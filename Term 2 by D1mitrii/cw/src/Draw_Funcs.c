#include "headers.h"
#include "structs.h"

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

void Draw_Square(IMAGE* picture, Options opt){
	int side = opt.side;
	
	int x1 = opt.x1;
	int y1 = opt.y1;
	int thick = opt.thick;

	printf("%d-%d-%d\n", opt.f_r, opt.f_g, opt.f_b);
	printf("%d-%d\n", opt.y1, opt.x1);
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

	}

}

void Draw_Circle(IMAGE* picture, Options opt){

	int y1 = opt.y1;
	int x1 = opt.x1;
	int radius = opt.radius;
	if (opt.fill){
    for(int i = y1 - radius - 1; i < y1 + radius + 1; i++){
		for(int j = x1 - radius - 1; j < x1 + radius + 1; j++){
			if((j - x1)*(j - x1) + (i - y1)*(i - y1) < (radius)*(radius)){
					Write_Pixel(picture, j, i, opt.f_r, opt.f_g, opt.f_b);
				}
			}
		}
	}

	for(int i = y1 - radius - opt.thick; i < y1 + radius + opt.thick; i++){
		for(int j = x1 - radius - opt.thick; j < x1 + radius + opt.thick; j++){
			if(((j - x1)*(j - x1) + (i - y1)*(i - y1) >= (radius) * (radius)) && ((j - x1)*(j - x1) + (i - y1)*(i - y1) < (radius + opt.thick)*(radius + opt.thick))){
				Write_Pixel(picture, j, i, opt.l_r, opt.l_g, opt.l_b);
			}	
		}
	}
}
