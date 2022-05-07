#include <stdio.h>
#include <stdlib.h>
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


void printHelp(){
    puts("This program supports CLI and only works with version 3 BMP files.");
    puts("BMP files with color table are not supported.");
    puts("The program only supports files with a depth of 24 pixels per bit.");
    puts("The photo must not be compressed.");
    puts("In the copy area and reflect area functions, the top left pixel is considered the origin (0, 0).");
    puts("Format of input: ./bmp [name of input file] [name of key] [argument 1],[argument 2],...,[argument N]"
         " [name of output file]");
    puts("All keys:");
    puts("\t-h(--help):\n\t\tShows instructions for the program. "
         "Takes no arguments. Written in place of the file name.");
    puts("\t\tExample: ./bmp --help");
    puts("\t-i(--info):\n\t\t Takes no arguments. You do not need to write the name of the output file.");
    puts("\t\tExample: ./bmp simpsonsvr.bmp -i");
    puts("\t\t-i(--info):\n\t\t Information of input file. Takes no arguments. "
         "You do not need to write the name of the output file.");
    puts("\t-r(--reflectArea):");
    puts("\t\tReflects a photo along a certain axis at the specified coordinates.");
    puts("\t\tArguments are entered in this way:");
    puts("\t\t-r [left x coordinate],[top y coordinate],[right x coordinate],[bottom y coordinate],[axis]");
    puts("\t\tExample: ./bmp simpsonsvr.bmp -r 100,100,400,400,vertical out.bmp");
    puts("\t-c(--copyArea):");
    puts("\t\tCopy area in picture and inserts it in certain place.");
    puts("\t\tArguments are entered in this way:");
    puts("\t\t-c [x source left],[y source top],[x source right],[y source bottom],"
         "[x destination left],[y destination top]");
    puts("\t\tExample: ./bmp simpsonsvr.bmp -c 100,100,200,200,200,200 out.bmp");
    puts("\t-С(--changeColor):");
    puts("\t\tChange color based on RGB components.");
    puts("\t\tArguments are entered in this way:");
    puts("\t\t-C [value of red component 1],[value of green component 1],[value of blue component 1],\n"
         "\t\t[value of red component 2],[value of green component 2],[value of blue component 2]");
    puts("\t\tExample: ./bmp simpsonsvr.bmp -C 255,255,255,0,0,0 out.bmp");
    puts("\t-f(--filter):");
    puts("\t\tChanges the value of one of the components.");
    puts("\t\tArguments are entered in this way:");
    puts("\t\t-f [value of the component],[name of the component]");
    puts("\t\tExample: ./bmp simpsonsvr.bmp -f 255,red out.bmp");
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

int IsImageOk(BMP image){
    if(image.info.headerSize != 40){
        puts("This version of the BMP file is not supported. Please, change your file.");
        return 0;
    }

    if(image.info.planes != 1){
        puts("Unsupported quantity of planes. Please, change your file.");
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

    if(image.info.colorsInColorTable != 0 || image.info.importantColorCount != 0){
        puts("This file uses a color table. Please, change your file.");
        return 0;
    }

    return 1;
}

int readImage(BMP *image, char* path){
    if(path[strlen(path) - 1] != 'p' || path[strlen(path) - 2] != 'm'
       || path[strlen(path) - 3] != 'b' || path[strlen(path) - 4] != '.'){
        puts("Wrong format of input file.");
        return 0;
    }

    FILE *f = fopen(path, "rb");

    fread(&image->header,1,sizeof(BitmapFileHeader),f);

    if(image->header.signature != 0x4d42){
        puts("The file does not conform to the BMP format. Please, change your file.");
        return 0;
    }

    fread(&image->info,1,sizeof(BitmapInfoHeader),f);

    if(!IsImageOk(*image)){
        return 0;
    }

    unsigned int H = image->info.height;
    unsigned int W = image->info.width;
    unsigned int offset = (W*3)%4;


    image->pixels = malloc(H * sizeof(RGB*));
    if(!image->pixels){
        puts("Memory is not available.");
        return 0;
    }

    for(int i=0; i<H; i++){
        image->pixels[i] = malloc(W * sizeof(RGB) + offset);
        if(!image->pixels[i]){
            puts("Memory is not available.");
            return 0;
        }

        fread(image->pixels[i], 1,W * sizeof(RGB) + offset,f);
    }

    fclose(f);

    return 1;
}

void freeMem(BMP* image){
    for(unsigned int i = 0; i < image->info.height; ++i){
        free(image->pixels[i]);
    }
    free(image->pixels);
}

int writeImage(BMP *image, char* path){
    unsigned int H = image->info.height;
    unsigned int W = image->info.width;
    unsigned int offset = (W*3)%4;

    if(path[strlen(path) - 1] != 'p' || path[strlen(path) - 2] != 'm'
    || path[strlen(path) - 3] != 'b' || path[strlen(path) - 4] != '.'){
        puts("Wrong format of output file.");
        return 0;
    }
    FILE *fout = fopen(path, "wb");


    fwrite(&image->header, 1, sizeof(BitmapFileHeader),fout);
    fwrite(&image->info, 1, sizeof(BitmapInfoHeader),fout);

    unsigned int w = W * sizeof(RGB) + offset;
    for(int i=0; i<H; i++){
        fwrite(image->pixels[i], 1, w, fout);
    }
    fclose(fout);

    freeMem(image);

    return 1;
}

void changeColor(BMP* image, int r1, int r2, int g1, int g2, int b1, int b2){
    int checkPresenceColor = 0;
    if(r1 < 0 || r2 < 0 || g1 < 0 || g2 < 0 || b1 < 0 || b2 < 0 || r1 > 255 || r2 > 255 || g1 > 255 ||
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


void reflectArea(BMP* image, char* axis, int x_left, int y_top,
                 int x_right, int y_bottom){

    if(x_left < 0 || x_left > x_right || x_right > image->info.width
    || y_bottom > image->info.height || y_top < 0 || y_top > y_bottom){
        puts("Wrong coordinates.");
        return;
    }

    unsigned int width_of_area = x_right - x_left;
    unsigned int height_of_area = y_bottom - y_top;

    y_bottom = (int)image->info.height - y_bottom - 1;
    y_top = (int)image->info.height - y_top;

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

    if(strcmp(axis, "vertical") != 0 && strcmp(axis, "horizontal") != 0){
        puts("Wrong axis selected.");
    }
}

void copyImage(BMP* image, int x_src_left, int y_src_top,
               int x_src_right, int y_src_bottom,
               int x_dest_left, int y_dest_top){

    int height = (int)image->info.height;
    int width = (int)image->info.width;


    if(x_src_left < 0 || y_src_top < 0
            || x_src_right > width || y_src_bottom > height
            || x_src_left > x_src_right || y_src_top > y_src_bottom){
        printf("%d %d\n", y_src_bottom, y_src_top);
        puts("Wrong source area coordinates.");
        return;
    }

    if(x_dest_left < 0 || y_dest_top < 0){
        puts("Wrong destination area coordinates.");
        return;
    }


    y_dest_top = height - y_dest_top;
    y_src_top = height - y_src_top;
    y_src_bottom = height - y_src_bottom - 1;


    BMP newImage;

    newImage.info.height = y_src_top - y_src_bottom;
    newImage.info.width = x_src_right - x_src_left;

    unsigned int y_dest_bottom = y_dest_top - newImage.info.height;
    unsigned int x_dest_right = x_dest_left + newImage.info.width;

    if(y_dest_bottom > height || x_dest_right > width){
        printf("%d\n", y_dest_bottom);
        puts("Wrong destination area coordinates.");
        return;
    }


    newImage.pixels = malloc(newImage.info.height * sizeof(RGB*));

    for(int i = 0; i < newImage.info.height; ++i){
        newImage.pixels[i] = malloc(newImage.info.width * sizeof(RGB));
    }

    unsigned int x;
    unsigned int y = 0;

    for(unsigned int i = y_src_bottom; i < y_src_top; ++i){
        x = 0;
        for(unsigned int j = x_src_left; j < x_src_right; ++j){
            newImage.pixels[y][x] = image->pixels[i][j];
            ++x;
        }
        ++y;
    }

    y = 0;
    x = 0;


    for(unsigned int i = y_dest_bottom; i < y_dest_top; ++i){
        for(unsigned int j = x_dest_left; j < x_dest_right; ++j){
            image->pixels[i][j] = newImage.pixels[y][x];
            ++x;
        }
        ++y;
        x = 0;
    }

    freeMem(&newImage);
}

void rgbFilter(BMP* image, int value, char* component){
    if(value < 0 || value > 255){
        puts("Invalid component value.");
        return;
    }

    if(strcmp(component, "red") != 0 && strcmp(component, "green") != 0 && strcmp(component, "blue") != 0){
        printf("Wrong component name.");
        return;
    }

    for(int i = 0; i < image->info.height; ++i){
        for(int j = 0; j < image->info.width; ++j){
            if(!strcmp(component, "red"))
                image->pixels[i][j].r = value;

            if(!strcmp(component, "green"))
                image->pixels[i][j].g = value;

            if(!strcmp(component, "blue"))
                image->pixels[i][j].b = value;
        }
    }
}

int main(int argc, char* argv[]){
    BMP image;

    char filename[50];
    char out_file[50];
    strcpy(filename, argv[1]);
    strcpy(out_file, argv[argc - 1]);

    if(!strcmp(filename, "-h") || !strcmp(filename, "--help")){
        printHelp();
        return 0;
    }

    char *opts = "r:c:f:C:ih";

    struct option longOpts[]={
            {"reflect", required_argument, NULL, 'r'},
            {"copy", required_argument, NULL, 'c'},
            {"filter", required_argument, NULL, 'f'},
            { "changeColor", required_argument, NULL, 'C'},
            { "info", no_argument, NULL, 'i'},
            { "help", no_argument, NULL, 'h'}
    };
    int opt;
    int longIndex;
    opt = getopt_long(argc, argv, opts, longOpts, &longIndex);

    if(!readImage(&image, filename)) return 0;


    if(opt == -1){
        printHelp();
        return 0;
    }

    while (opt != -1) {

        switch(opt){
            case 'h': {
                printHelp();
                freeMem(&image);

                return 0;
            }

            case 'i': {
                printImageInfo(image);
                freeMem(&image);

                return 0;
            }

            case 'r': {
                char string[50];
                int x_left, x_right, y_top, y_bottom;

                int count = sscanf(optarg, "%d,%d,%d,%d,%s", &x_left, &y_top, &x_right, &y_bottom, string);

                if(count < 5){
                    puts("Too few arguments to do this function (-r/--reflect).");
                    break;
                }

                reflectArea(&image, string, x_left, y_top, x_right, y_bottom);
                break;
            }

            case 'c': {
                int x_src_left, x_src_right, y_src_top, y_src_bottom, x_dest_left, y_dest_top;

                int count = sscanf(optarg, "%d,%d,%d,%d,%d,%d", &x_src_left, &y_src_top, &x_src_right,
                                   &y_src_bottom, &x_dest_left, &y_dest_top);

                if(count < 6){
                    puts("Too few arguments to do this function (-c/--copy).");
                    break;
                }

                copyImage(&image, x_src_left, y_src_top, x_src_right, y_src_bottom, x_dest_left, y_dest_top);
                break;
            }

            case 'C':{
                int r1, g1, b1, r2, g2, b2;

                int count = sscanf(optarg, "%d,%d,%d,%d,%d,%d", &r1, &g1, &b1,
                                   &r2, &g2, &b2);

                if(count < 6){
                    puts("Too few arguments to do this function (-C/--changeColor).");
                    break;
                }

                changeColor(&image, r1, r2, g1, g2, b1, b2);
                break;
            }

            case 'f': {
                int value;
                char str[50];

                int count = sscanf(optarg, "%d,%s", &value, str);

                if(count < 2){
                    puts("Too few arguments to do this function (-f/--filter).");
                    break;
                }

                rgbFilter(&image, value, str);
                break;
            }

            default: {
                puts("No such key.");
                break;
            }

        }
        opt = getopt_long(argc, argv, opts, longOpts, &longIndex);
    }

    if(!writeImage(&image, out_file)){
        freeMem(&image);
    }


    
    return 0;
}