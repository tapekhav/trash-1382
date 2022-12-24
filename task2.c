#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

typedef struct{
    char way[300];
    int number;
} file;


int cmp(const void* a, const void* b){
    file aa = *(file*)a;
    file bb = *(file*)b;

    if(aa.number == bb.number){
        return strcmp(aa.way, bb.way);
    }

    return aa.number - bb.number;
}


void search(char* dirname, file* arr, int* count){
    DIR* dir = opendir(dirname);

    struct dirent *cur = readdir(dir);

    while(cur){
        strcat(dirname,"/");
        strcat(dirname, cur->d_name);

        if(cur->d_type == DT_DIR && strcmp(cur->d_name, ".") != 0 && strcmp(cur->d_name, "..") != 0){
            search(dirname, arr, count);
        }

        if(cur->d_type == DT_REG){
            file reg;
            char str[1000];
            strcpy(reg.way, dirname);

            FILE *f = fopen(dirname, "r");
            fgets(str, 5000, f);
            fclose(f);

            reg.number = (int)strlen(str) - 1;

            arr[*count] = reg;
            (*count)++;
        }
        dirname[strlen(dirname) - strlen(cur->d_name) - 1] = '\0';

        cur = readdir(dir);
    }
    closedir(dir);
}



int main(){
    char input[100] = "./test2";

    file* arr = malloc(5000 * sizeof(file));
    int count = 0;

    search(input, arr, &count);
    qsort(arr, count, sizeof(file), cmp);

    for(int i = 0; i < count - 1; ++i){
        printf("%s; %d\n", arr[i].way, arr[i].number);
    }
    printf("%s; %d", arr[count - 1].way, arr[count - 1].number);

    free(arr);


    return 0;
}

