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

typedef struct
{
    int x_src_left, y_src_top, x_src_right, y_src_bottom;
    int x_dest_left, y_dest_top;
    char* axis;
    int r1, g1, b1;
    int r2, g2, b2;
    char* component;
    int value_of_component;
    int help, info;
    int reflectArea, copyArea, changeColor, rgbFilter;
} configs;


void printHelp(){
    puts("This program supports CLI and only works with version 3 BMP files.");
    puts("BMP files with color table are not supported.");
    puts("The program only supports files with a depth of 24 pixels per bit.");
    puts("The photo must not be compressed.");
    puts("In the copy area and reflect area functions, the top left pixel is considered the origin (0, 0).");
    puts("The default value of all integer arguments for all keys is 0.");
    puts("The default value is NULL for arguments of type char*.");
    puts("If the required key was not entered or the key arguments were entered incorrectly,\nthen standard values are passed to the function.");
    puts("Format of input: ./a.out [key of input file] [name of function] [key 1] [argument 1],...,[argument N] ...\n"
         " [key N] [argument 1],...,[argument N] [name of output file]\n");

    puts("All functions:");
    puts("\treflectArea(--reflectArea/-R):");
    puts("\t\tReflects a photo along a certain axis at the specified coordinates.");
    puts("\t\tThis function needs -a(--axis), -l(--src_coordinates_left_top) "
         "and -r(--src_coordinates_right_bottom) keys.");
    puts("\tcopyArea(--copyArea/-C):");
    puts("\t\tCopy area in picture and inserts it in certain place.");
    puts("\t\tThis function needs -l(--src_coordinates_left_top), -r(--src_coordinates_right_bottom) "
         "and -d(dest_coordinates_left_top) keys.");
    puts("\tchangeColor(--changeColor/-c):");
    puts("\t\tChange color based on RGB components.");
    puts("\t\tThis function needs -1(--first_color) and -2(--second_filter) keys.");
    puts("\trgbFilter(--rgbFilter/-F):");
    puts("\t\tChanges the value of one of the components all over the photo.");
    puts("\t\tThis function needs -a(--axis) and -v(--value_of_component) keys.\n");

    puts("All keys:");
    puts("\t-1(--first_color):");
    puts("\t\tGets the components of color to be changed (3 arguments).");
    puts("\t-2(--second_color):");
    puts("\t\tGets the components of the color to be changed to (3 arguments).");
    puts("\t-l(--src_coordinates_left_top):");
    puts("\t\tGets the coordinates of the top left corner of the source (2 arguments).");
    puts("\t-r(--src_coordinates_right_bottom):");
    puts("\t\tGets the coordinates of the bottom right corner of the source (2 arguments).");
    puts("\t-d(--dest_coordinates_left_top):");
    puts("\t\tGets the coordinates of the top left corner of the destination (2 arguments).");
    puts("\t-o(--option):");
    puts("\t\tGets a string with the name of the component (1 argument).");
    puts("\t-v(--value_of_component):");
    puts("\t\tGets the value of the component (1 argument).");
    puts("\t-a(--axis):");
    puts("\t\tGets a string with the name of the axis (1 argument).");
    puts("\t-h(--help):");
    puts("\t\tPrint instruction for using the program.");
    puts("\t-i(--info):");
    puts("\t\tPrints information about a file.\n");
    puts("An example of using the program:");
    puts("./a.out simpsonsvr.bmp --changeColor -1 255,255,255 -2 0,0,0 out.bmp");
    puts("./a.out simpsonsvr.bmp -R -l 100,100 -r 400,400 -a vertical out.bmp");
    puts("./a.out simpsonsvr.bmp -C -l 100,100 -r 300,300 -d 300,300 out.bmp");
    puts("./a.out simpsonsvr.bmp -F --option red --value_of_component 255 out.bmp");
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

    if(!f){
        puts("There is no such file in this directory.");
        return 0;
    }

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
    if(r1 < 0 || r2 < 0 || g1 < 0 || g2 < 0 || b1 < 0 || b2 < 0
            || r1 > 255 || r2 > 255 || g1 > 255
            || g2 > 255 || b1 > 255 || b2 > 255){
        puts("One of the component is incorrectly set.");
        return;
    }

    for(int i = 0; i < image->info.height; ++i){
        for(int j = 0; j < image->info.width; ++j){
            if(image->pixels[i][j].r == r1 && image->pixels[i][j].g == g1
            && image->pixels[i][j].b == b1){
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

    if(x_left < 0 || x_left > x_right || x_right > (image->info.width - 1)
    || y_bottom > (image->info.height - 1) || y_top < 0 || y_top > y_bottom){
        puts("Wrong coordinates.");
        return;
    }

    unsigned int width_of_area = x_right - x_left + 1;
    unsigned int height_of_area = y_bottom - y_top;

    y_bottom = (int)image->info.height - y_bottom - 1;
    y_top = (int)image->info.height - y_top - 1;

    if(!strcmp(axis, "vertical")){
        for (int y = 0; y < height_of_area; ++y) {
            for (int x = 0; x < width_of_area / 2; ++x) {
                swapPixels(&image->pixels[y_top - y][x_left + x], &image->pixels[y_top - y][x_right - x]);
            }
        }
    }

    if(!strcmp(axis, "horizontal")) {
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

void copyArea(BMP* image, int x_src_left, int y_src_top,
               int x_src_right, int y_src_bottom,
               int x_dest_left, int y_dest_top){

    int height = (int)image->info.height;
    int width = (int)image->info.width;


    if(x_src_left < 0 || y_src_top < 0
            || x_src_right > (width - 1) || y_src_bottom > (height - 1)
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
    y_src_bottom = height - y_src_bottom - 1;


    BMP newImage;

    newImage.info.height = y_src_top - y_src_bottom;
    newImage.info.width = x_src_right - x_src_left;

    unsigned int y_dest_bottom = y_dest_top - newImage.info.height;
    unsigned int x_dest_right = x_dest_left + newImage.info.width;

    if(y_dest_bottom > height || x_dest_right > width){
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

    if(strcmp(component, "red") != 0 && strcmp(component, "green") != 0
    && strcmp(component, "blue") != 0){
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


void choice(configs* config, int opt){
    int count;

    switch (opt) {
        case '1':
            count = sscanf(optarg, "%d,%d,%d", &config->r1, &config->g1, &config->b1);

            if(count < 3) puts("Some arguments were not read, so their default value did not change.");

            break;
        case '2':
            count = sscanf(optarg, "%d,%d,%d", &config->r2, &config->g2, &config->b2);

            if(count < 3) puts("Some arguments were not read, so their default value did not change.");

            break;
        case 'o':
            config->component = malloc(50 * sizeof(char));
            count = sscanf(optarg, "%s", config->component);

            if(count < 1) puts("Some arguments were not read, so their default value did not change.");

            break;
        case 'v':
            count = sscanf(optarg, "%d", &config->value_of_component);

            if(count < 1) puts("Some arguments were not read, so their default value did not change.");

            break;
        case 'l':
            count = sscanf(optarg, "%d,%d", &config->x_src_left, &config->y_src_top);

            if(count < 2) puts("Some arguments were not read, so their default value did not change.");

            break;
        case 'r':
            count = sscanf(optarg, "%d,%d", &config->x_src_right, &config->y_src_bottom);

            if(count < 2) puts("Some arguments were not read, so their default value did not change.");

            break;
        case 'd':
            count = sscanf(optarg, "%d,%d", &config->x_dest_left, &config->y_dest_top);

            if(count < 2) puts("Some arguments were not read, so their default value did not change.");

            break;
        case 'a':
            config->axis = malloc(50 * sizeof(char));
            count = sscanf(optarg, "%s", config->axis);

            if(count < 1) puts("Some arguments were not read, so their default value did not change.");

            break;
        case 'R':
            config->reflectArea = 1;
            break;
        case 'C':
            config->copyArea = 1;
            break;
        case 'c':
            config->changeColor = 1;
            break;
        case 'F':
            config->rgbFilter = 1;
            break;
        case 'h':
            config->help = 1;
            break;
        case 'i':
            config->info = 1;
            break;
        default:
            puts("No such key.");
            break;
    }
}

int main(int argc, char* argv[]){
    BMP image;

    char filename[50];
    char out_file[50];

    if(argc < 1){
        puts("The program received too few arguments.");
        puts("Enter the key -h(--help) to see the instructions for the program.");
        return 0;
    }

    strcpy(filename, argv[1]);
    strcpy(out_file, argv[argc - 1]);

    if(!strcmp(filename, "-h") || !strcmp(filename, "--help")){
        printHelp();
        return 0;
    }

    if(argc < 3){
        puts("The program received too few arguments.");
        puts("Enter the key -h(--help) to see the instructions for the program.");
        return 0;
    }



    char *opts = "1:2:l:r:d:o:v:a:RCFcih";

    struct option longOpts[]={
            {"first_color", required_argument, NULL, '1'},
            {"second_color", required_argument, NULL, '2'},
            {"src_coordinates_left_top", required_argument, NULL, 'l'},
            {"src_coordinates_right_bottom", required_argument, NULL, 'r'},
            { "dest_coordinates_left_top", required_argument, NULL, 'd'},
            { "option", required_argument, NULL, 'o'},
            { "value_of_component", required_argument, NULL, 'v'},
            { "axis", required_argument, NULL, 'a'},
            { "help", no_argument, NULL, 'h'},
            { "info", no_argument, NULL, 'i'},
            { "reflectArea", no_argument, NULL, 'R'},
            { "copyArea", no_argument, NULL, 'C'},
            { "rgbFilter", no_argument, NULL, 'F'},
            { "changeColor", no_argument, NULL, 'c'},
            {NULL, no_argument, NULL, 0}
    };
    int opt;
    int longIndex;
    opt = getopt_long(argc, argv, opts, longOpts, &longIndex);

    configs config = {0, 0, 0, 0, 0,
                      0, NULL, 0, 0, 0,
                      0, 0, 0, NULL, 0,
                      0, 0, 0, 0, 0, 0};


    if(!readImage(&image, filename)) return 0;


    if(opt == -1){
        puts("Invalid input format.");
        return 0;
    }

    while(opt != -1){
        choice(&config, opt);
        opt = getopt_long(argc, argv, opts, longOpts, &longIndex);
    }

    if(config.help == 1){
        printHelp();

        freeMem(&image);
        return 0;
    }
    if(config.info == 1){
        printImageInfo(image);

        freeMem(&image);
        return 0;
    }

    if(config.changeColor == 1){
        changeColor(&image, config.r1, config.r2, config.g1,
                    config.g2, config.b1, config.b2);
    }
    if(config.rgbFilter == 1){
        if(config.component != NULL) {
            rgbFilter(&image, config.value_of_component, config.component);
            free(config.component);
        } else {
            puts("You did not enter a component name.");
        }
    }
    if(config.reflectArea == 1){
        if(config.axis != NULL) {
            reflectArea(&image, config.axis, config.x_src_left,
                        config.y_src_top, config.x_src_right, config.y_src_bottom);
            free(config.axis);
        } else {
            puts("You did not enter an axis name.");
        }
    }
    if(config.copyArea == 1){
        copyArea(&image, config.x_src_left, config.y_src_top,config.x_src_right,
                  config.y_src_bottom, config.x_dest_left, config.y_dest_top);
    }


    if(!writeImage(&image, out_file)){
        freeMem(&image);
    }


    return 0;
}