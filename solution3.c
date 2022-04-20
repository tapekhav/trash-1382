#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char *word;
    char *translate;
}dict;


int main() {
    char str1[100][300];
    char str2[100][300];

    dict arr[300];

    int i = 0;
    int c = 0;
    int f = 0;

    for(;;){
        scanf("%s", str1[c]);
        if(!strcmp(str1[c], "ugabuga")) break;

        scanf("%s", str2[c]);

        for(int y = 0; y < i; ++y){
            if(strcmp(str1[c], arr[y].word) == 0){
                arr[y].translate = str2[c];

                f = 1;
                i--;
                c++;

                break;
            }

        }

        if(f == 0) {
            arr[i].word = str1[c];
            arr[i].translate = str2[c];
        }


        f = 0;
        i++;

        c++;
    }

    getchar();

    char str[1000];
    fgets(str, 1000, stdin);


    char *token;
    char *array[1000];

    token = strtok(str, " ");

    int k = 0;

    while(token != NULL){
        array[k] = malloc(100);
        array[k] = token;

        token = strtok(NULL, " \n");
        k++;
    }

    int flag = 0;

    for(int p = 0; p < k; p++){
        for(int n = 0; n < i; n++){
            if(!strcasecmp(array[p], arr[n].word)) {
                array[p] = arr[n].translate;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            array[p] = "<unknown>";
        }

        flag = 0;
    }

    int l;

    for(l = 0; l < k - 1; ++l){
        printf("%s ", array[l]);
    }
    printf("%s", array[l]);

    /* for(int j = 0; j < i; ++j){
         printf("%s---%s\n", arr[j].word, arr[j].translate);
     } */

    return 0;
}
