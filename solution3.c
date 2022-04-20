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
    int count = 0;
    int flag = 0;

    for(;;){
        scanf("%s", str1[i]);

        if(!strcmp(str1[i], "ugabuga"))
            break;

        scanf("%s", str2[i]);

        for(int j = 0; j < i; ++j) {
            if (!strcmp(dictionary[j].word, str1[count])) {
                dictionary[j].trans = str2[count];

                flag = 1;
                count++;
                --i;
                break;
            }
        }

        if(flag == 0) {
            dictionary[i].word = str1[count];
            dictionary[i].trans = str2[count];
        }

        flag = 0;
        i++;
        count++;

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


    return 0;
}
