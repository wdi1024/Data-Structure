#include <stdio.h>
#include <stdlib.h>


void swap(int *x, int *y)
{
    printf("x : %d, y : %d \n", *x, *y);

    int t = *x;
    *x = *y;
    *y = t;

    printf("x : %d, y : %d \n", *x, *y);
}


int main()
{
    int a, b;

    scanf("%d %d", &a, &b);
    printf("%d %d\n", a, b);
    swap(&a,&b);
    printf("%d %d", a, b);
    return 0;
}