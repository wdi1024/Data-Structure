#include <stdio.h>
#include <stdlib.h>

int iFact(int n)
{
    int r = 1;

    for(int i = 1; i <= n; i++)
        r *= i;
    return r;
}


int rFact(int n)
{
    if (n==1)
        return 1;
    else
        return n*rFact(n-1);
}

int main()
{
    int n;
    
    scanf("%d", &n);
    
    printf("%d %d", iFact(n), rFact(n));

    return 0;
}

