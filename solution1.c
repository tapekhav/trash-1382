#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
 
int Integer(const void* a){
    int i = *((const int *) a);
 
    if(i % 2 == 0) return 1;
    return 0;
    //return (abs(*((const int*)a)) + 1) % 2;
}
 
 
int Float(const void* a){
    double i = *((const double*)a);
 
    if(i < 0) i *= -1;
 
    int j = (int)i;
    return (i - j < 0.000001) && (j % 2 == 0);
}
 
int count_if(void *arr, int size, int k, int (*func)(const void *a)){
    int count = 0;
 
    //printf("%d", *(arr));
 
    for(int i = 0; i < k; ++i){
        if(func(arr + i*size)){
            ++count;
        }
        //printf("%d\n", *(arr + i*size));
    }
 
    return count;
}
 
 
int main(){
    int flag;
    scanf("%d", &flag);
 
    if(flag == 0) {
        int arr[20];
        int count = 0;
        char c;
 
        for(int i = 0; i < 20; ++i){
            scanf("%d%c", &arr[i], &c);
            ++count;
 
            if(c == '\n') break;
        }
 
        printf("%d", count_if(arr, 4, count, Integer));
    }
    else {
        double arr[20];
        int count = 0;
        char c;
 
        for(int i = 0; i < 20; ++i){
            scanf("%lf%c", &arr[i], &c);
            ++count;
 
            if(c == '\n') break;
        }
 
        printf("%d", count_if(arr, 8, count, Float));
    }
 
}
