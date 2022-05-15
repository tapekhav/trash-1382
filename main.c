#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#define REPLACE 1
#define INVERT 2
#define COPY 3
#define LINES 4

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

void help();

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
    printf("saved to %s\n", nameOut);
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
            int leftWidth,
            int leftHeight,
            int rightWidth,
            int rightHeight){

    leftHeight = (int)img->fileInfo.height - leftHeight - 1;
    rightHeight = (int)img->fileInfo.height - rightHeight - 1;

    if (leftHeight < rightHeight){
        int tmp = rightHeight;
        rightHeight = leftHeight;
        leftHeight = tmp;
    }

    if (rightWidth < leftWidth){
        int tmp = rightWidth;
        rightWidth = leftWidth;
        leftWidth = tmp;
    }

    if (rightWidth > img->fileInfo.width - 1) rightWidth = (int)img->fileInfo.width - 1;
    if (rightHeight < 0) rightHeight = 0;

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
            for (unsigned int w = leftWidth; w <= (rightWidth+leftWidth)/2; w++) {
                Rgb tmp;
                tmp = img->rgb[h][w];
                img->rgb[h][w] = img->rgb[h][rightWidth+leftWidth-w];
                img->rgb[h][rightWidth+leftWidth-w] = tmp;
            }
        }
    }

    saveImg(img, nameOut);
}

void copy(bmpFile* img,
            char* nameOut,
            int leftWidth,
            int leftHeight,
            int rightWidth,
            int rightHeight,
            int toLeftWidth,
            int toLeftHeight){

    printf("%s\n%d\t%d\n%d\t%d\n%d\t%d\n", nameOut, leftWidth, leftHeight, rightWidth, rightHeight, toLeftWidth, toLeftHeight);

    leftHeight = img->fileInfo.height - leftHeight - 1;
    rightHeight = img->fileInfo.height - rightHeight - 1;
    toLeftHeight = img->fileInfo.height - toLeftHeight - 1;

    if (leftHeight < rightHeight){
        unsigned int tmp = rightHeight;
        rightHeight = leftHeight;
        leftHeight = tmp;
    }
    if (rightWidth < leftWidth){
        unsigned int tmp = rightWidth;
        rightWidth = leftWidth;
        leftWidth = tmp;
    }

    if (rightWidth > img->fileInfo.width - 1) rightWidth = (int)img->fileInfo.width - 1;
    if (leftHeight > img->fileInfo.height - 1) leftHeight = img->fileInfo.height - 1;
    if (rightHeight < 0) rightHeight = 0;
    if (leftWidth < 0) leftWidth = 0;

    if((rightHeight > img->fileInfo.height -1 ) ||
    (leftWidth > img->fileInfo.width - 1)||
    (rightWidth < 0) ||
    (leftHeight < 0))
    {
        printf("Invalid value\n");
        saveImg(img, nameOut);
        return;
    }

    //copy to buf
    bmpFile buf;
    int heightBuf = leftHeight-rightHeight;
    int widthBuf = rightWidth-leftWidth;
    buf.fileInfo.height = heightBuf;
    buf.fileInfo.width = widthBuf;

    buf.rgb = malloc(heightBuf*sizeof(Rgb*));
    for(unsigned int h = 0; h <= heightBuf; h++){
        buf.rgb[h] = malloc(widthBuf * sizeof(Rgb));
        for (int w = 0; w <= widthBuf; w++){
            buf.rgb[h][w] = img->rgb[rightHeight+h][leftWidth+w];
        }
    }

    //insert from buf
    for(int h = heightBuf; h >= 0; h--){
        for (int w = 0; w <= widthBuf; w++){
            if (0 <= (toLeftHeight-(heightBuf-h)) && toLeftWidth+w <= img->fileInfo.width-1)
                img->rgb[toLeftHeight-(heightBuf-h)][toLeftWidth+w] = buf.rgb[h][w];
            else
                continue;
        }
    }

    for(unsigned int h = 0; h <= heightBuf; h++){
        free(buf.rgb[h]);
    }
    saveImg(img, nameOut);
}

int correct(int x){
    if (x%2 == 0) return 1;
    return 0;
}

void lines(bmpFile* img,
               char* nameOut,
               int n,//h
               int m,//w
               int t,
               char r,
               char g,
               char b){

    int H = (int)img->fileInfo.height;
    int W = (int)img->fileInfo.width;

    for(int h = 1; h < n; h++){
        for (int h1 = ((h*H)/n)-(t/2-correct(t)); h1 <= ((h*H)/n)+t/2; h1++){
            for(int w1 = 0; w1 <= W; w1++ ){
                img->rgb[h1][w1].r = r;
                img->rgb[h1][w1].g = g;
                img->rgb[h1][w1].b = b;
            }
        }
    }

    for(int w = 1; w < m; w++){
        for (int w1 = ((w*W)/m)-(t/2-correct(t)); w1 <= ((w*W)/m)+t/2; w1++){
            for(int h1 = 0; h1 < H; h1++ ){
                img->rgb[h1][w1].r = r;
                img->rgb[h1][w1].g = g;
                img->rgb[h1][w1].b = b;
            }
        }
    }
    saveImg(img, nameOut);
}

int correctFile(bmpFile* img, char* name){
    unsigned long len = strlen(name);
    if(name[len-4] != '.' || name[len-3] != 'b' || name[len-2] != 'm' || name[len-1] != 'p'){
        printf("Incorrect file name\n");
        return 1;
    }
    FILE* file = fopen(name, "rb");
    if(!file){
        printf("The file is not in the directory\n");
        return 1;
    }
    *img = readImg(name);
    if(img->fileInfo.compression != 0){
        printf("File is compressed\n");
        return 1;
    }
    if(img->fileInfo.bitsPerPixel != 24){
        printf("File color depth is not 24 bits per color\n");
        return 1;
    }
    if(img->fileInfo.headerSize != 40){
        printf("This version of the BMP file is not supported\n");
        return 1;
    }
    if(img->fileInfo.colorsInColorTable != 0 || img->fileInfo.importantColorCount != 0){
        printf("File must not use color table\n");
        return 1;
    }
    return 0;
}

void printImageInfo(bmpFile image){
    printf("Signature:\t%x (%hu)\n", image.fileHeader.signature, image.fileHeader.signature);
    printf("filesize:\t%x (%u)\n", image.fileHeader.filesize, image.fileHeader.filesize);
    printf("reserved1:\t%x (%hu)\n", image.fileHeader.reserved1, image.fileHeader.reserved1);
    printf("reserved2:\t%x (%hu)\n", image.fileHeader.reserved2, image.fileHeader.reserved2);
    printf("pixelArrOffset:\t%x (%u)\n", image.fileHeader.pixelArrOffset, image.fileHeader.pixelArrOffset);
    printf("headerSize:\t%x (%u)\n", image.fileInfo.headerSize, image.fileInfo.headerSize);
    printf("width:     \t%x (%u)\n", image.fileInfo.width, image.fileInfo.width);
    printf("height:    \t%x (%u)\n", image.fileInfo.height, image.fileInfo.height);
    printf("planes:    \t%x (%hu)\n", image.fileInfo.planes, image.fileInfo.planes);
    printf("bitsPerPixel:\t%x (%hu)\n", image.fileInfo.bitsPerPixel, image.fileInfo.bitsPerPixel);
    printf("compression:\t%x (%u)\n", image.fileInfo.compression, image.fileInfo.compression);
    printf("imageSize:\t%x (%u)\n", image.fileInfo.imageSize, image.fileInfo.imageSize);
    printf("xPixelsPerMeter:\t%x (%u)\n", image.fileInfo.xPixelsPerMeter, image.fileInfo.xPixelsPerMeter);
    printf("yPixelsPerMeter:\t%x (%u)\n", image.fileInfo.yPixelsPerMeter, image.fileInfo.yPixelsPerMeter);
    printf("colorsInColorTable:\t%x (%u)\n", image.fileInfo.colorsInColorTable, image.fileInfo.colorsInColorTable);
    printf("importantColorCount:\t%x (%u)\n",image.fileInfo.importantColorCount, image.fileInfo.importantColorCount);
}

void help(){
    char text[] = "\n\t\t\tWelcome to BMP Photo editor\n\n"
                  "\t--Program supports CLI and only works with version 3 BMP files\n"
                  "\t--BMP files with color table are not supported\n"
                  "\t--The program only supports files with a depth of 24 pixels per bit\n"
                  "\t--File must not be compressed\n\n\n"

                  "There is 4 functions:\n\n\n"

                  "\t1 - Replace Color (-r/--replace)\n"
                  "\tReplace one color to another\n\n"
                  "\tRequired arguments -r/--replace <Name File Input.bmp> -1/--firstColor <red,green,blue> -2/--secondColor <red,green,blue> <Name File Output.bmp>\n"
                  "\tExample: -r simpsonsvr.bmp -1 0,0,0, -2 125,0,255 out.bmp\n\n\n"

                  "\t2 - Invert Area Image (-i/--invert)\n"
                  "\tInverts vertically or horizontally the selected area\n\n"
                  "\tRequired arguments -i/--invert <Name File Input.bmp> -o/--option <h/v> -s/--start <Start Width Coordinates>,<Start Height Coordinates> -e/--end <End Width Coordinates>,<End Height Coordinates> <Name File Output.bmp>\n"
                  "\tExample: -i simpsonsvr.bmp -o v -s 100,50 -e 550,350 out.bmp\n\n\n"

                  "\t3 - Copy Area Image (-c/--copy)\n"
                  "\tСopy selected area to destination\n\n"
                  "\tRequired arguments -c/--copy <Name File Out.bmp> -s/--start <Start Width Coordinates>,<Start Height Coordinates> -e/--end <End Width Coordinates>,<End Height Coordinates> -d/--destination <Destination Width>,<Destination Height> <Name File Output.bmp>\n"
                  "\tExample: -c simpsonsvr.bmp -s 200,50 -e 450,150 -d 350,200 out.bmp\n\n\n"

                  "\t4 - Draw Line Collage (-l/--lines)\n"
                  "\tDraws lines vertically and horizontally creating a collage\n\n"
                  "\tRequired arguments -l/--lines <Name File Input> -y/--yLines <Numbers Lines by Height> -x/--xLines <Numbers Lines by Width> -t/--thickness <Thickness> -1/--firstColor<red,green,blue> <Name File Output.bmp>\n"
                  "\tExample: -l simpsonsvr.bmp -x 5 -y 3 -t 5 -1 128,0,128 out.bmp\n\n\n";
    puts(text);
}

void helpV2(){
    char text[] = "help(((\n";
    puts(text);
}


int main(int argc, char *argv[]){

    char *opts = "r:i:c:l:f:1:2:s:e:o:d:y:x:t:hp";
    struct option longOpts[]={
            {"replace", required_argument, NULL, 'r'},
            {"invert", required_argument, NULL, 'i'},
            {"copy", required_argument, NULL, 'c'},
            {"lines", required_argument, NULL, 'l'},
            {"file", required_argument, NULL, 'f'},
            {"firstColor", required_argument, NULL, '1'},
            {"secondColor", required_argument, NULL, '2'},
            {"start", required_argument, NULL,'s'},
            {"end", required_argument, NULL, 'e'},
            {"option", required_argument, NULL, 'o'},
            {"destination", required_argument, NULL,'d'},
            {"yLines", required_argument, NULL,'y'},
            {"xLines", required_argument, NULL,'x'},
            {"thickness", required_argument, NULL,'t'},
            {"help", no_argument, NULL, 'h'},
            {"printInfo", no_argument, NULL, 'p'},
            {NULL, 0, NULL, 0}
    };

    int opt;
    int longOpt;
    opt = getopt_long(argc, argv, opts, longOpts, &longOpt);


    if (argc < 2){
        printf("Error\nFor help use -h/--help\n");
        return 0;
    }

    char inputFile[256];
    char outputFile[255];
    strcpy(outputFile, argv[argc-1]);
    bmpFile img;

    int way = 0;
    int x1, y1, x2, y2, dx, dy, r1, g1, b1, r2, g2, b2, xLines, yLines, thickness = 0;
    int startCood, endCoord, distCoord, firstClr, secondClr, thick, xCnt, yCnt = 0;

    char option = 'n';
    int countRead;

    while (opt != -1){
        switch (opt) {
            case 'r':{
                countRead = sscanf(optarg, "%s", inputFile);
                if (countRead < 1){
                    printf("File name was not entered\n");
                    return 1;
                }
                if (correctFile(&img, inputFile) != 0){
                    printf("Invalid file\n");
                    return 1;
                }
                way = REPLACE;
                break;
            }
            case 'i':{
                countRead = sscanf(optarg, "%s", inputFile);
                if (correctFile(&img, inputFile) != 0){
                    printf("Invalid file\n");
                    return 1;
                }
                if (countRead < 1){
                    printf("Too few arguments\n");
                    return 1;
                }
                way = INVERT;
                break;
            }
            case 'c':{
                countRead = sscanf(optarg, "%s", inputFile);
                if (correctFile(&img, inputFile) != 0){
                    printf("Invalid file\n");
                    return 1;
                }
                if (countRead < 1){
                    printf("Too few arguments\n");
                    return 1;
                }
                way = COPY;
                break;
            }
            case 'l':{
                countRead = sscanf(optarg, "%s", inputFile);
                if (correctFile(&img, inputFile) != 0){
                    printf("Invalid file\n");
                    return 1;
                }
                if (countRead < 1){
                    printf("Too few arguments\n");
                    return 1;
                }
                way = LINES;
                break;
            }
            case 'f':{
                countRead = sscanf(optarg, "%s", outputFile);
                if (countRead < 1){
                    printf("Too few arguments for file name\n");
                    return 1;
                }
                if (strcmp(outputFile, "no") == 0){
                    strcpy(outputFile, inputFile);
                    break;
                }
                int len = strlen(outputFile);
                if (len < 5 || outputFile[len-4] != '.' || outputFile[len-3] != 'b' || outputFile[len-2] != 'm' || outputFile[len-1] != 'p'){
                    printf("Incorrect file name\n");
                    return 1;
                }
                break;
            }
            case 's':{
                countRead = sscanf(optarg, "%d,%d", &x1, &y1);
                if (countRead < 2){
                    printf("Too few arguments for coordinates\n");
                    return 1;
                }
                startCood = 1;
                break;
            }
            case 'e':{
                countRead = sscanf(optarg, "%d,%d", &x2,&y2);
                if (countRead < 2){
                    printf("Too few arguments for coordinates\n");
                    return 1;
                }
                endCoord = 1;
                break;
            }
            case 'o':{
                countRead = sscanf(optarg, "%c", &option);
                if (countRead < 1){
                    printf("Too few arguments for option\n");
                    return 1;
                }
                if (option == 'n'){
                    printf("Invalid value option\n");
                    return 1;
                }
                break;
            }
            case 'd':{
                countRead = sscanf(optarg, "%d,%d", &dx, &dy);
                if (countRead < 2){
                    printf("Too few arguments for coordinates\n");
                    return 1;
                }
                distCoord = 1;
                break;
            }
            case '1':{
                countRead = sscanf(optarg, "%d,%d,%d", &r1, &g1, &b1);
                if (countRead < 3){
                    printf("Too few arguments for color\n");
                }
                firstClr = 1;
                break;
            }
            case '2':{
                countRead = sscanf(optarg, "%d,%d,%d", &r2, &g2, &b2);
                if (countRead < 3){
                    printf("Too few arguments for color\n");
                    return 1;
                }
                secondClr = 1;
                break;
            }
            case 'y':{
                countRead = sscanf(optarg, "%d", &yLines);
                if (countRead < 1){
                    printf("Too few arguments for number lines by Y\n");
                    return 1;
                }
                yCnt = 1;
                break;
            }
            case 'x':{
                countRead = sscanf(optarg, "%d", &xLines);
                if (countRead < 1){
                    printf("Too few arguments for number lines by X\n");
                    return 1;
                }
                xCnt = 1;
                break;
            }
            case 't':{
                countRead = sscanf(optarg, "%d", &thickness);
                if (countRead < 1){
                    printf("Too few arguments fot thickness\n");
                    return 1;
                }
                thick = 1;
                break;
            }
            case 'h':{
                help();
                return 0;
            }
            case 'p':{
                printImageInfo(img);
                return 0;
            }
            default:{
                printf("Unknown key or too low argument %c\n", opt);
                return 1;
            }
        }
        opt = getopt_long(argc, argv, opts, longOpts, &longOpt);
    }

    switch (way) {
        case REPLACE:{
            if (firstClr == 1 && secondClr == 1)
                replaceColor(&img, outputFile, r1, g1, b1, r2, g2, b2);
            else
                printf("Some key(s) was not used\n");
            break;
        }
        case COPY:{
            if (startCood == 1 && endCoord == 1 && distCoord == 1)
                copy(&img, outputFile, x1, y1, x2, y2, dx, dy);
            else
                printf("Some key(s) was not used\n");
            break;
        }
        case INVERT:{
            if (option != 'n' && startCood == 1 && endCoord == 1)
                invert(&img, outputFile, option,x1, y1, x2, y2);
            else
                printf("Some key(s) was not used\n");
            break;
        }
        case LINES:{
            if (secondClr == 1 && firstClr == 0){
                r1 = r2;
                g1 = g2;
                b1 = g2;
            }
            if (xCnt == 1 && yCnt == 1 && thick == 1 && firstClr == 1)
            lines(&img, outputFile, yLines, xLines, thickness, (char)r1, (char)g1, (char)b1);
            break;
        }
        default:{
            printf("You did not call any function\n");
        }
    }

    return 0;
}