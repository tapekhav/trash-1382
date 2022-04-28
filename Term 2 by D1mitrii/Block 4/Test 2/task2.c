#include <stdio.h>
#include <math.h>
#define SIZE 20

int char_cmp(const void* a, const void* b){
    return (int) *(const char*)a - (int) *(const char*)b;
}

int int_cmp(const void* a, const void* b){
    return *(const int*)a - *(const int*)b;
}

int double_cmp(const void* a, const void* b){

    double left = *(const double*) a;
    double right = *(const double*) b;
    if(fabs(left - right) < 0.0001) return 0;
    if(left > right) return 1;
    if(left < right) return -1;
    return 0;
}


int universalMax(void* arr, int n, int size, int (*cmp)(const void*, const void*)){
    int inx = 0;

    for (int i = 0; i < n; i++)
    {
        if(cmp((arr + i * size), arr + inx * size) > 0){
        inx = i;
        }
    }

    return inx;
}

int main()
{
    char carr[SIZE];
    int iarr[SIZE];
    double darr[SIZE];
    char ch;
    int type;
    scanf("%d%c", &type, &ch);
    switch (type)
    {
    case 1:
        for (int i = 0; i < SIZE; i++)
        {
            scanf("%c%c", &carr[i], &ch);
        }
        printf("%d", universalMax(carr, SIZE, sizeof(char), char_cmp));
        break;
    case 4:
        for (int i = 0; i < SIZE; i++)
        {
            scanf("%d", &iarr[i]);
        }
        printf("%d", universalMax(iarr, SIZE, sizeof(int), int_cmp));
        break;
    case 8:
        for (int i = 0; i < SIZE; i++)
        {
            scanf("%lf", &darr[i]);
        }
        printf("%d", universalMax(darr, SIZE, sizeof(double), double_cmp));
        break;
    default:
        break;
    }
    return 0;
}