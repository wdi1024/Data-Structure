#include <stdio.h>
#include <stdlib.h>

int count; 

int fib(int n)
{
    count += 1;
    if (n==0) return 0;
    if (n==1) return 1;
    return (fib(n-1)+fib(n-2));
}

int fib_iter(int n)
{
    if (n==0) return 0;
    if (n==1) return 1;

    int pp=0;
    int p=1;
    int result = 0;

    for (int i = 2; i<=n; i++)
    {
        result = p+pp;
        pp=p;
        p=result;
    }
    return result;
}

int main()
{
    int n;
    scanf("%d",&n);

    printf("%d:%d",fib_iter(n),count);
}
