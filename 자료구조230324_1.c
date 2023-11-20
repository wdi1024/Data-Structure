#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3


void makeMatrix(int A[N][N])
{
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            if (rand() % 2 ==0)
                A[i][j]=rand() % 10;
            else
                A[i][j]=-(rand()%10);   
}

void printMatrix(int A[N][N])
{
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++)
            printf("%3d", A[i][j]);
        printf("\n");
    }
}

void transposeMatrix(int A[N][N])
{
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++)
            printf("%3d", A[j][i]);
        printf("\n");
    }
}

void mulMatrix(int A[N][N], int B[N][N], int C[N][N])
{
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
        {
            C[i][j]=0;
            for (int k=0; k<N; k++)
                C[i][j] = C[i][j] + A[i][k]*B[k][j];
        }
    
}
int main()
{
    int A[N][N], B[N][N], C[N][N];
    srand(time(NULL));

    makeMatrix(A);
    makeMatrix(B);

    printMatrix(A); printf("\n");
    printMatrix(B); printf("\n");

    transposeMatrix(B); printf("\n");

    mulMatrix(A,B,C);
    printMatrix(C);
    return 0;
}