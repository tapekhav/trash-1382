#include "headers.h"
#include "structs.h"
#include "Read_Write.h"
#include "Draw_Funcs.h"

void Turn_Whole_Image(IMAGE* picture, Options* opt){
	switch (opt->angle)
	{
	case 180:{
		int height = picture->bmif.height;
		int width = picture->bmif.width;
		RGB** arr = picture->canvas;
		
		for (int i = 0; i < width/2; i++)
		{
			for (int j = 0; j < height; j++)
			{
				RGB temp = arr[j][i];
				arr[j][i] = arr[height-j-1][width-i-1];
				arr[height-j-1][width-i-1] = temp;
			}
			
		}
		break;
		}
	case 90:{
		unsigned int h = picture->bmif.width;
		unsigned int w = picture->bmif.height;

		unsigned int offset = (w * 3) % 4;
		offset = offset ? 4 - offset : offset;

		RGB **arr = malloc((h)*sizeof(RGB*));
		for(int i=0; i<h; i++){
			arr[i] = malloc(sizeof(RGB)*(w)+offset);
		}
		for(int i=0; i<picture->bmif.height; i++){
			for(int j=0; j<picture->bmif.width; j++){
				arr[picture->bmif.width-1-j][i] = picture->canvas[i][j];
			}
		}
		Free_Mem(picture);
		picture->bmif.height = h;
		picture->bmif.width = w;
		picture->canvas = arr;

		break;
		}
	case 270:{
		unsigned int h = picture->bmif.width;
		unsigned int w = picture->bmif.height;

		unsigned int offset = (w * 3) % 4;
		offset = offset ? 4 - offset : offset;

		RGB **arr = malloc((h)*sizeof(RGB*));
		for(int i=0; i<h; i++){
			arr[i] = malloc(sizeof(RGB)*(w)+offset);
		}
		for (int i = 0; i < picture->bmif.height; i++)
		{
			for (int j = 0; j < picture->bmif.width; j++)
			{
				arr[j][picture->bmif.height-i-1] = picture->canvas[i][j];
			}
			
		}
		
		Free_Mem(picture);
		picture->bmif.height = h;
		picture->bmif.width = w;
		picture->canvas = arr;
		break;
	}	
	default:{
		puts("IMAGE ROTATION FUNCTION:\nThe angle value is not correct.");
		break;
	}
	}
}

void Turn(IMAGE* picture, Options* opt){

	if (opt->x1 <= 0 && opt->y2 <= 0 && opt->x2 >= picture->bmif.width-1 && opt->y1 >= picture->bmif.height-1)
	{
		Turn_Whole_Image(picture, opt);
	}
	else if(opt->angle == 90 || opt->angle == 180 || opt->angle == 270){
	
	if (opt->y1 >= picture->bmif.height)
	{
		opt->y1 = picture->bmif.height - 1;
	}
	if (opt->y2 < 0)
	{
		opt->y2 = 0;
	}
	if (opt->x2 >= picture->bmif.width)
	{
		opt->x2 = picture->bmif.width;
	}
	if (opt->x1 < 0)
	{
		opt->x1 = 0;
	}
	



	int copy_area_height = opt->y1-opt->y2;
	int copy_area_width = opt->x2-opt->x1;

	RGB** copy_area = malloc(picture->bmif.height * sizeof(RGB*));

	for (int i = 0; i < picture->bmif.height; i++)
	{
		copy_area[i] = malloc(picture->bmif.width*sizeof(RGB));

		for (int j = 0; j < picture->bmif.width; j++)
		{
			copy_area[i][j] = picture->canvas[i][j];
		}
	}

	for (int i = 1; i < copy_area_height - 1; i++)
	{
		for (int j = 1; j < copy_area_width - 1; j++)
		{
			Write_Pixel(picture, opt->x1 + j, opt->y2 + i, 255, 255, 255);
		}
	}

	int x_center = opt->x1 + copy_area_width/2;
	int y_center = opt->y2 + copy_area_height/2;
	int new_x, new_y;

	int trans_matrix[2][2];

	switch (opt->angle)
	{
		case 180:
            trans_matrix[0][0] = -1;
            trans_matrix[0][1] = 0;
            trans_matrix[1][0] = 0;
            trans_matrix[1][1] = -1;
            break;
		case 90:
			trans_matrix[0][0] = 0;
            trans_matrix[0][1] = -1;
            trans_matrix[1][0] = 1;
            trans_matrix[1][1] = 0;
            break;
		case 270:
			trans_matrix[0][0] = 0;
            trans_matrix[0][1] = 1;
            trans_matrix[1][0] = -1;
            trans_matrix[1][1] = 0;
            break;
		default:
			break;
	}
	for(int y = -(copy_area_height)/2; y < (copy_area_height)/2; y++ ){
	 for (int x = -(copy_area_width)/2; x < (copy_area_width)/2; x++) {
            new_y = trans_matrix[1][0]*x + trans_matrix[1][1]*y + y_center;
            new_x = trans_matrix[0][0]*x + trans_matrix[0][1]*y + x_center;
            if(new_y<picture->bmif.height && new_x<picture->bmif.width && new_y>=0 && new_x>=0)
              picture->canvas[new_y][new_x] = copy_area[y + y_center][x + x_center];
        	}
    	}
	}
	else
		puts("IMAGE ROTATION FUNCTION:\nThe angle value is not correct.");
}