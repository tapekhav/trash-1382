#include <stdio.h>
#include <string.h>
#include <dirent.h>


long long mul(char* dirname);

long long add(char* dirname){
    long long res = 0;
    DIR* dir = opendir(dirname);

    struct dirent *cur = readdir(dir);

    while(cur){
        if(cur->d_type == DT_DIR && strcmp(cur->d_name, ".") != 0 && strcmp(cur->d_name, "..") != 0){
            if(!strcmp(cur->d_name, "add")) {
                strcat(dirname, "/");
                strcat(dirname, cur->d_name);
                res += add(dirname);
                size_t slen = strlen(dirname);
                dirname[slen-4] = '\0';
            }
            if(!strcmp(cur->d_name, "mul")) {
                strcat(dirname, "/");
                strcat(dirname, cur->d_name);
                res += mul(dirname);
                size_t slen = strlen(dirname);
                dirname[slen-4] = '\0';
            }
        }
        if(cur->d_type == DT_REG){
            FILE* f;
            long long n;
            char c;

            strcat(dirname, "/");
            strcat(dirname, cur->d_name);

            f = fopen(dirname, "r");
            while (c != EOF && c != '\n' && fscanf(f, "%lld", &n) != EOF) {
                c = fgetc(f);
                res += n;
            }
            fclose(f);

            size_t slen = strlen(dirname);
            size_t len = strlen(cur->d_name);


            dirname[slen - len - 1] = '\0';
        }
        cur = readdir(dir);

    }

    closedir(dir);

    return res;
}

long long mul(char* dirname){
    long long res = 1;
    DIR* dir = opendir(dirname);

    struct dirent *cur = readdir(dir);

    while(cur){
        if(cur->d_type == DT_DIR && strcmp(cur->d_name, ".") != 0 && strcmp(cur->d_name, "..") != 0){
            if(!strcmp(cur->d_name, "add")) {
                strcat(dirname, "/");
                strcat(dirname, cur->d_name);
                res *= add(dirname);
                size_t slen = strlen(dirname);
                dirname[slen-4] = '\0';
            }
            if(!strcmp(cur->d_name, "mul")) {
                strcat(dirname, "/");
                strcat(dirname, cur->d_name);
                res *= mul(dirname);
                size_t slen = strlen(dirname);
                dirname[slen-4] = '\0';
            }
        }
        if(cur->d_type == DT_REG){
            FILE* f;
            long long n;
            char c;

            strcat(dirname, "/");
            strcat(dirname, cur->d_name);

            f = fopen(dirname, "r");

            while (c != EOF && c != '\n' && fscanf(f, "%lld", &n) != EOF) {
                c = fgetc(f);
                res *= n;
            }

            size_t slen = strlen(dirname);
            size_t len = strlen(cur->d_name);

            fclose(f);

            dirname[slen - len - 1] = '\0';
        }

        cur = readdir(dir);

    }

    closedir(dir);

    return res;
}


int main() {
    char path[1000] = "./result.txt";
    char tmp[1000] = "./tmp";

    FILE *file = fopen(path, "w");

    fprintf(file, "%lld", add(tmp));


    return 0;
}