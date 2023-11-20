#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void makeArray(int A[])
{
    for(int i = 0; i<N; i++)
        A[i]=rand()%100+1;
}

void printArray(int A[])
{
    for(int i=0; i<N; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int findMax(int A[])
{
    int max = A[0];

    for(int i = 1; i < N; i++)
        if(A[i]>max)
            max=A[i];
    return max;
}


int main()
{
    int A[N];
    
    srand(time(NULL)); //난수 발생 전에 무조건 넣어야 하는 라인
    
    makeArray(A);
    printArray(A);
    
    printf("Max : %d\n", findMax(A));
    
    return 0;
}
