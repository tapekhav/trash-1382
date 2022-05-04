#include <stdio.h>
#include <stdlib.h>
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
	unsigned char red;
	unsigned char green;
	unsigned char blue;
} RGB;

#pragma pack(pop)


typedef struct
{
	BitmapFileHeader bmfh;
	BitmapInfoHeader bmif;
	RGB **canvas;

} IMAGE;

typedef struct
{
	int fill;
	int radius;
	int thick;
	int side;
	int angle;
	int x1;
	int y1;
	int x2;
	int y2;
	char* color_of_fill;
	char* color_of_lines;
} Options;

void printFileHeader(BitmapFileHeader header){
	printf("signature:\t%x (%hu)\n", header.signature, header.signature);
	printf("filesize:\t%x (%u)\n", header.filesize, header.filesize);
	printf("reserved1:\t%x (%hu)\n", header.reserved1, header.reserved1);
	printf("reserved2:\t%x (%hu)\n", header.reserved2, header.reserved2);
	printf("pixelArrOffset:\t%x (%u)\n", header.pixelArrOffset, header.pixelArrOffset);
}

void printInfoHeader(BitmapInfoHeader header){
	printf("headerSize:\t%x (%u)\n", header.headerSize, header.headerSize);
	printf("width:     \t%x (%u)\n", header.width, header.width);
	printf("height:    \t%x (%u)\n", header.height, header.height);
	printf("planes:    \t%x (%hu)\n", header.planes, header.planes);
	printf("bitsPerPixel:\t%x (%hu)\n", header.bitsPerPixel, header.bitsPerPixel);
	printf("compression:\t%x (%u)\n", header.compression, header.compression);
	printf("imageSize:\t%x (%u)\n", header.imageSize, header.imageSize);
	printf("xPixelsPerMeter:\t%x (%u)\n", header.xPixelsPerMeter, header.xPixelsPerMeter);
	printf("yPixelsPerMeter:\t%x (%u)\n", header.yPixelsPerMeter, header.yPixelsPerMeter);
	printf("colorsInColorTable:\t%x (%u)\n", header.colorsInColorTable, header.colorsInColorTable);
	printf("importantColorCount:\t%x (%u)\n", header.importantColorCount, header.importantColorCount);
}

void Write_Pixel(IMAGE* picture, int x, int y, unsigned char r, unsigned char g, unsigned char b){
	unsigned int H = picture->bmif.height;
	unsigned int W = picture->bmif.width;

	if((y > -1) && (y < H) && (x > -1) && (x < W)){
		RGB pixel;
		pixel.red = r;
		pixel.green = g;
		pixel.blue = b;
		picture->canvas[y][x] = pixel;
	}
}

void Read_Image(IMAGE* picture, char* file_input_name){

	FILE *src_img = fopen(file_input_name, "rb");


	fread(&picture->bmfh, 1, sizeof(BitmapFileHeader), src_img);
	fread(&picture->bmif, 1, sizeof(BitmapInfoHeader), src_img);


	unsigned int height = picture->bmif.height;
	unsigned int width = picture->bmif.width;
	unsigned int offset = (width * 3) % 4;

	picture->canvas = malloc(height * sizeof(RGB*));

	for(int i = 0; i < height; i++){
		picture->canvas[i] = malloc(width * sizeof(RGB) + offset);
		fread(picture->canvas[i], 1, width * sizeof(RGB) + offset, src_img);
	}

	fclose(src_img);

}

void Write_Image(IMAGE* picture, char* file_output_name){

	FILE *new_img = fopen(file_output_name, "wb");

	fwrite(&picture->bmfh, 1, sizeof(BitmapFileHeader), new_img);
	fwrite(&picture->bmif, 1, sizeof(BitmapInfoHeader), new_img);

	unsigned int height = picture->bmif.height;
    unsigned int width = picture->bmif.width;

	unsigned int w = width * sizeof(RGB) + (width * 3) % 4;

	for(int i = 0; i < height; i++){
		fwrite(picture->canvas[i], 1, w, new_img);
	}
	fclose(new_img);

}

void Filter_RGB(IMAGE* picture, char* component_name, int new_value){
	if(strstr("rgb", component_name) && (new_value >= 0) && (new_value <= 255)){
		for(int i = 0; i < picture->bmif.height; i++){
			for(int j = 0; j < picture->bmif.width; j++){

				if(!strcmp(component_name, "r"))
					picture->canvas[i][j].red = (unsigned char) new_value;

				if(!strcmp(component_name, "g"))
					picture->canvas[i][j].green = (unsigned char) new_value;

				if(!strcmp(component_name, "b"))
					picture->canvas[i][j].blue = (unsigned char) new_value;

			}
		}
	}
	else{
		printf("ERORR!!!");
	}
}

void Draw_Square(IMAGE* picture, Options* opt){
	int side = opt->side;

	// Fill the square
	if(opt->fill == 1){
		for (int i = opt->x1; i < opt->x1 + side; i++)
		{
			for (int j = opt->y1; j > opt->y1 - side; j--)
			{
				Write_Pixel(picture, i, j, 255, 255, 255);
			}
		}
	}

	// Draw diagonals
	for (int thick = 0; thick < opt->thick; thick++){
		for (int i = 0; i < side; i++)
		{
			Write_Pixel(picture, opt->x1 + i + thick, opt->y1 - i, 255, 0, 0);
			Write_Pixel(picture, opt->x1 + i - thick, opt->y1 - i, 255, 0, 0);

			Write_Pixel(picture, opt->x1 + side - i + thick - 1, opt->y1 - i, 255, 0, 0);
			Write_Pixel(picture, opt->x1 + side - i - thick - 1, opt->y1 - i, 255, 0, 0);
		}
	}
	
	// Draw sides
	for (int thick = 0; thick < opt->thick; thick++)
	{	
		// horizontals
		for (int i = opt->x1 - thick + 1; i < opt->x1 + side + thick; i++){
			Write_Pixel(picture, i, opt->y1 + thick, 0, 0, 0);
			Write_Pixel(picture, i, opt->y1 - side + 1  + thick, 0, 0, 0);
			Write_Pixel(picture, i, opt->y1 - thick, 0, 0, 0);
			Write_Pixel(picture, i, opt->y1 - side + 1 - thick, 0, 0, 0);
		}
		
		// verticals
		for (int i = opt->y1 - side + 1 - thick; i <= opt->y1 + thick; i++){
			Write_Pixel(picture, opt->x1 + thick, i, 0, 0, 0);
			Write_Pixel(picture,opt->x1 + side - 1 + thick, i, 0, 0, 0);
			Write_Pixel(picture, opt->x1 - thick, i, 0, 0, 0);
			Write_Pixel(picture,opt->x1 + side - 1 - thick, i, 0, 0, 0);
		}
		

	}
	
	
}

void Draw_Circle(IMAGE* picture, Options* opt){
	int r = 0, g = 0, b = 0;
	int x = 0;
	int y = opt->radius;
	int delta = 1 - 2 * opt->radius;
	int error = 0;
	while(y >= 0) {
		Write_Pixel(picture, opt->x1 + x, opt->y1 + y, r, g, b);
		Write_Pixel(picture, opt->x1 + x, opt->y1 - y, r, g, b);
		Write_Pixel(picture, opt->x1 - x, opt->y1 + y, r, g, b);
		Write_Pixel(picture, opt->x1 - x, opt->y1 - y, r, g, b);
		error = 2 * (delta + y) - 1;
		if(delta < 0 && error <= 0) {
			++x;
			delta += 2 * x + 1;
			continue;
		}
		error = 2 * (delta - x) - 1;
		if(delta > 0 && error > 0) {
			--y;
			delta += 1 - 2 * y;
			continue;
		}
		++x;
		delta += 2 * (x - y);
		--y;
	}
	
}

void rotate(IMAGE* picture, Options* opt){
	int x1 = opt->x1;
	int y1 = opt->y1;
	int x2 = opt->x2;
	int y2 = opt->y2;
	int height = y1 - y2 + 1;
	int width = x2 - x1 + 1;
	RGB** arr = picture->canvas;
	switch (opt->angle)
	{
		case 180:

			for (int y = 0; y < height; y++) {
            	for (int x = 0; x < (width / 2); x++) {

					RGB temp_pixel = arr[y1 - y][x1 + x];
                	arr[y1 - y][x1 + x] = arr[y1 - y][x2 - x];
					arr[y1 - y][x2 - x] = temp_pixel;
            	}
       		}
        	for (int y = 0; y < (height / 2); y++) {
            	for (int x = 0; x < width; x++) {
					RGB temp_pixel = arr[y2 + y][x1 + x];
                	arr[y2 + y][x1 + x] =  arr[y1 - y][x1 + x];
					arr[y1 - y][x1 + x] = temp_pixel;
            	}
       		}
			
			break;
		
		default:
			printf("The program does not work with the given angle.");
			break;
	}
	
}



int main(int argc, char** argv){

	IMAGE picture;
	Read_Image(&picture, "simpsonsvr.bmp");
	Options cc = {0, 0, 1, 100, 180, -1, 562, 780, 0};
	//printInfoHeader(picture.bmif);
	//Filter_RGB(&picture, "r", 255);
	rotate(&picture, &cc);
	//Draw_Square(&picture, &cc);
	//Draw_Circle(&picture, &cc);
	Write_Image(&picture, "new.bmp");

	return 0;
}
