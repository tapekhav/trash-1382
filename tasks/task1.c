void func(BMP *image, int x_left, int y_top, int x_right, int y_bottom){
    BMP newImage;

    newImage.info.height = y_bottom - y_top;
    newImage.info.width = x_right - x_left;

    newImage.pixels = malloc(newImage.info.height * sizeof(RGB*));

    for(int i = 0; i < newImage.info.height; ++i){
        newImage.pixels[i] = malloc(newImage.info.width * sizeof(RGB));
    }

    unsigned int x;
    unsigned int y = 0;


    reflectArea(image, "horizontal", 0, 0, (int)image->info.width - 1, (int)image->info.height - 1);
    for(unsigned int i = y_top; i < y_bottom; ++i){
        x = 0;
        for(unsigned int j = x_left; j < x_right; ++j){
            newImage.pixels[y][x] = image->pixels[i][j];
            ++x;
        }
        ++y;
    }

    for(int i = 0; i < image->info.height; i++){
        for(int j = 0; j < image->info.width; j++){
            image->pixels[i][j] = newImage.pixels[i % newImage.info.height][j % newImage.info.width];
        }
    }

    reflectArea(image, "horizontal", 0, 0, (int)image->info.width - 1, (int)image->info.height - 1);


    freeMem(&newImage);
}
