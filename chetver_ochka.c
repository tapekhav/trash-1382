#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>


int cmp(const void* a, const void* b){
    char* aa = *(char**)a;
    char* bb = *(char**)b;


    return strcmp(aa, bb);
}


void search(char* dirname, char** arr, int* count){
    DIR* dir = opendir(dirname);

    struct dirent *cur = readdir(dir);

    while(cur){
        strcat(dirname,"/");
        strcat(dirname, cur->d_name);

        if(cur->d_type == DT_DIR && strcmp(cur->d_name, ".") != 0 && strcmp(cur->d_name, "..") != 0){
            search(dirname, arr, count);
        }

        if(cur->d_type == DT_REG){
            char* str = malloc(300);

            FILE *f = fopen(dirname, "r");
            fgets(str, 5000, f);
            str[strlen(str) - 1] = '\0';
            fclose(f);

            arr[*count] = str;
            (*count)++;
        }
        dirname[strlen(dirname) - strlen(cur->d_name) - 1] = '\0';

        cur = readdir(dir);
    }
    closedir(dir);
}



int main(){
    char input[100] = "./test2";
    char out[100] = "./result.txt";

    char** arr = malloc(5000*sizeof(char*));
    int count = 0;

    search(input, arr, &count);
    qsort(arr, count, sizeof(char*), cmp);

    FILE* file = fopen(out, "wb");

    for(int i = 0; i < count - 1; ++i){
        fprintf(file, "%s\n", arr[i]);
    }
    fprintf(file, "%s", arr[count - 1]);

    for(int i = 0; i < count; ++i){
        free(arr[i]);
    }
    free(arr);

    fclose(file);


    return 0;
}

