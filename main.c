#include <stdio.h>
#include <string.h>

typedef struct word{
    char key[100];
    char trans[100];
}word;

int main() {
    int cnt_word = 0;

    word arr[100];
    for(;;){
        word w;
        scanf("%s", w.key);
        if(strcmp(w.key, "ugabuga") == 0){
            break;
        }
        scanf("%s", w.trans);
        arr[cnt_word] = w;
        cnt_word++;
    }


    getc(stdin);
    printf("end read\n");


    char orig[10000];
    fgets(orig, 10000, stdin);

    char *token;
    token = strtok(orig, " ");
    while (token != NULL){
        int flag = 0;
        for (int i = 0; i < cnt_word; i++){
            if(strcasecmp(token, arr[i].key) == 0){
                printf("%s ", arr[i].trans);
                flag = 1;
                break;
            }
        }
        if (flag == 0) printf("<unknown> ");
        token = strtok(NULL, " \n");
    }
    return 0;
}