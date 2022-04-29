#include <stdio.h>

long sum(long a, long b){
    return a + b;
}


int main()
{
    long int first;
    long int second;
    scanf("%ld %ld", &first, &second);
    printf("%ld", sum(first, second));
    assertEqual(sum(99, 1), 100);
    assertEqual(sum(-313, 3), -310);
    assertEqual(sum(-313, -17), -330);
    return 0;
}
