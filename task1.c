#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>


typedef struct
{
    char name[300];
    char info[5000];
} file;

void search(char* dirname, file** arr, int* count)
{
    DIR* dir = opendir(dirname);
    struct dirent* cur = readdir(dir);

    while(cur){
        strcat(dirname, "/");
        strcat(dirname, cur->d_name);

        if(cur->d_type == DT_DIR && strcmp(cur->d_name, ".") != 0 && strcmp(cur->d_name, "..") != 0){
            search(dirname, arr, count);
        }

        if(cur->d_type == DT_REG){
            file* reg = malloc(sizeof(file));

            strcpy(reg->name, cur->d_name);

            FILE* f = fopen(dirname, "r");
            fgets(reg->info, 5000, f);
            fclose(f);

            arr[(*count)++] = reg;
        }


        dirname[strlen(dirname) - strlen(cur->d_name) - 1] = '\0';
        cur = readdir(dir);
    }

    closedir(dir);
}

int main(){
    char input[300] = "./tests";
    file** arr = malloc(5000 * sizeof(file*));
    int count = 0;

    search(input, arr, &count);

    int max = 0;
    file* res;

    for(int j = 0; j < count; j++) {
        int k = 0;
        file* f = arr[j];
        for (int i = 0; i < count; i++) {
            if(!strcmp(f->name, arr[i]->name) && !strcmp(f->info, arr[i]->info)){
                k++;
            }
        }

        if(k > max){
            max = k;
            res = f;
        }
    }


    printf("%d; %s\n", max, res->name);

    for(int i = 0; i < 5000; i++){
        free(arr[i]);
    }
    free(arr);


    return 0;
}
