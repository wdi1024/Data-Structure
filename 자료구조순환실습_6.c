#include <stdio.h>
#include <stdlib.h>


int gcd(x, y)
{
    if (y<=0)
        return x;
    else
        return gcd(y, x%y);
}


int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n",gcd(a, b));
    return 0;
}