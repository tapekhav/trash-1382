#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

typedef struct{
    char* path;
    int count_of_chars;
} file_info;

file_info* init_file_info(){
    file_info* file = malloc(1 * sizeof(file_info));
    file->path = malloc(1000 * sizeof(char));
    return file;
}

void read_file(char* path, file_info* ptr_file){
    strcpy(ptr_file->path, path);
    FILE* txt_file = fopen(path, "r");
    if(!txt_file)
        return;

    int len = 0;
    char string[1001];
    while (fgets(string, 1000, txt_file))
    {
        len += strlen(string);
        fgets(string, 1000, txt_file);
    }
    
    ptr_file->count_of_chars = len;
    fclose(txt_file);
}

void search_dir(const char* dir_path, file_info** arr, int* count){

    char cur_path[1000];
    strcpy(cur_path, dir_path);

    DIR *dir = opendir(cur_path);

    if(!dir)
        return;
    
    struct dirent* de = readdir(dir);

    while (de)
    {
        if (de->d_type == DT_REG && strstr(de->d_name, ".txt")){
            int path_len = strlen(cur_path);
            strcat(cur_path, "/");
            strcat(cur_path, de->d_name);

            file_info* new_file = init_file_info();
            read_file(cur_path, new_file);
            arr[(*count)++] = new_file;
            cur_path[path_len] = '\0';
        }
        if(de->d_type == DT_DIR && strcmp(".", de->d_name) && strcmp("..", de->d_name)){
                int path_len = strlen(cur_path);
                strcat(cur_path, "/");
                strcat(cur_path, de->d_name);
                search_dir(cur_path, arr, count);
                cur_path[path_len] = '\0';
        }
        
        de = readdir(dir);
        
    }

    closedir(dir);
}

int mycmp(const void* a, const void* b){
    file_info* first_file = *(file_info**)a;
    file_info* second_file = *(file_info**)b;

    long int avg = first_file->count_of_chars - second_file->count_of_chars;
    if (avg == 0)
    {
        return strcmp(first_file->path, second_file->path);
    }
    return avg;
}

int main()
{
    file_info** arr = malloc(1000 * sizeof(file_info*));
    int count = 0;

    search_dir("./labyrinth", arr, &count);

    qsort(arr, count, sizeof(file_info*), mycmp);

    for (int i = 0; i < count; i++)
    {
        printf("%s; %d\n", arr[i]->path, arr[i]->count_of_chars);
    }

    for (int i = 0; i < count; i++)
    {
        free(arr[i]->path);
        free(arr[i]);
    }
    free(arr);
    
    return 0;
}
