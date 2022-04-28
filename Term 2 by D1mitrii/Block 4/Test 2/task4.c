#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct{

    char name[30];

    char author[30];

    unsigned int pages;

    char isbn[20];

}Book;

int cmp(const void* a, const void* b){
    char* author_b = (*(Book*)b).author;
    char* author_a = (*(Book*)a).author;
    return (strcmp(author_b, author_a));
}


int main()
{
    int n;
    scanf("%d", &n);
    Book* arr = malloc(n * sizeof(Book));
    for (int i = 0; i < n; i++)
    {
        Book new_book;
        scanf("%s %s %u %s",new_book.name, new_book.author, &new_book.pages, new_book.isbn);
        arr[i] = new_book;
    }   
    qsort(arr, n, sizeof(Book), cmp);
    for (int i = 0; i < n-1; i++)
    {
        printf("%s %s %u %s ", arr[i].name, arr[i].author, arr[i].pages, arr[i].isbn);
    }
    printf("%s %s %u %s", arr[n-1].name, arr[n-1].author, arr[n-1].pages, arr[n-1].isbn);
    return 0;
}