#include <stdio.h>
#include <stdlib.h>

void sumOfWeight(int g)
{
    int cnt = 0;

    for(int i = 1; i <= 10; i++)
    {
        for(int j = 1; j <=10; j++)
        {
            for(int k = 1; k <=10; k++)
            {
                if(2*i+3*j+5*k==g)
                {
                    printf("%d %d %d\n", i, j, k);
                    cnt+=1;
                }
            }
        }
    }
    if(cnt == 0)
        printf("0\n");
    else
        printf("%d", cnt);
}

int main()
{
    int g;
    scanf("%d", &g);

    sumOfWeight(g);

    return 0;
}

