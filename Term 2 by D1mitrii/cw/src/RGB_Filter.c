#include "headers.h"
#include "structs.h"

void Filter_RGB(IMAGE* picture, Options* opt){
	if(opt->component != NULL && strstr("rgb", opt->component) && (opt->component_value >= 0) && (opt->component_value <= 255)){
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
		puts("Inncorrect component name");
	}
}
