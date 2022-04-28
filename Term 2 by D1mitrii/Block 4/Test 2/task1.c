#include <stdio.h>
#define SIZE 500
int mult_by_two(const int* a){
    return ( *(const int*)a * 2);
}

int pow_by_three(const int* a){
    int val = *(const int*)a;
    return (val * val * val);
}

int int_abs(const int* a){
    int val = *(const int*)a;
    if(val >= 0) return val;
    return -val;
}


void forEachElement(int* arr, int n, int (*func)(const int*)){
    for (int i = 0; i < n; i++)
    {
        arr[i] = func(&arr[i]);
    }
}

int main()
{
    int count = SIZE;
    int arr[SIZE];
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &arr[i]);
    }
    int cmd;
    scanf("%d", &cmd);
    switch (cmd)
    {
    case 1:
        forEachElement(arr, count, mult_by_two);
        break;
    case 2:
        forEachElement(arr, count, pow_by_three);
        break;
    case 3:
        forEachElement(arr, count, int_abs);
        break;
    default:
        printf("Error");
        return 0;
    }
    for (int i = 0; i < count-1; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("%d", arr[count-1]);
    return 0;
}