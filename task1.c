#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

typedef struct{
    char name[300];
    char info[5000];
} file;


int cmp(const void* a, const void* b){
    file aa = *(file*)a;
    file bb = *(file*)b;

    if(!strcmp(aa.name, bb.name)){
        return strcmp(aa.info, bb.info);
    }

    return strcmp(aa.name, bb.name);
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
            strcpy(reg.name, cur->d_name);

            FILE *f = fopen(dirname, "r");
            fgets(reg.info, 5000, f);
            fclose(f);

            arr[*count] = reg;
            (*count)++;
        }
        dirname[strlen(dirname) - strlen(cur->d_name) - 1] = '\0';

        cur = readdir(dir);
    }
    closedir(dir);
}



int main(){
    char input[100] = "./tests";

    file* arr = malloc(5000 * sizeof(file));
    int count = 0;

    search(input, arr, &count);
    qsort(arr, count, sizeof(file), cmp);

    int max = 0;
    int num = 1;

    file f = arr[0];
    file res;

    for(int i = 1; i < count; ++i){
        if(!strcmp(f.name, arr[i].name) && !strcmp(f.info, arr[i].info)){
            num++;
        }
        else{
            if(max < num){
                max = num;
                res = f;
            }
            num = 1;
            f = arr[i];
        }
    }

    printf("%d; %s\n", max, res.name);

    free(arr);


    return 0;
}
