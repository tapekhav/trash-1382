#include <stdio.h>
#include <string.h>

int pred_i(const void *num){
    if (*(int*)num%2 != 0) return 0;
    return 1;
}

int pred_d(const void *num){
    double i = *((const double*)num);

    if(i < 0) i *= -1;

    int j = (int)i;
    return (i - j < 0.000001) && (j % 2 == 0);
}


int count_if(void* base, size_t num, size_t size, int (*pred)(const void*)){
    int cnt = 0;
    for (int i = 0; i < num; i++){
        cnt += pred(base+i*size);
    }
    return cnt;
}

int main(){
    int size;
    scanf("%d", &size);
    char c;
    int res = -1;

    printf("enter nums\n");

    if (size == 4){
        int arr[5];
        for (int i = 0; i < 5; i++){
            scanf("%d", &arr[i]);
        }
        res = count_if(arr, 5, 4, pred_i);

    }else if(size == 8){
        double arr[5];
        for (int i = 0; i < 5; i++){
            scanf("%lf", &arr[i]);
        }
        res = count_if(arr, 5, size, pred_d);
    }


    if (res != -1) printf("%d", res);

    return 0;
}