#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 10

typedef char element;

typedef struct
{
    element data[N];
    int size;
}ListType;

void init(ListType *L)
{
    L->size = 0;
}

int isFull(ListType *L)
{
    return L -> size == N;
}

int isEmpty(ListType *L)
{
    return L->size == 0;
}

void insertLast(ListType *L, element e)
{
    if(isFull(L))
        printf("Full\n");
    else
    {
        L->data[L->size] = e;
        L->size++;
    }
}
void insert(ListType *L, int pos, element e)
{
    if(!isFull(L) && pos >= 0 && pos <= L -> size)
    {
        for (int i = L->size-1; i>= pos; i--)
            L->data[i+1] = L->data[i];

        L->data[pos]=e;
        L->size++;
    }
}

element delete(ListType *L, int pos)
{
    if(isEmpty(L) || pos < 0 || pos >= L->size)
    {
        printf("ERROR");
        return -1;
    }

    element data = L->data[pos];

    for (int i = pos; i < (L->size -1); i++)
        L->data[i] = L->data[i+1];

    L->size--;

    return data;
}

void print(ListType *L)
{
    for (int i = 0; i< L->size; i++)
        printf("%c", L->data[i]);
    printf("\n");
}



int main()
{
    ListType L;

    init(&L);
    
    insertLast(&L, 'A'); print(&L);
    insertLast(&L, 'B'); print(&L);
    insertLast(&L, 'C'); print(&L);
    getchar();

    insert(&L, 0, 'D'); print(&L);
    insert(&L, 2, 'E'); print(&L);
    getchar();

    printf("%c is deleted, left = ", delete(&L,0)); print(&L);

    return 0;
}