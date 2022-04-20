#include <stdio.h>
#include <string.h>

typedef struct{
    char *word;
    char *trans;
}dict;


int main(){

    char str1[100][300];
    char str2[100][300];

    dict dictionary[100];

    int i = 0;
    int c = 0;
    int f = 0;

    for(;;){
        scanf("%s", str1[c]);
        if(!strcmp(str1[c], "ugabuga")) break;

        scanf("%s", str2[c]);

        for(int y = 0; y < i; ++y){
            if(strcmp(str1[c], dictionary[y].word) == 0){
                dictionary[y].trans = str2[c];

                f = 1;
                i--;
                c++;

                break;
            }
        }


        if(f == 0) {
            dictionary[i].word = str1[c];
            dictionary[i].trans = str2[c];
        }

        f = 0;
        i++;
        c++;

    }

    getchar();

    char str[1000];
    fgets(str, 1000, stdin);


    char* token;
    int flag1 = 0;

    int start = 0;

    token = strtok(str, " \n");

    while(token != NULL){

        if(start > 0) printf(" ");
        start++;

        for(int x = 0; x < i; ++x){
            if(!strcasecmp(token, dictionary[x].word)){
                printf("%s", dictionary[x].trans);

                flag1 = 1;
                break;
            }
        }

        if(flag1 == 0) printf("<unknown>");

        flag1 = 0;
        token = strtok(NULL, " \n");
    }
    /*puts("");
    for(int p = 0; p < i; ++p){

        printf("%s---%s\n", dictionary[p].word, dictionary[p].trans);
    } */


    return 0;
}
