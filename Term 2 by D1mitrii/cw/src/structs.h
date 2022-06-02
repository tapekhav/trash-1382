#pragma once
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
	RGB** canvas;

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