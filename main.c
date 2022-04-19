#include <stdio.h>
#include <stdlib.h>

#pragma pack (push, 1)
typedef struct{
    unsigned short signature;
    unsigned int filesize;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int pixelArrOffset;
} BitmapFileHeader;

typedef struct{
    unsigned int headerSize;
    unsigned int width;
    unsigned int height;
    unsigned short planes;
    unsigned short bitsPerPixel;
    unsigned int compression;
    unsigned int imageSize;
    unsigned int xPixelsPerMeter;
    unsigned int yPixelsPerMeter;
    unsigned int colorsInColorTable;
    unsigned int importantColorCount;
} BitmapInfoHeader;

typedef struct
{
    unsigned char b;
    unsigned char g;
    unsigned char r;
} Rgb;

typedef struct{
    BitmapFileHeader fileHeader;
    BitmapInfoHeader fileInfo;
    Rgb** rgb;
}bmpFile;
#pragma pack(pop)

bmpFile readImg(char* name){
    FILE *f = fopen(name, "rb");
    bmpFile img;

    fread(&img.fileHeader ,1,sizeof(BitmapFileHeader),f);
    fread(&img.fileInfo,1,sizeof(BitmapInfoHeader),f);

    unsigned int H = img.fileInfo.height;
    unsigned int W = img.fileInfo.width;

    img.rgb = malloc(H*sizeof(Rgb*));
    for(int i=0; i<H; i++){
        img.rgb[i] = malloc(W * sizeof(Rgb) + (W*3)%4);
        fread(img.rgb[i],1,W * sizeof(Rgb) + (W*3)%4,f);
    }
    return img;
}

void saveImg(bmpFile* img, char* nameOut){
    FILE *f = fopen(nameOut, "wb");
    fwrite(&img->fileHeader, 1, sizeof(BitmapFileHeader),f);
    fwrite(&img->fileInfo, 1, sizeof(BitmapInfoHeader),f);

    unsigned int W = (img->fileInfo.width)*sizeof(Rgb)+ (img->fileInfo.width*3)%4;

    for(int i=0; i<img->fileInfo.height; i++){
        fwrite(img->rgb[i],1, W ,f);
    }
    fclose(f);
}

void replaceColor(bmpFile* img,
                  char* nameOut,
                  unsigned char r1,
                  unsigned char g1,
                  unsigned char b1,
                  unsigned char r2,
                  unsigned char g2,
                  unsigned char b2){

    for (int h = 0; h < img->fileInfo.height ; h++){
        for (int w = 0; w < img->fileInfo.width; w++){
            if ((img->rgb[h][w].r == r1) && (img->rgb[h][w].g == g1) && (img->rgb[h][w].b == b1)){
                img->rgb[h][w].r = r2;
                img->rgb[h][w].g = g2;
                img->rgb[h][w].b = b2;
            }
        }
    }

    saveImg(img, nameOut);
}

void invert(bmpFile* img,
            char* nameOut,
            char var,
            unsigned int leftHeight,
            unsigned int leftWidth,
            unsigned int rightHeight,
            unsigned int rightWidth){


    if (!(leftHeight <= img->fileInfo.height && leftHeight >= 0 && rightHeight >= 0 && rightWidth <= img->fileInfo.width)){
        printf("ERROR\ninvalid size\n");
    } else {
        if (var == 'v') {
            for (unsigned int h = rightHeight; h <= (leftHeight+rightHeight)/2; h++){
                for (unsigned int w = leftWidth; w <= rightWidth; w++) {
                    Rgb tmp;
                    tmp = img->rgb[h][w];
                    img->rgb[h][w] = img->rgb[leftHeight+rightHeight-h][w];
                    img->rgb[leftHeight+rightHeight-h][w] = tmp;

                }
            }
        } else if(var == 'h'){
            for (unsigned int h = rightHeight; h <= leftHeight; h++) {
                printf("-");
                for (unsigned int w = leftWidth; w <= (rightWidth+leftWidth)/2; w++) {
                    printf("+");
                    Rgb tmp;
                    tmp = img->rgb[h][w];
                    img->rgb[h][w] = img->rgb[h][rightWidth+leftWidth-w];
                    img->rgb[h][rightWidth+leftWidth-w] = tmp;
                }
            }
        }
        saveImg(img, nameOut);
    }
}

void copy(bmpFile* img,
            char* nameOut,
            unsigned int leftHeight,
            unsigned int leftWidth,
            unsigned int rightHeight,
            unsigned int rightWidth,
            unsigned int toLeftHeight,
            unsigned int toLeftWidth){

    //leftHeight = img->fileInfo.height - leftHeight;
    //rightHeight = img->fileInfo.height - rightHeight;
    //toLeftHeight = img->fileInfo.height - toLeftHeight;

    //copy to buf
    bmpFile buf;
    unsigned int heightBuf = leftHeight-rightHeight;
    unsigned int widthBuf = rightWidth-leftWidth;
    buf.fileInfo.height = heightBuf;
    buf.fileInfo.width = widthBuf;

    buf.rgb = malloc(heightBuf*sizeof(Rgb*));
    for(unsigned int h = 0; h < heightBuf; h++){
        printf("%d\n", h);
        buf.rgb[h] = malloc(widthBuf * sizeof(Rgb));
        for (int w = 0; w < widthBuf; w++){
            buf.rgb[h][w].r = img->rgb[rightHeight+h][leftWidth+w].r;
            buf.rgb[h][w].g = img->rgb[rightHeight+h][leftWidth+w].g;
            buf.rgb[h][w].b = img->rgb[rightHeight+h][leftWidth+w].b;
        }
        //fread(buf.rgb[i],1,W * sizeof(Rgb) + (W*3)%4,f);
    }

    //insert from buf
    for(unsigned int h=heightBuf; h > 0; h--){
        for (int w = 0; w < widthBuf; w++){
            img->rgb[toLeftHeight-h][toLeftWidth+w].r = buf.rgb[h][w].r;
            img->rgb[toLeftHeight-h][toLeftWidth+w].g = buf.rgb[h][w].g;
            img->rgb[toLeftHeight-h][toLeftWidth+w].b = buf.rgb[h][w].b;
        }
        //fread(buf.rgb[i],1,W * sizeof(Rgb) + (W*3)%4,f);
    }

    //TODO free buf

    saveImg(img, nameOut);
}


int main(){

    bmpFile img = readImg("simpsonsvr.bmp");
    saveImg(&img, "out.bmp");

    replaceColor(&img, "out.bmp", 255, 255, 255, 0, 124, 125);

    invert(&img, "out.bmp", 'v', 350, 300, 191, 513);
    //copy(&img, "out.bmp", 0, 0, 100, 200, 50, 50);

    return 0;
}