#include "headers.h"
#include "structs.h"

#include "Read_Write.h"
#include "Draw_Funcs.h"
#include "RGB_Filter.h"
#include "Turn_Funcs.h"
#include "Help_Info.h"

void choice(Options* config, const char option){
	int count = -1;
    switch (option) {
        case 'T':{
            count = sscanf(optarg, "%d", &config->angle);
            if(count != 1){ puts("The angle remained at the default value (0).");}
			if(config->angle < 0) {config->angle = 0; puts("The negative angle is set to 0.");}
			config->action = 1;
            break;
		}
		case 'S':{
            count = sscanf(optarg, "%d", &config->side);
            if(count != 1){ puts("The side of square remained at the default value (0).");}
			if(config->side < 0) {config->side = 0; puts("The negative side is set to 0.");}
			config->action = 2;
            break;
		}
		case 'F':{
			config->component = malloc(20 * sizeof(char));
            count = sscanf(optarg, "%s", config->component);
            if(count != 1){
				puts("The component remained at the default value r (Red).");
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
			if(config->radius < 0) {
				config->radius = 0;
				puts("The negative radius is replaced by 0.");
				}
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
        Help();
        return 0;
    }

	strcpy(inputfile_path, argv[1]);
    strcpy(outfile_path, argv[argc - 1]);

	if(!strcmp(inputfile_path, "-h") || !strcmp(inputfile_path, "--help")){
		Help();
        return 0;
    }

	if(argc < 3){
        puts("The arguments are not enough for the program to work.");
        Help();
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
		Help();
		Free_Mem(&picture);
		return 0;
	}
	
	switch (config.action){
		case 1:{
			config.y1 = picture.bmif.height - config.y1 - 1;
			config.y2 = picture.bmif.height - config.y2 - 1;
			Turn(&picture, &config);
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