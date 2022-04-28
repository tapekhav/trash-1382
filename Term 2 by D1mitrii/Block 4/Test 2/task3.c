#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct{
    char* text;
    int len;
} sentence;



int cmp(const void* a, const void* b){
    sentence sent_a = *(sentence*) a;
    sentence sent_b = *(sentence*) b;
    return (sent_a.len - sent_b.len);
}


int main()
{
    char string[1001];
    fgets(string, 1000, stdin);
    sentence* arr = malloc(500 * sizeof(sentence));
    char* token = strtok(string, ".\n");
    int count = 0;
    while (token)
    {
        
        if (token[0] == ' '){
            for (int i = 0; i < strlen(token); i++){
                token[i] = token[i+1];
            }
        }
        sentence new_sent = {token, strlen(token)};
        arr[count++] = new_sent;
        token = strtok(NULL, ".\n");
    }
    
    qsort(arr, count, sizeof(sentence), cmp);

    for (int i = 0; i < count - 1; i++)
    {
        printf("%s. ", arr[i].text);
    }
    printf("%s.", arr[count-1].text);

    free(arr);
    return 0;
}