#include "headers.h"
#include "structs.h"

int Image_OK(IMAGE* picture){

    if(picture->bmif.headerSize != 40){
        puts("This version of the BMP file is not supported.");
        return 0;
    }

    if(picture->bmif.planes != 1){
        puts("Unsupported quantity of planes.");
        return 0;
    }

    if(picture->bmif.compression != 0){
        puts("The file is compressed.");
        return 0;
    }

    if(picture->bmif.bitsPerPixel != 24){
        puts("The color depth of the file is not 24 pixels per bit.");
        return 0;
    }

    if(picture->bmif.colorsInColorTable != 0 || picture->bmif.importantColorCount != 0){
        puts("This file uses a color table.");
        return 0;
    }

    return 1;
}

void Free_Mem(IMAGE* picture){
    for(unsigned int i = 0; i < picture->bmif.height; ++i){
        free(picture->canvas[i]);
    }
    free(picture->canvas);
}

int Read_Image(IMAGE* picture, char* file_input_name){

	if(file_input_name[strlen(file_input_name) - 1] != 'p' || file_input_name[strlen(file_input_name) - 2] != 'm' || file_input_name[strlen(file_input_name) - 3] != 'b' || file_input_name[strlen(file_input_name) - 4] != '.'){
			puts("Wrong format of input file.");
			return 1;
	}
	FILE *src_img = fopen(file_input_name, "rb");

	if (src_img == NULL)
	{
		printf("The input file could not be opened.");
		return 1;
	}

	fread(&picture->bmfh, 1, sizeof(BitmapFileHeader), src_img);

	fread(&picture->bmif, 1, sizeof(BitmapInfoHeader), src_img);

	if (!Image_OK(picture))
	{
		puts("This bmp file is not supported.");
		return 1;
	}
	

	unsigned int height = picture->bmif.height;
	unsigned int width = picture->bmif.width;
	
	unsigned int offset = (width*3)%4;

	offset = offset ? 4 - offset : offset;

	picture->canvas = malloc(height * sizeof(RGB*));
	unsigned int w = (picture->bmif.width) *sizeof(RGB) + offset;
	for(int i = 0; i < height; i++){
		picture->canvas[i] = malloc(w);
		
		fread(picture->canvas[i], 1,w, src_img);
	}
	fclose(src_img);
	return 0;
}

int Write_Image(IMAGE* picture, char* file_output_name){
	if(file_output_name[strlen(file_output_name) - 1] != 'p' || file_output_name[strlen(file_output_name) - 2] != 'm'
    || file_output_name[strlen(file_output_name) - 3] != 'b' || file_output_name[strlen(file_output_name) - 4] != '.'){
        puts("Wrong format of output file.");
        return 1;
    }
	FILE *new_img = fopen(file_output_name, "wb");

	if (new_img == NULL)
	{
		printf("The output file could not be opened.");
		return 1;
	}
	
	fwrite(&picture->bmfh, 1, sizeof(BitmapFileHeader), new_img);
	fwrite(&picture->bmif, 1, sizeof(BitmapInfoHeader), new_img);

	unsigned int height = picture->bmif.height;
    unsigned int width = picture->bmif.width;

	unsigned int offset = (width * 3) % 4;
	offset = offset ? 4 - offset : offset;

	for(int i = 0; i < height; i++){
		fwrite(picture->canvas[i], 1, width * sizeof(RGB) + offset, new_img);
	}
	fclose(new_img);
    Free_Mem(picture);
	return 0;
}
