#include <stdio.h>
#include <stdlib.h>

double ipower(float x, int n)
{
    int i;
    double result=1.0;
    for(i=0; i<n; i++)
        result=result *x;
    return result;
}

double power(float x, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2 == 0)
        return power(x*x,n/2);
    else
        return x*power(x*x,(n-1)/2);
}

int main()
{
    float x; int n;
    scanf("%f %d", &x, &n);
    
    printf("%f - %f", ipower(x,n), power(x,n));

    return 0;
}

