#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <getopt.h>
#include <string.h>

#pragma pack (push, 1)
typedef struct
{
    unsigned short signature;
    unsigned int filesize;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int pixelArrOffset;
} BitmapFileHeader;

typedef struct
{
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
} RGB;

typedef struct
{
    BitmapFileHeader header;
    BitmapInfoHeader info;
    RGB** pixels;
}BMP;

#pragma pack(pop)

struct Configs{
    int final;
    int reverse; // 0 - false
    int verbose; // 0 - false
};

int IsImageOk(BMP image){
    if(image.header.signature != 0x4d42){
        puts("The file does not conform to the BMP format. Please, change your file.");
        return 0;
    }

    if(image.info.compression != 0){
        puts("The file is compressed. Please, change your file.");
        return 0;
    }

    if(image.info.bitsPerPixel != 24){
        puts("The color depth of the file is not 24 pixels per bit. Please, change your file.");
        return 0;
    }

    if(image.info.colorsInColorTable != 0){
        puts("This file uses a color table.");
        return 0;
    }

    return 1;
}

void printHelp(){
    printf("getopt ex");
    printf("-f <value> - final value\n");
    printf("-r - reverse\n");
    printf("-v --verbose - verbose\n");
    printf("-h -? - help\n");
}

void readImage(BMP *image, char* path){
    FILE *f = fopen(path, "rb");
    fread(&image->header,1,sizeof(BitmapFileHeader),f);
    fread(&image->info,1,sizeof(BitmapInfoHeader),f);

    unsigned int H = image->info.height;
    unsigned int W = image->info.width;
    unsigned int offset = (W*3)%4;


    image->pixels = malloc(H*sizeof(RGB*));
    for(int i=0; i<H; i++){
        image->pixels[i] = malloc(W * sizeof(RGB) + offset);
        fread(image->pixels[i], 1,W * sizeof(RGB) + offset,f);
    }

    fclose(f);
}

void writeImage(BMP *image, char* path){
    unsigned int H = image->info.height;
    unsigned int W = image->info.width;
    unsigned int offset = (W*3)%4;

    FILE *fout = fopen(path, "wb");


    fwrite(&image->header, 1, sizeof(BitmapFileHeader),fout);
    fwrite(&image->info, 1, sizeof(BitmapInfoHeader),fout);

    unsigned int w = W * sizeof(RGB) + offset;
    for(int i=0; i<H; i++){
        fwrite(image->pixels[i], 1, w, fout);
    }
    fclose(fout);

}

void printImageInfo(BMP image){
    printf("Signature:\t%x (%hu)\n", image.header.signature, image.header.signature);
    printf("filesize:\t%x (%u)\n", image.header.filesize, image.header.filesize);
    printf("reserved1:\t%x (%hu)\n", image.header.reserved1, image.header.reserved1);
    printf("reserved2:\t%x (%hu)\n", image.header.reserved2, image.header.reserved2);
    printf("pixelArrOffset:\t%x (%u)\n", image.header.pixelArrOffset, image.header.pixelArrOffset);
    printf("headerSize:\t%x (%u)\n", image.info.headerSize, image.info.headerSize);
    printf("width:     \t%x (%u)\n", image.info.width, image.info.width);
    printf("height:    \t%x (%u)\n", image.info.height, image.info.height);
    printf("planes:    \t%x (%hu)\n", image.info.planes, image.info.planes);
    printf("bitsPerPixel:\t%x (%hu)\n", image.info.bitsPerPixel, image.info.bitsPerPixel);
    printf("compression:\t%x (%u)\n", image.info.compression, image.info.compression);
    printf("imageSize:\t%x (%u)\n", image.info.imageSize, image.info.imageSize);
    printf("xPixelsPerMeter:\t%x (%u)\n", image.info.xPixelsPerMeter, image.info.xPixelsPerMeter);
    printf("yPixelsPerMeter:\t%x (%u)\n", image.info.yPixelsPerMeter, image.info.yPixelsPerMeter);
    printf("colorsInColorTable:\t%x (%u)\n", image.info.colorsInColorTable, image.info.colorsInColorTable);
    printf("importantColorCount:\t%x (%u)\n",image.info.importantColorCount, image.info.importantColorCount);
}

void changeColor(BMP* image, unsigned char r1, unsigned char r2, unsigned char g1, unsigned char g2,
                 unsigned char b1, unsigned char b2){
    int checkPresenceColor = 0;
    if(r1 < 0 || r2 < 0 || g1 < 0 || g2 < 0|| b1 < 0 || b2 < 0 || r1 > 255 || r2 > 255 || g1 > 255 ||
            g2 > 255 || b1 > 255 || b2 > 255){
        puts("One of the component is incorrectly set.");
        return;
    }

    for(int i = 0; i < image->info.height; ++i){
        for(int j = 0; j < image->info.width; ++j){
            if(image->pixels[i][j].r == r1 && image->pixels[i][j].g == g1 && image->pixels[i][j].b == b1){
                checkPresenceColor = 1;
                image->pixels[i][j].r = r2;
                image->pixels[i][j].g = g2;
                image->pixels[i][j].b = b2;
            }
        }
    }


    if(checkPresenceColor == 0) puts("There is no this color.");

}

void swapPixels(RGB *pix1, RGB *pix2){
    RGB temp = *pix1;
    *pix1 = *pix2;
    *pix2 = temp;
}


void reflectArea(BMP* image, char* axis, unsigned int x_left, unsigned int y_top,
                 unsigned int x_right, unsigned int y_bottom){

    if(x_left < 0 || x_left > x_right || x_right > image->info.width
    || y_bottom > image->info.height || y_top < 0 || y_top > y_bottom){
        puts("Wrong coordinates.");
        return;
    }


    //printf("y0 - %d\ny_end - %d\n", y_top, y_bottom);

    unsigned int width_of_area = x_right - x_left;
    unsigned int height_of_area = y_bottom - y_top;

    y_bottom = image->info.height - y_bottom;
    y_top = image->info.height - y_top;
    //printf("widthOfArea - %d\n heightOfArea - %d\n", width_of_area, height_of_area);

    if(!strcmp(axis, "horizontal")){
        for (int y = 0; y < height_of_area; ++y) {
            for (int x = 0; x < width_of_area / 2; ++x) {
                swapPixels(&image->pixels[y_top - y][x_left + x], &image->pixels[y_top - y][x_right - x]);
            }
        }
    }

    if(!strcmp(axis, "vertical")) {
        for (int y = 0; y < height_of_area / 2; ++y) {
            for (int x = 0; x < width_of_area; ++x) {
                swapPixels(&image->pixels[y_bottom + y][x_left + x], &image->pixels[y_top - y][x_left + x]);
            }
        }
    }

    if(strcmp(axis, "vertical") && strcmp(axis, "horizontal")){
        puts("Wrong axis selected.");
    }
}

void copyImage(BMP* image, unsigned int x_src_left, unsigned int y_src_top,
               unsigned int x_src_right, unsigned int y_src_bottom,
               unsigned int x_dest_left, unsigned int y_dest_top){

    unsigned int height = image->info.height;
    unsigned int width = image->info.width;


    if(x_src_left < 0 || y_src_top < 0
            || x_src_right > width || y_src_bottom > height
            || x_src_left > x_src_right || y_src_top > y_src_bottom){
        puts("Wrong source area coordinates.");
        return;
    }

    if(x_dest_left < 0 || y_dest_top < 0){
        puts("Wrong destination area coordinates.");
        return;
    }


    y_dest_top = height - y_dest_top;
    y_src_top = height - y_src_top;
    y_src_bottom = height - y_src_bottom;

    //printf("y_dest_top - %d\ny_src_top - %d\ny_src_bottom - %d\n", y_dest_top, y_src_top, y_src_bottom);


    BMP newImage;

    newImage.info.height = y_src_top - y_src_bottom;
    newImage.info.width = x_src_right - x_src_left;
    //printf("newImage.info.height - %d\n", newImage.info.height);

    unsigned int y_dest_bottom = y_dest_top - newImage.info.height;
    unsigned int x_dest_right = x_dest_left + newImage.info.width;

    if(y_dest_bottom > height){
        puts("Wrong destination area coordinates.");
        printf("%d %d %d %d\n", y_dest_bottom, y_dest_top, newImage.info.height, image->info.height);
        return;
    }

    if(x_dest_right > width){
        puts("Wrong destination area coordinates.");
        puts("-");
        return;
    }


    newImage.pixels = malloc(newImage.info.height * sizeof(RGB*));

    for(int i = 0; i < newImage.info.height; ++i){
        newImage.pixels[i] = malloc(newImage.info.width * sizeof(RGB));
    }

    unsigned int x;
    unsigned int y = 0;

    for(int i = y_src_bottom; i < y_src_top; ++i){
        x = 0;
        for(int j = x_src_left; j < x_src_right; ++j){
            newImage.pixels[y][x] = image->pixels[i][j];
            ++x;
        }
        ++y;
    }

    y = 0;
    x = 0;


    for(int i = y_dest_bottom; i < y_dest_top; ++i){
        for(int j = x_dest_left; j < x_dest_right; ++j){
            image->pixels[i][j] = newImage.pixels[y][x];
            ++x;
        }
        ++y;
        x = 0;
    }

    for(int i = 0; i < newImage.info.height; ++i){
        free(newImage.pixels[i]);
    }
    free(newImage.pixels);
}

void rgbFilter(BMP* image, unsigned char value, char* component){
    if(value < 0 || value > 255){
        puts("Invalid component value.");
        return;
    }

    if(strcmp(component, "red") && strcmp(component, "green") && strcmp(component, "blue")){
        printf("Wrong component name.");
        return;
    }

    for(int i = 0; i < image->info.height; ++i){
        for(int j = 0; j < image->info.width; ++j){
            if(!strcmp(component, "red")){
                image->pixels[i][j].r = value;
            }

            if(!strcmp(component, "green")){
                image->pixels[i][j].g = value;
            }

            if(!strcmp(component, "blue")){
                image->pixels[i][j].b = value;
            }
        }
    }
}

//TODO getopt

int main(int argc, char* argv[]){
    BMP image;
    readImage(&image, "simpsonsvr.bmp");
    //printImageInfo(image);
    //rgbFilter(&image, 255, "red");
    //printf("%d", image.info.colorsInColorTable);
    //changeColor(&image, 255, 0, 255, 0, 255, 0);
    //copyImage(&image, 100,  100, 200, 200, 200, 200);
    //reflectArea(&image, "vertical", 215, 23, 576, 361);
    writeImage(&image, "out.bmp");

    /*struct Configs config = {0, 0, 0};
    char *opts = "f:rvh?";
    struct option longOpts[]={
            {"verbose", no_argument, NULL, 'v'},
            {"longlong", no_argument, NULL, 0},
            {"long", no_argument, NULL, 0},
            { NULL, 0, NULL, 0}
    };
    int opt;
    int longIndex;
    opt = getopt_long(argc, argv, opts, longOpts, &longIndex);
    while(opt!=-1){
        switch(opt){
            case 'f':
//				printf("get f with value: %d\n", atoi(optarg));
                config.final = atoi(optarg);
                break;
            case 'r':
                config.reverse = 1;
                //printf("get r\n");
                break;
            case 'v':
                //printf("get v\n");
                config.verbose = 1;
                break;
            case 'h':
            case '?':
                printHelp();
                return 0;
            case 0:
                printf("->%s\n",longOpts[longIndex].name);
        }
        opt = getopt_long(argc, argv, opts, longOpts, &longIndex);
    }
    argc -= optind;
    argv += optind;
    printf("final = %d\n", config.final);
    printf("verbose = %d\n", config.verbose);
    printf("reverse = %d\n", config.reverse);
    for(int i=0; i<argc; i++)
        printf(">>%s\n", argv[i]);
    return 0; */

    return 0;
}