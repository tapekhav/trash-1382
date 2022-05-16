BMP catPictures(BMP* image1, BMP* image2){
    BMP res;

    res.header = image1->header;

    if(image1->info.height > image2->info.height){
        res.info = image1->info;
    } else {
        res.info = image2->info;
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

    if(image1->info.height != res.info.height) {
        int diff = (int)res.info.height - (int)image1->info.height;
        for (int i = 0; i < image1->info.height; i++) {
            for (int j = 0; j < image1->info.width; j++) {
                res.pixels[diff + i][j] = image1->pixels[i][j];
            }
        }
    } else {
        for (int i = 0; i < image1->info.height; i++) {
            for (int j = 0; j < image1->info.width; j++) {
                res.pixels[i][j] = image1->pixels[i][j];
            }
        }
    }

    if(image2->info.height == res.info.height) {
        for (int i = 0; i < image2->info.height; i++) {
            for (int j = 0; j < image2->info.width; j++) {
                res.pixels[i][image1->info.width + j] = image2->pixels[i][j];
            }
        }
    } else {
        int diff = (int)res.info.height - (int)image2->info.height;
        for (int i = 0; i < image2->info.height; i++) {
            for (int j = 0; j < image2->info.width; j++) {
                res.pixels[diff + i][image1->info.width + j] = image2->pixels[i][j];
            }
        }
    }

    return res;
}
