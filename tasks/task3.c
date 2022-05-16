BMP catColumns(BMP* image1, BMP* image2){
    BMP res;
    res.header = image1->header;
    BMP min_image;
    BMP max_image;

    if(image1->info.height > image2->info.height){
        res.info = image1->info;
        min_image = *image2;
        max_image = *image1;
    } else {
        res.info = image2->info;
        min_image = *image1;
        max_image = *image2;
    }

    res.info.width = image1->info.width + image2->info.width;

    res.pixels = malloc(res.info.height * sizeof(RGB*));

    for(int i = 0; i < res.info.height; ++i){
        res.pixels[i] = malloc(res.info.width * sizeof(RGB));
    }

    for(int i = 0; i < res.info.height; i++){
        for(int j = 0; j < res.info.width; j++){
            res.pixels[i][j].r = 255;
            res.pixels[i][j].g = 255;
            res.pixels[i][j].b = 255;
        }
    }


    int diff = (int)max_image.info.height - (int)min_image.info.height;


    for(int i = 0; i < max_image.info.height; i++) {
        int x = 0;
        int y = 0;
        while ((x + y) < res.info.width) {

            if(x < min_image.info.width) {
                if (i < min_image.info.height) {
                    res.pixels[diff + i][x + y] = min_image.pixels[i][x];
                }
                x++;
            }

            if(i < max_image.info.height) {
                if (y < max_image.info.width) {
                    res.pixels[i][x + y] = max_image.pixels[i][y];
                    y++;
                }
            }
        }
    }


    return res;
}
