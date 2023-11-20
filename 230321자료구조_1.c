#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct Poly
{
    int degree;
    int coef[N];
}Poly;

Poly addPoly(Poly A, Poly B)
{
    Poly C;

    int Apos = 0, Bpos = 0, Cpos = 0;
    int degA = A.degree;
    int degB = B.degree;

    C.degree = (degA >= degB) ? degA : degB;

    while (Apos <= A.degree && Bpos <= B.degree)
    {
        if (degA > degB)
        {
            C.coef[Cpos]=A.coef[Apos];
            Apos++; Cpos++; degA--;
        }
        else if (degA==degB)
        {
            C.coef[Cpos]= A.coef[Apos] + B.coef[Bpos];
            Apos++; Bpos++; Cpos++; degA--; degB--;
        }
        else
        {
            C.coef[Cpos]=B.coef[Bpos];
            Bpos++; Cpos++; degB--;
        }
    }
    return C;
}

void printPoly(Poly P)
{
    int i, j;
    for (i=0, j = P.degree; i <= P.degree; i++, j--)
        printf("%2dx^%d +",P.coef[i], j);

    printf("\b\b  \n");
}

int main()
{
    Poly a, b, c;

    scanf("%d %d", &a.degree, &b.degree);

    for (int i = 0; i<=a.degree; i++)
        scanf("%d", &a.coef[i]);

    for (int i = 0; i<=b.degree; i++)
        scanf("%d", &b.coef[i]);
    printPoly(a);
    printPoly(b);

    c= addPoly(a,b);
    printf("========================================\n");
    printPoly(c);
    return 0;
}