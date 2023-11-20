#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

typedef char element;

typedef struct
{
    element data[N];
    int front, rear;
}QueueType;

void init(QueueType *Q)
{
    Q->front = Q->rear = -1;
}

int isFull(QueueType *Q)
{
    return Q->rear == N-1;
}

int isEmpty(QueueType *Q)
{
    return Q->front == Q->rear;
}

void enqueue(QueueType *Q, element e)
{
    if (isFull(Q))
        printf("FULL");
    else
    {
        Q->rear++;
        Q->data[Q->rear] = e;
    }
}

void print(QueueType *Q)
{
    printf("Front : %d - Rear : %d\n", Q->front, Q->rear);

    for (int i = Q->front + 1; i <= Q->rear; i++)
        printf("[%c]", Q->data[i]);

    printf("\n");
}

element dequeue(QueueType *Q)
{
    if(isEmpty(Q))
    {
        printf("Empty\n");
        return 0;
    }
    Q->front++;
    return Q->data[Q->front];
}

int main()
{
    QueueType Q;
    init(&Q);
    srand(time(NULL));

    for (int i = 0; i < 7; i++)
        enqueue(&Q,rand() % 26 + 65); //rand()%26+65를 하면 대문자 알파벳의 ASCII 코드 값이 나옴
    
    print(&Q);  getchar();

    for(int i = 0; i < 4; i++)
        printf("[%c]", dequeue(&Q));
    printf("\n");   print(&Q);  getchar();

    return 0;
}