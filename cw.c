#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <png.h>

#define PNG_DEBUG 3

#include <string.h>
#include <getopt.h>


struct Png {
    int width, height;
    png_byte color_type;
    png_byte bit_depth;

    png_structp png_ptr;
    png_infop info_ptr;
    int number_of_passes;
    png_bytep *row_pointers;
};

struct Configs {
    int x1, y1;
    int x2, y2;
    int x3, y3;
    int line_fat;
    int line_color_r, line_color_g, line_color_b;
    int paint_color_r, paint_color_g, paint_color_b;
    int is_pour;
    int xPhoto, yPhoto;
    char *output;
};


void printHelp() {
    printf("Это программа с CLI для редактирования png файлов\n");
    printf("Формат ввода: ./a.out [имя исходного файла] [функция] "
           "-[ключ1]/--[полный ключ1] [аргумент1] ...\n\n");
    printf("Функции/ключи:\n");
    printf("triangle [имя файла] - рисование треугольника с возможностью его залить и "
           "выбрать "
           "цвет.\n");
    printf("    -f/--first  [<x-координата>.<y-координата>] - первая вершина треугольника\n");
    printf("    -s/--second  [<x-координата>.<y-координата>] - вторая вершина треугольника\n");
    printf("    -t/--third [<x-координата>.<y-координата>] - третья вершина треугольника\n");
    printf("    -l/--lineFat [<число>] - толщина сторон треугольника(в пикселях)\n");
    printf("    -r/--range [<число>.<число>.<число>] - цвет сторон треугольника (RGB)\n");
    printf("    -C/--color [<число>.<число>.<число>] - цвет заливки треугольника (RGB)\n");
    printf("    -с/--cast - заливка треугольника (по умолчанию без заливки)\n");
    printf("line [имя файла] - рисование прямой линии.\n");
    printf("    -f/--first  [<x-координата>.<y-координата>] - начало линии\n");
    printf("    -s/--second  [<x-координата>.<y-координата>] - конец линии\n");
    printf("    -l/--lineFat [<число>] - толщина линии(в пикселях)\n");
    printf("    -C/--color [<число>.<число>.<число>] - цвет линии (RGB)\n");
    printf("collage [имя файла] - создается коллаж из изображения.\n");
    printf("    -x/--xPhoto  [<число>] - количество изображений по оси X\n");
    printf("    -y/--yPhoto  [<число>] - количество изображений по оси Y\n");
    printf("rectangle [имя файла] - поиск самого большого прямоугольника заданного цвета и его "
           "перекраска в заданный цвет.\n");
    printf("    -C/--color [<число>.<число>.<число>] - цвет перекраски (RGB)\n");
    printf("    -r/--range [<число>.<число>.<число>] - цвет искомого прямоугольника (RGB)\n");
    printf("-h/--help - вывод справки о работе программы.\n");
    printf("-o/--output [путь] - файл для вывода (по умолчанию исходный файл)\n");
}


void read_png_file(char *file_name, struct Png *image) {
    int x, y;
    char header[8];    // 8 is the maximum size that can be checked

    /* open file and test for it being a png */
    FILE *fp = fopen(file_name, "rb");
    if (!fp) {
        // Some error handling: file could not be opened
        printf("Ошибка открытия файла на чтение!\n");
    }

    fread(header, 1, 8, fp);
    if (png_sig_cmp(header, 0, 8)) {
        printf("Это не PNG файл!\n");
        exit(-1);
    }

    /* initialize stuff */
    image->png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

    if (!image->png_ptr) {
        printf("png_create_read_struct failed\n");
        exit(-1);
    }

    image->info_ptr = png_create_info_struct(image->png_ptr);
    if (!image->info_ptr) {
        printf("png_create_read_struct failed\n");
        exit(-1);
    }

    if (setjmp(png_jmpbuf(image->png_ptr))) {
        printf("error during init_io\n");
        exit(-1);
    }

    png_init_io(image->png_ptr, fp);
    png_set_sig_bytes(image->png_ptr, 8);

    png_read_info(image->png_ptr, image->info_ptr);

    image->width = png_get_image_width(image->png_ptr, image->info_ptr);
    image->height = png_get_image_height(image->png_ptr, image->info_ptr);
    image->color_type = png_get_color_type(image->png_ptr, image->info_ptr);
    image->bit_depth = png_get_bit_depth(image->png_ptr, image->info_ptr);

    image->number_of_passes = png_set_interlace_handling(image->png_ptr);
    png_read_update_info(image->png_ptr, image->info_ptr);

    /* read file */
    if (setjmp(png_jmpbuf(image->png_ptr))) {
        // Some error handling: error during read_image
        printf("error during read_image\n");
        exit(-1);
    }

    image->row_pointers = (png_bytep *) malloc(sizeof(png_bytep) * image->height);
    for (y = 0; y < image->height; y++)
        image->row_pointers[y] = (png_byte *) malloc(
                png_get_rowbytes(image->png_ptr, image->info_ptr));

    png_read_image(image->png_ptr, image->row_pointers);

    fclose(fp);
}


void write_png_file(char *file_name, struct Png *image) {
    int x, y;
    FILE *fp = fopen(file_name, "wb");

    if (!fp) {
        printf("Ошибка открытия результирующего файла!\n");
        exit(-1);
    }

    /* initialize stuff */
    image->png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

    if (!image->png_ptr) {
        printf("png_create_write_struct failed\n");
        exit(-1);
    }

    image->info_ptr = png_create_info_struct(image->png_ptr);
    if (!image->info_ptr) {
        // Some error handling: png_create_info_struct failed
        printf("png_create_info_struct failed\n");
        exit(-1);
    }

    if (setjmp(png_jmpbuf(image->png_ptr))) {
        printf("error during init_io\n");
        exit(-1);
    }

    png_init_io(image->png_ptr, fp);


    /* write header */
    if (setjmp(png_jmpbuf(image->png_ptr))) {
        // Some error handling: error during writing header
        printf("error during writing header\n");
        exit(-1);
    }

    png_set_IHDR(image->png_ptr, image->info_ptr, image->width, image->height,
                 image->bit_depth, image->color_type, PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

    png_write_info(image->png_ptr, image->info_ptr);


    /* write bytes */
    if (setjmp(png_jmpbuf(image->png_ptr))) {
        printf("Ошибка чтения байтов!\n");
        exit(-1);
    }

    png_write_image(image->png_ptr, image->row_pointers);


    /* end write */
    if (setjmp(png_jmpbuf(image->png_ptr))) {
        printf("error during end of write\n");
    }

    png_write_end(image->png_ptr, NULL);

    /* cleanup heap allocation */
    for (y = 0; y < image->height; y++)
        free(image->row_pointers[y]);
    free(image->row_pointers);

    fclose(fp);
}

// Рисование круга(для толщины линии)
void draw_Circle(struct Png *image, int x0, int y0, int line_fat, int width_pixel, int Red, int
Green,
                 int Blue) {
    int x = 0;
    int radius = line_fat / 2;
    int y = radius;
    int start = y0 - radius;
    int end = y0 + radius;
    int delta = 1 - 2 * radius;
    int error;
    while (y >= 0) {
        png_byte *row = image->row_pointers[y0 + y];
        png_byte *ptr = &(row[(x0 + x) * width_pixel]);
        ptr[0] = Red;
        ptr[1] = Green;
        ptr[2] = Blue;

        png_byte *row1 = image->row_pointers[y0 - y];
        png_byte *ptr1 = &(row1[(x0 + x) * width_pixel]);
        ptr1[0] = Red;
        ptr1[1] = Green;
        ptr1[2] = Blue;

        png_byte *row2 = image->row_pointers[y0 + y];
        png_byte *ptr2 = &(row2[(x0 - x) * width_pixel]);
        ptr2[0] = Red;
        ptr2[1] = Green;
        ptr2[2] = Blue;

        png_byte *row3 = image->row_pointers[y0 - y];
        png_byte *ptr3 = &(row3[(x0 - x) * width_pixel]);
        ptr3[0] = Red;
        ptr3[1] = Green;
        ptr3[2] = Blue;
        error = 2 * (delta + y) - 1;
        while (start <= y0) {
            for (int i = abs(x - x0); i < (x + x0); i++) {
                png_byte *row4 = image->row_pointers[start];
                png_byte *ptr4 = &(row4[i * width_pixel]);
                ptr4[0] = Red;
                ptr4[1] = Green;
                ptr4[2] = Blue;

                png_byte *row5 = image->row_pointers[end];
                png_byte *ptr5 = &(row5[i * width_pixel]);
                ptr5[0] = Red;
                ptr5[1] = Green;
                ptr5[2] = Blue;
            }
            if (error > 0) {
                start++;
                end--;
            }
            break;
        }
        if (delta < 0 && error <= 0) {
            ++x;
            delta += 2 * x + 1;
            continue;
        }
        error = 2 * (delta - x) - 1;
        if (delta > 0 && error > 0) {
            --y;
            delta += 1 - 2 * y;
            continue;
        }
        ++x;
        delta += 2 * (x - y);
        --y;
    }
}

void paint_line(struct Png *image, int width_pixel, int x0, int y0, int x1, int y1, int line_fat,
                int Red, int Green, int Blue) {
    int A, B, sign;
    A = y1 - y0;
    B = x0 - x1;
    if (abs(A) > abs(B)) sign = 1;
    else sign = -1;
    int signa, signb;
    if (A < 0) signa = -1;
    else signa = 1;
    if (B < 0) signb = -1;
    else signb = 1;
    int f = 0;
    png_byte *row = image->row_pointers[y0];
    png_byte *ptr = &(row[x0 * width_pixel]);
    ptr[0] = Red;
    ptr[1] = Green;
    ptr[2] = Blue;
    draw_Circle(image, x0, y0, line_fat, width_pixel, Red, Green, Blue);
    int x = x0, y = y0;
    if (sign == -1) {
        do {
            f += A * signa;
            if (f > 0) {
                f -= B * signb;
                y += signa;
            }
            x -= signb;
            png_byte *row = image->row_pointers[y];
            png_byte *ptr = &(row[x * width_pixel]);
            ptr[0] = Red;
            ptr[1] = Green;
            ptr[2] = Blue;
            draw_Circle(image, x, y, line_fat, width_pixel, Red, Green, Blue);
        } while (x != x1 || y != y1);
    } else {
        do {
            f += B * signb;
            if (f > 0) {
                f -= A * signa;
                x -= signb;
            }
            y += signa;
            png_byte *row = image->row_pointers[y];
            png_byte *ptr = &(row[x * width_pixel]);
            ptr[0] = Red;
            ptr[1] = Green;
            ptr[2] = Blue;
            draw_Circle(image, x, y, line_fat, width_pixel, Red, Green, Blue);
        } while (x != x1 || y != y1);
    }
}

// проверка, находится ли текущий пиксель внутри треугольника
int is_inside(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
    int one = (x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0);
    int two = (x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0);
    int three = (x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0);
    if ((one < 0 && two < 0 && three < 0) || (one > 0 && two > 0 && three > 0)) {
        return 1;
    }
    return 0;
}

//проверка, покрашен ли уже пиксель при заливке треугольника (внутри и на линии)
int is_not_painted(struct Png *image, int width_pixel, int x, int y, int Red_p, int Green_p, int
Blue_p, int Red_l, int Green_l, int Blue_l) {
    png_byte *row = image->row_pointers[y];
    png_byte *ptr = &(row[x * width_pixel]);
    int one = (ptr[0] == Red_p) && (ptr[1] == Green_p) && (ptr[2] == Blue_p);
    int two = (ptr[0] == Red_l) && (ptr[1] == Green_l) && (ptr[2] == Blue_l);
    if (one || two) {
        return 0;
    }
    return 1;
}

// рекурсивная заливка треугольника
void pouring_triangle(struct Png *image, int width_pixel, int x_c, int y_c, int x1, int y1, int x2,
                      int y2,
                      int x3, int y3, int Red, int Green, int Blue, int Red_l, int Green_l,
                      int Blue_l) {
    if (is_inside(x_c, y_c, x1, y1, x2, y2, x3, y3) && is_not_painted(image, width_pixel, x_c,
                                                                      y_c, Red, Green, Blue, Red_l,
                                                                      Green_l, Blue_l)) {
        png_byte *row = image->row_pointers[y_c];
        png_byte *ptr = &(row[x_c * width_pixel]);
        ptr[0] = Red;
        ptr[1] = Green;
        ptr[2] = Blue;
        pouring_triangle(image, width_pixel, x_c + 1, y_c, x1, y1, x2, y2, x3, y3, Red, Green, Blue,
                         Red_l,
                         Green_l, Blue_l);
        pouring_triangle(image, width_pixel, x_c, y_c + 1, x1, y1, x2, y2, x3, y3, Red, Green, Blue,
                         Red_l,
                         Green_l, Blue_l);
        pouring_triangle(image, width_pixel, x_c - 1, y_c, x1, y1, x2, y2, x3, y3, Red, Green, Blue,
                         Red_l,
                         Green_l, Blue_l);
        pouring_triangle(image, width_pixel, x_c, y_c - 1, x1, y1, x2, y2, x3, y3, Red, Green, Blue,
                         Red_l,
                         Green_l, Blue_l);
    }
}


void draw_triangle(struct Png *image, int width_pixel, int x1, int y1, int x2, int y2, int x3, int
y3, int line_fat, int is_pour, int Red_l, int Green_l, int Blue_l, int Red_p, int Green_p,
                   int Blue_p) {
    paint_line(image, width_pixel, x1, y1, x2, y2, line_fat, Red_l, Green_l, Blue_l);
    paint_line(image, width_pixel, x2, y2, x3, y3, line_fat, Red_l, Green_l, Blue_l);
    paint_line(image, width_pixel, x3, y3, x1, y1, line_fat, Red_l, Green_l, Blue_l);
    if (is_pour) {
        int x_c = (x1 + x2 + x3) / 3;
        int y_c = (y1 + y2 + y3) / 3;
        pouring_triangle(image, width_pixel, x_c, y_c, x1, y1, x2, y2, x3, y3, Red_p, Green_p,
                         Blue_p, Red_l,
                         Green_l, Blue_l);
    }
}

// перенос пикселя при создании коллажа
void replace(png_byte *new_pixel, png_byte *old_pixel, int width_pixel) {
    for (int i = 0; i < width_pixel; i++) {
        new_pixel[i] = old_pixel[i];
    }
}

void make_collage(struct Png *image, int width_pixel, int x_photos, int y_photos) {
    int new_width = image->width * x_photos;
    int new_height = image->height * y_photos;

    png_byte **new_mas = (png_byte **) malloc(sizeof(png_byte * ) * new_height);
    for (int y = 0; y < new_height; y++)
        new_mas[y] = (png_byte *) malloc(sizeof(png_byte) * new_width * width_pixel);
    for (int y = 0; y < new_height; y++) {
        int old_y = y % image->height;
        png_byte *old_row = image->row_pointers[old_y];
        png_byte *new_row = new_mas[y];
        for (int x = 0; x < new_width; x++) {
            int old_x = x % image->width;
            png_byte *old_pixel = &(old_row[old_x * width_pixel]);
            png_byte *new_pixel = &(new_row[x * width_pixel]);
            replace(new_pixel, old_pixel, width_pixel);
        }
    }
    for (int x = 0; x < image->height; x++) {
        free(image->row_pointers[x]);
    }
    free(image->row_pointers);

    image->row_pointers = new_mas;
    image->width = new_width;
    image->height = new_height;
}

int check_X_Y(struct Png *image, int x0, int y0, int *x1, int *y1, int *x2, int *y2, int *x3, int
*y3, int *x4, int *y4, int width_pixel, int red0, int green0, int blue0) {
    int x1t = 0, y1t = 0, x2t = 0, y2t = 0, x3t = 0, y3t = 0, x4t = 0, y4t = 0;
    int flag = 0;
    png_byte *row = image->row_pointers[y0];
    for (int x = x0; x < image->width; x++) {
        png_byte *ptr = &(row[x * width_pixel]);
        if (ptr[0] == red0 && ptr[1] == green0 && ptr[2] == blue0) {
            if (flag == 0) {
                x1t = x, y1t = y0;
                flag++;
            }
        } else {
            if (x != (x0 + 1)) {
                x2t = x - 1, y2t = y0;
                flag++;
                break;
            } else {
                return 0;
            }
        }
    }
    for (int y = y0; y < image->height; y++) {
        png_byte *row = image->row_pointers[y];
        png_byte *ptr = &(row[x0 * width_pixel]);
        if (ptr[0] != red0 || ptr[1] != green0 || ptr[2] != blue0) {
            if (y != (y0 + 1) && flag == 2) {
                y3t = y - 1, x3t = x0;
                flag++;
            }
        }
    }
    for (int y = y0; y < image->height; y++) {
        png_byte *row = image->row_pointers[y];
        png_byte *ptr = &(row[x1t * width_pixel]);
        if (ptr[0] != red0 || ptr[1] != green0 || ptr[2] != blue0) {
            if (y != (y0 + 1) && flag == 3) {
                y4t = y - 1, x4t = x2t;
                flag++;
            }
        }
    }
    if (y4t != y3t)
        return 0;
    row = image->row_pointers[y3t];

    for (int x = x3t; x < x4t; x++) {
        png_byte *ptr = &(row[x * width_pixel]);
        if (ptr[0] != red0 || ptr[1] != green0 || ptr[2] != blue0) {
            return 0;
        }
    }
    *x1 = x1t, *y1 = y1t;
    *x2 = x2t, *y2 = y2t;
    *x3 = x3t, *y3 = y3t;
    *x4 = x4t, *y4 = y4t;
    return 1;

}

//перекраска прямоугольника
void pouring_rectangle(struct Png *image, int width_pixel, int x, int y, int Red, int Green, int
Blue, int Red_l, int Green_l, int Blue_l) {
    if (!is_not_painted(image, width_pixel, x, y, Red, Green, Blue, Red, Green, Blue)) {
        png_byte *row = image->row_pointers[y];
        png_byte *ptr = &(row[x * width_pixel]);
        ptr[0] = Red_l;
        ptr[1] = Green_l;
        ptr[2] = Blue_l;
        pouring_rectangle(image, width_pixel, x + 1, y, Red, Green, Blue, Red_l, Green_l, Blue_l);
        pouring_rectangle(image, width_pixel, x - 1, y, Red, Green, Blue, Red_l, Green_l, Blue_l);
        pouring_rectangle(image, width_pixel, x, y + 1, Red, Green, Blue, Red_l, Green_l, Blue_l);
        pouring_rectangle(image, width_pixel, x, y - 1, Red, Green, Blue, Red_l, Green_l, Blue_l);
    }
}

// поиск прямоугольника макс площади
int is_rectangle(struct Png *image, int width_pixel, int red0, int green0, int blue0, int red1, int
green1, int blue1) {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    int square, square_max = 0;
    int x1_max, y1_max, x2_max, y2_max, x3_max, y3_max, x4_max, y4_max;
    for (int y = 0; y < image->height; y++) {
        png_byte *row = image->row_pointers[y];
        for (int x = 0; x < image->width; x++) {
            png_byte *ptr = &(row[x * width_pixel]);
            if (ptr[0] == red0 && ptr[1] == green0 && ptr[2] == blue0) {
                if (check_X_Y(image, x, y, &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4,
                              width_pixel, red0, green0, blue0)) {
                    int square = sqrt((x2 - x1) * (x2 - x1)) * sqrt((y3 - y1) * (y3 - y1));
                    if (square > square_max) {
                        square_max = square;
                        x1_max = x1, y1_max = y1, x2_max = x2, y2_max = y2, x3_max = x3, y3_max =
                                y3, x4_max = x4, y4_max = y4;
                    }
                }
            }
        }
    }
    pouring_rectangle(image, width_pixel, x1_max, y1_max, red0, green0, blue0, red1, green1, blue1);
    return 0;
}

// расстановка конфигураций, переданных через флаги в getopt
void cfg(int **arr, int kl, char *opt) {
    char *str1;
    str1 = strtok(opt, ".");
    *(arr[0]) = atoi(str1);
    for (int i = 1; i < kl; i++) {
        str1 = strtok(NULL, ".");
        *(arr[i]) = atoi(str1);
    }
}


void choice(struct Configs *config, int opt) {
    char *str1;
    int **arr = malloc(3 * sizeof(int *));
    switch (opt) {
        case 'r':
            arr[0] = &(config->line_color_r), arr[1] = &(config->line_color_g), arr[2] = &
                    (config->line_color_b);
            cfg(arr, 3, optarg);
            break;
        case 'f':
            arr[0] = &(config->x1), arr[1] = &(config->y1);
            cfg(arr, 2, optarg);
            break;
        case 's':
            arr[0] = &(config->x2), arr[1] = &(config->y2);
            cfg(arr, 2, optarg);
            break;
        case 't':
            arr[0] = &(config->x3), arr[1] = &(config->y3);
            cfg(arr, 2, optarg);
            break;
        case 'l':
            config->line_fat = atoi(optarg);
            break;
        case 'C':
            arr[0] = &(config->paint_color_r), arr[1] = &(config->paint_color_g), arr[2] = &
                    (config->paint_color_b);
            cfg(arr, 3, optarg);
            break;
        case 'c':
            config->is_pour = 1;
            break;
        case 'x':
            config->xPhoto = atoi(optarg);
            break;
        case 'y':
            config->yPhoto = atoi(optarg);
            break;
        case 'o':
            config->output = optarg;
            break;
        case 'h':
            printHelp();
            exit(-1);
            break;
    }
}

int main(int argc, char **argv) {

    char *opts = "f:s:t:l:C:cx:y:o:hr:";
    char *output = argv[1];
    struct Configs config = {0, 0, 0, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 0, 0,
                             0, 0, output};
    struct Png image;
    char *func = argv[2];
    char *file = argv[1];
    struct option longOpts[] = {
            {"first",   required_argument, NULL, 'f'},
            {"second",  required_argument, NULL, 's'},
            {"third",   required_argument, NULL, 't'},
            {"lineFat", required_argument, NULL, 'l'},
            {"color",   required_argument, NULL, 'C'},
            {"cast",    no_argument,       NULL, 'c'},
            {"xPhoto",  required_argument, NULL, 'x'},
            {"yPhoto",  required_argument, NULL, 'y'},
            {"output",  required_argument, NULL, 'o'},
            {"help",    no_argument,       NULL, 'h'},
            {"range",   required_argument, NULL, 'r'},
    };
    int opt;
    int longIndex;
    opt = getopt_long(argc, argv, opts, longOpts, &longIndex);
    while (opt != -1) {
        choice(&config, opt);
        opt = getopt_long(argc, argv, opts, longOpts, &longIndex);
    }
    read_png_file(file, &image);
    if (!strcmp(func, "triangle")) {
        draw_triangle(&image, 3, config.x1, config.y1, config.x2, config.y2, config.x3,
                      config.y3, config.line_fat, config.is_pour, config.line_color_r,
                      config.line_color_g,
                      config.line_color_b, config.paint_color_r, config.paint_color_g,
                      config.paint_color_b);
    }
    if (!strcmp(func, "line")) {
        paint_line(&image, 3, config.x1, config.y1, config.x2, config.y2, config.line_fat,
                   config.paint_color_r, config.paint_color_g, config.paint_color_b);
    }
    if (!strcmp(func, "collage")) {
        make_collage(&image, 3, config.xPhoto, config.yPhoto);
    }
    if (!strcmp(func, "rectangle")) {
        is_rectangle(&image, 3, config.line_color_r, config.line_color_g, config
                .line_color_b, config.paint_color_r, config.paint_color_g, config.paint_color_b);
    }

    write_png_file(config.output, &image);
    return 0;
}