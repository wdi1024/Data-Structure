#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, evenSum=0, oddSum=0;
    scanf("%d", &n);
    int i=0;
    while(i<=n)
    {
        if(i%2==1)
            oddSum+=i;
        else
            evenSum+=i;
        i++;
    }
    printf("짝수의 합은 %d입니다.\n", evenSum);
    printf("홀수의 합은 %d입니다.\n", oddSum);
    return 0;
}

