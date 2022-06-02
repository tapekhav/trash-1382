#include "headers.h"
#include "structs.h"

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

void Help(){
	puts("");
	puts("This program supports CLI and only works with version 3 BMP files.");
	puts("BMP files with color table are not supported.");
	puts("The program only supports files with a depth of 24 pixels per bit.");
	puts("The program does not work with compressed photos.");
	puts("If the required key to perform the function has not been entered, then the standard key values are 0.");
	puts("The default value for the argument of the RGB_Filter(-F) function is 'r'.");
	puts("If incorrect values are entered for the arguments, their value will be set to default.");
	puts("Input format:");
	puts("\t./a.out [input file] [key of function] [arguments if needed] [key 1] [argument 1],...,[argument N] ... [output file]");
	puts("Functions and their keys:");
	puts("\t--Turn (-T) <angle> - The function of rotating part of the image (the whole image).");
	puts("\t\tThis function needs --start(-s), --end(-e) keys.");
	puts("\t--Square(-S) <side> - The function of drawing a square.");
	puts("\t\tThis function needs --start(-s), --thick(-t), --line_colors(-l), --fill(-f) keys.");
	puts("\t--RGB_Filter(-F) <short name of component> - Changes the value of one of the components throughout the photo.");
	puts("\t\tThis function needs --component_value(-c) key.");
	puts("\t--Circle1(-1) - Draws a circle based on the coordinates of the upper-left corner and the lower-right corner of the square.");
	puts("\t\tThis function needs --start(-s), --end(-e), --thick(-t), --line_colors(-l), --fill(-f) keys.");
	puts("\t--Circle2(-2) <radius> - Draws a circle based on the coordinates of the center of the circle and its radius.");
	puts("\t\tThis function needs --start(-s), --thick(-t), --line_colors(-l), --fill(-f) keys.");
	puts("All keys:");
	puts("\t--start(-s) <x1,y1> - Used to set the coordinates of the center of the circle or the upper-left corner of the area.");
	puts("\t--end(-e) <x2,y2> - Used to set the coordinates of the bottom-right corner of the area.");
	puts("\t--thick(-t) <thickness value> - Set the thickness of the lines.");
	puts("\t--line_colors(-l) <r,g,b> - Three integer values for the line color.");
	puts("\t--fill(-f) <r,g,b> - Three integer values for the fill.");
	puts("\t--component_value(-c) <component value> - Integer value of the color component.");
	puts("\t--info(-i) - Prints information about the file.");
	puts("\t--help(-h) - Prints this help.");
	puts("Examples:");
	puts("\t./editor ./testfiles/alex.bmp -F r -c 255 ./outfiles/out.bmp");
	puts("\t./editor ./testfiles/simpsonsvr.bmp -2 100 -s 200,200 -t 1 -l 255,0,0 -f 0,0,0 ./outfiles/out.bmp");
	puts("\t./editor ./testfiles/landscape.bmp -S 1000 -s 200,200 -t 1 -l 255,0,0 -f 0,0,0 ./outfiles/out.bmp");
	puts("\t./editor ./testfiles/landscape.bmp -T 270 -s -10,-10 -e 10000, 10000 ./outfiles/out.bmp");
	puts("WARNING!!!!");
	puts("The program does not guarantee correct operation if the user does not adhere to the help.");
	printf("\n");
}