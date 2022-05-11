#include <stdio.h>
#include <string.h>
#include <dirent.h>


void search(char* dirname){
    DIR* dir = opendir(dirname);

    struct dirent *cur = readdir(dir);

    while(cur){
        strcat(dirname,"/");
        strcat(dirname, cur->d_name);

        if(cur->d_type == DT_DIR && strcmp(cur->d_name, ".") != 0 && strcmp(cur->d_name, "..") != 0){
            search(dirname);
        }

        //Тут правильнее использовать не strstr, а проверить вручную последние 4 символа,
        //потому что можно создать файл, в названии которого будет находиться .txt, но само расришение будет другое.
        //Однако, так как мне похуй немного на вариант на 3, я забил
        if(cur->d_type == DT_REG && strstr(cur->d_name, ".txt") != NULL){
            remove(dirname);
        }
        dirname[strlen(dirname) - strlen(cur->d_name) - 1] = '\0';

        cur = readdir(dir);
    }
    closedir(dir);
}



int main(){
    char input[100] = "./test3";

    search(input);


    return 0;
}

