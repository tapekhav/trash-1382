#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

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
	unsigned char blue;
	unsigned char green;
	unsigned char red;
} RGB;

typedef struct
{
	BitmapFileHeader bmfh;
	BitmapInfoHeader bmif;
	RGB **canvas;

} IMAGE;

#pragma pack(pop)

typedef struct
{
	int action, info_or_help;
	int fill;
	int component_value;
	int radius;
	int thick;
	int side;
	int angle;
	int x1, y1;
	int x2, y2;
	char* component;
	int f_r, f_g, f_b;
	int l_r, l_g, l_b;
} Options;

void Print_Info(IMAGE img){
	printf("signature:\t%x (%hu)\n", img.bmfh.signature, img.bmfh.signature);
	printf("filesize:\t%x (%u)\n", img.bmfh.filesize, img.bmfh.filesize);
	printf("reserved1:\t%x (%hu)\n",img.bmfh.reserved1, img.bmfh.reserved1);
	printf("reserved2:\t%x (%hu)\n", img.bmfh.reserved2, img.bmfh.reserved2);
	printf("pixelArrOffset:\t%x (%u)\n", img.bmfh.pixelArrOffset, img.bmfh.pixelArrOffset);
	printf("headerSize:\t%x (%u)\n", img.bmif.headerSize, img.bmif.headerSize);
	printf("width:     \t%x (%u)\n", img.bmif.width, img.bmif.width);
	printf("height:    \t%x (%u)\n", img.bmif.height, img.bmif.height);
	printf("planes:    \t%x (%hu)\n", img.bmif.planes, img.bmif.planes);
	printf("bitsPerPixel:\t%x (%hu)\n", img.bmif.bitsPerPixel, img.bmif.bitsPerPixel);
	printf("compression:\t%x (%u)\n", img.bmif.compression, img.bmif.compression);
	printf("imageSize:\t%x (%u)\n", img.bmif.imageSize, img.bmif.imageSize);
	printf("xPixelsPerMeter:\t%x (%u)\n", img.bmif.xPixelsPerMeter, img.bmif.xPixelsPerMeter);
	printf("yPixelsPerMeter:\t%x (%u)\n", img.bmif.yPixelsPerMeter, img.bmif.yPixelsPerMeter);
	printf("colorsInColorTable:\t%x (%u)\n", img.bmif.colorsInColorTable, img.bmif.colorsInColorTable);
	printf("importantColorCount:\t%x (%u)\n", img.bmif.importantColorCount, img.bmif.importantColorCount);
}

int Check_Image(IMAGE* picture){

    if(picture->bmif.headerSize != 40){
        puts("This version of the BMP file is not supported. Please, change your file.");
        return 0;
    }

    if(picture->bmif.planes != 1){
        puts("Unsupported quantity of planes. Please, change your file.");
        return 0;
    }

    if(picture->bmif.compression != 0){
        puts("The file is compressed. Please, change your file.");
        return 0;
    }

    if(picture->bmif.bitsPerPixel != 24){
        puts("The color depth of the file is not 24 pixels per bit. Please, change your file.");
        return 0;
    }

    if(picture->bmif.colorsInColorTable != 0 || picture->bmif.importantColorCount != 0){
        puts("This file uses a color table. Please, change your file.");
        return 0;
    }

    return 1;
}

void Write_Pixel(IMAGE* picture, int x, int y, int r, int g, int b){
	unsigned int H = picture->bmif.height;
	unsigned int W = picture->bmif.width;
	if((y > -1) && (y < (int) H) && (x > -1) && (x < (int) W)){
		RGB pixel;
		pixel.red = r;
		pixel.green = g;
		pixel.blue = b;
		picture->canvas[y][x] = pixel;
	}
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

void Filter_RGB(IMAGE* picture, Options* opt){
	printf("%d", opt->component_value);
	if(strstr("rgb", opt->component) && (opt->component_value >= 0) && (opt->component_value <= 255)){
		for(int i = 0; i < picture->bmif.height; i++){
			for(int j = 0; j < picture->bmif.width; j++){

				if(!strcmp(opt->component, "r"))
					picture->canvas[i][j].red = (unsigned char) opt->component_value;

				if(!strcmp(opt->component, "g"))
					picture->canvas[i][j].green = (unsigned char) opt->component_value;

				if(!strcmp(opt->component, "b"))
					picture->canvas[i][j].blue = (unsigned char) opt->component_value;

			}
		}
	}
	else{
		printf("ERORR!!!");
	}
}

void Draw_Square(IMAGE* picture, Options opt){
	int side = opt.side;
	
	int x1 = opt.x1;
	int y1 = opt.y1;
	int thick = opt.thick;
	// Fill the square
	if(opt.fill == 1){
		for (int i = x1; i < x1 + side; i++)
		{
			for (int j = y1; j > y1 - side; j--)
			{
				Write_Pixel(picture, i, j, opt.f_r, opt.f_g, opt.f_b);
			}
		}
	}
	
	// Draw diagonals
	for (int thick = 0; thick < opt.thick; thick++){
		for (int i = 0; i < side + 1; i++)
		{
			Write_Pixel(picture, x1 + i + thick, y1 - i, opt.l_r, opt.l_g, opt.l_b);
			Write_Pixel(picture, x1 + i - thick, y1 - i,  opt.l_r, opt.l_g, opt.l_b);

			Write_Pixel(picture, x1 + side - i + thick - 1, y1 - i, opt.l_r, opt.l_g, opt.l_b);
			Write_Pixel(picture, x1 + side - i - thick - 1, y1 - i, opt.l_r, opt.l_g, opt.l_b);
		}
	}
	
	
	// Draw sides
	for (int thick = 0; thick < opt.thick; thick++)
	{	
		
		// horizontals
		for (int i = x1 - thick - 1; i <= x1 + side + thick; i++){
			Write_Pixel(picture, i, y1 + thick + 1,  opt.l_r, opt.l_g, opt.l_b);
			Write_Pixel(picture, i, y1 - side - thick ,  opt.l_r, opt.l_g, opt.l_b);
		}
		
		// verticals
		for (int i = y1 - side - thick; i <= y1 + thick; i++){
			Write_Pixel(picture, x1 - thick - 1, i, opt.l_r, opt.l_g, opt.l_b);
			Write_Pixel(picture, x1 + side + thick, i,  opt.l_r, opt.l_g, opt.l_b);
		}
		/*
		// verticals
		for (int i = opt->y1 - side - thick + 1; i <= opt->y1 + thick; i++){
			Write_Pixel(picture, opt->x1 + thick, i, 0, 0, 0);
			Write_Pixel(picture,opt->x1 + side + thick, i, 0, 0, 0);
			//Write_Pixel(picture, opt->x1 - thick, i, 0, 0, 0);
			//Write_Pixel(picture,opt->x1 + side - 1 - thick, i, 0, 0, 0);
		}
		*/

	}

}

void Draw_Circle(IMAGE* picture, Options opt){

	//printf("-%p-", opt.color_fill);
	int y1 = opt.y1;
	int x1 = opt.x1;
	int radius = opt.radius;
	if (opt.fill){
    for(int i = y1 - radius - 1; i < y1 + radius + 1; i++){
		for(int j = x1 - radius - 1; j < x1 + radius + 1; j++){
			if((j - x1)*(j - x1) + (i - y1)*(i - y1) < (radius)*(radius)){
				//printf("|%p|", opt.color_fill);
				Write_Pixel(picture, j, i, opt.f_r, opt.f_g, opt.f_b);
				}
			}
		}
	}

	for(int i = y1 - radius - opt.thick; i < y1 + radius + opt.thick; i++){
		for(int j = x1 - radius - opt.thick; j < x1 + radius + opt.thick; j++){
			if(((j - x1)*(j - x1) + (i - y1)*(i - y1) >= (radius) * (radius)) && ((j - x1)*(j - x1) + (i - y1)*(i - y1) < (radius + opt.thick)*(radius + opt.thick)))
				Write_Pixel(picture, j, i, opt.l_r, opt.l_g, opt.l_b);
		}
	}
}

void Rotate_Whole_Image(IMAGE* picture, Options* opt){
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
		printf("IMAGE ROTATION FUNCTION:\nThe angle value is not correct.\n");
		break;
	}
	}
}

void Rotate(IMAGE* picture, Options* opt){

	if (opt->x1 <= 0 && opt->y1 <= 0 && opt->x2 >= picture->bmif.width-1 && opt->y2 >= picture->bmif.height-1)
	{
		Rotate_Whole_Image(picture, opt);
		return;
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
		puts("This rotation angle is not supported.");
}

void choice(Options* config, const char option){
	int count = -1;
    switch (option) {
        case 'T':{
            count = sscanf(optarg, "%d", &config->angle);
            if(count != 1){ puts("The angle remained at the default value (0).");}
			config->action = 1;
            break;
		}
		case 'S':{
            count = sscanf(optarg, "%d", &config->side);
            if(count != 1){ puts("The side of square remained at the default value (0).");}
			config->action = 2;
            break;
		}
		case 'F':{
			config->component = malloc(20 * sizeof(char));
            count = sscanf(optarg, "%s", config->component);
            if(count != 1){ puts("The component remained at the default value r (Red).");
			config->component = "r";
			}
			config->action = 3;
            break;
		}
		case '1':{
            config->action = 4;
			break;
		}
		case '2':{
            count = sscanf(optarg, "%d", &config->radius);
            if(count != 1){ puts("The radius was not set, the default value is set (0).");}
            config->action = 5;
			break;
		}
		case 'l':{
            count = sscanf(optarg, "%d,%d,%d", &config->l_r, &config->l_g, &config->l_b);

			if(count < 3){ puts("The missing values for lines will be set to default (0).");}

			if (config->l_r < 0 || config->l_r > 255)
			{
				config->l_r = 0;
				puts("The value of the red component of the line is set to the default value (0).");
			}
			if (config->l_g < 0 || config->l_g > 255)
			{
				config->l_g = 0;
				puts("The value of the green component of the line is set to the default value (0).");
			}
			if (config->l_b < 0 || config->l_b > 255)
			{
				config->l_b = 0;
				puts("The value of the blue component of the line is set to the default value (0).");
			}
			break;
		}
		case 't':{
			count = sscanf(optarg, "%d", &config->thick);

			if (count != 1)
			{
				config->thick = 0;
				puts("The thickness is set to the default value (0).");
			}
			if (config->thick < 0)
			{
				config->thick = 0;
				puts("The negative thickness value has been replaced with the default value (0).");
			}
			break;
		}
		case 'f':{
            count = sscanf(optarg, "%d,%d,%d", &config->f_r, &config->f_g, &config->f_b);
			if(count < 3){ puts("The missing values for fill will be set to default (0).");}

			if (config->f_r < 0 || config->f_r > 255)
			{
				config->f_r = 0;
				puts("The value of the red component of the fill is set to the default value (0).");
			}
			if (config->f_g < 0 || config->f_g > 255)
			{
				config->f_g = 0;
				puts("The value of the green component of the fill is set to the default value (0).");
			}
			if (config->f_b < 0 || config->f_b > 255)
			{
				config->f_b = 0;
				puts("The value of the blue component of the fill is set to the default value (0).");
			}
			config->fill = 1;
			break;
		}
		case 'c':{
			count = sscanf(optarg, "%d", &config->component_value);

			if (count != 1)
			{
				config->component_value = 0;
				puts("The new component value of RGB filter is set to the default value (0).");
			}
			if (config->component_value < 0 || config->component_value > 255)
			{
				config->component_value = 0;
				puts("The new component value of RGB filter is set to the default value (0).");
			}
			break;
		}
        case 's':{
			count = sscanf(optarg, "%d,%d", &config->x1, &config->y1);
			if (count < 2)
			{
				puts("Some values for the coordinates were not read, so their value is set by default.");
			}
			break;
		}
		case 'e':{
			count = sscanf(optarg, "%d,%d", &config->x2, &config->y2);
			if (count < 2)
			{
				puts("Some values for the coordinates were not read, so their value is set by default.");
			}
			break;
		}
		case 'i':{
			config->info_or_help = 1;
			break;
		}
		case 'h':{
			config->info_or_help = 2;
			break;
		}
		default:{
            puts("No such key.");
            break;
		}
    }
}

int main(int argc, char* argv[]){

	IMAGE picture;

	char inputfile_path[100];
    char outfile_path[100];
	
	if(argc < 2){
        puts("The arguments are not enough for the program to work.");
        //help();
        return 0;
    }

	strcpy(inputfile_path, argv[1]);
    strcpy(outfile_path, argv[argc - 1]);

	if(!strcmp(inputfile_path, "-h") || !strcmp(inputfile_path, "--help")){
        //help();
        return 0;
    }

	if(argc < 3){
        puts("The arguments are not enough for the program to work.");
        //help();
        return 0;
    }

	char *opts = "T:S:F:12:l:t:f:c:s:e:ih";

	struct option long_opts[]={
		{"Turn", required_argument, NULL, 'T'},
		{"Square", required_argument, NULL, 'S'},
		{"RGB_Filter", required_argument, NULL, 'F'},
		{"Circle1", no_argument, NULL, '1'},
		{"Circle2", required_argument, NULL, '2'},
		{"line_colors", required_argument, NULL, 'l'},
		{"thick", required_argument, NULL, 't'},
		{"fill", required_argument, NULL, 'f'},
		{"component_value", required_argument, NULL, 'c'},
		{"start", required_argument, NULL, 's'},
		{"end", required_argument, NULL, 'e'},
		{"info", no_argument, NULL, 'i'},
		{"help", no_argument, NULL, 'h'},
		{NULL, no_argument, NULL, 0}
    };

    int opt;
    int long_index;

    opt = getopt_long(argc, argv, opts, long_opts, &long_index);

	Options config = {
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		NULL, 0, 0,
		0, 0, 0, 0
	};

	if(Read_Image(&picture, inputfile_path)) return 0;

	//Read_Image(&picture, "./testfiles/1.bmp");
	//Write_Image(&picture, "./testfile/out.bmp");

	if(opt == -1){
		puts("Incorrect input format.");
		return 0;
	}

	while(opt != -1){
        choice(&config, opt);
        opt = getopt_long(argc, argv, opts, long_opts, &long_index);
    }
	if (config.info_or_help == 1){
		Print_Info(picture);
		Free_Mem(&picture);
		return 0;
	}

	if (config.info_or_help == 2){
		//Help();
		Free_Mem(&picture);
		return 0;
	}
	
	switch (config.action){
		case 1:{
			config.y1 = picture.bmif.height - config.y1 - 1;
			config.y2 = picture.bmif.height - config.y2 - 1;
			Rotate(&picture, &config);
			if(!Write_Image(&picture, outfile_path)){
				puts("The program has finished working.");
			}
			break;
			}
		case 2:{
			config.y1 = picture.bmif.height - config.y1 - 1;
			config.y2 = picture.bmif.height - config.y2 - 1;
			Draw_Square(&picture, config);
			if(!Write_Image(&picture, outfile_path)){
				puts("The program has finished working.");
			}
			break;
			}
		case 3:{
			Filter_RGB(&picture, &config);
			if(!Write_Image(&picture, outfile_path)){
				puts("The program has finished working.");
			}
			break;
			}
		case 4:{
			config.y1 = picture.bmif.height - config.y1 - 1;
			config.y2 = picture.bmif.height - config.y2 - 1;

			if ((config.y1 - config.y2) == (config.x2 - config.x1)){
				config.radius = (int) (config.y1 - config.y2)/2;
				config.y1 = config.y1 - config.radius;
				config.x1 = config.x1 + config.radius;
				Draw_Circle(&picture, config);
			}
			if(!Write_Image(&picture, outfile_path)){
				puts("The program has finished working.");
			}
			break;
			}
		case 5:{
			config.y1 = picture.bmif.height - config.y1 - 1;
			printf("%d - %d\n", config.y1, config.x1);
			Draw_Circle(&picture, config);
			if(!Write_Image(&picture, outfile_path)){
				puts("The program has finished working.");
			}
			break;
			}
		default:
			break;
	}

	return 0;
}
