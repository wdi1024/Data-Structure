// 230407 수업에 코드 추가

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 10

typedef char element;

typedef struct
{
    element data[N];
    int front, rear;
}DequeType;

void init(DequeType *D)
{
    D->front = D->rear = 0;
}

int isFull(DequeType *D)
{
    return D->front == (D->rear + 1) % N;
}

int isEmpty(DequeType *D)
{
    return D->front == D->rear;
}

void addFront(DequeType *D, element e)
{
    if(isFull(D))
        printf("Full\n");
    else
    {
        D->data[D->front] = e;
        D->front = (D -> front -1 + N) % N;
    }
}

void add_rear(DequeType *D, element e)
{
    if (isFull(D))
        printf("FULL");
    else
    {
        D->rear = (D->rear + 1) % N;
        D->data[D->rear] = e;
    }
}

void print(DequeType *D)
{
    printf("Front : %d - Rear : %d\n", D->front, D->rear);

    int i = D->front;

    while (i != D->rear)
    {
        i = (i + 1) % N;
    }

    printf("\n");
}

element deleteFront(DequeType *D)
{
    if(isEmpty(D))
    {
        printf("Empty\n");
        return 0;
    }
    D->front = (D->front + 1) % N;
    return D->data[D->front];
}

element deleteRear(DequeType *D)
{
    if(isEmpty(D))
    {
        printf("Empty\n");
        return 0;
    }
    int pos = D -> rear;
    D->rear = (D->rear - 1 + N) % N;
    return D->data[pos];
}

element get_front(DequeType *D)
{
    if(isEmpty(D))
    {
        printf("Empty\n");
        return 0;
    }

    return D->data[(D->front - 1) % N];
}

element getRear(DequeType *D)
{
    if(isEmpty(D))
    {
        printf("Empty\n");
        return 0;
    }

    return D->data[(D->rear + 1) % N];
}

int getCount(DequeType *D)
{
    int count = D->rear - D->front;
    if (count < 0)
        count += N;
    
    return count;
}

int main()
{
    DequeType D;
    init(&D);
    srand(time(NULL));
/*
    for (int i = 0; i < 3; i++)
        add_rear(&D,rand() % 26 + 65); //rand()%26+65를 하면 대문자 알파벳의 ASCII 코드 값이 나옴
    print(&D);  getchar();

    for (int i = 0; i < 4; i++)
        addFront(&D,rand() % 26 + 65); //rand()%26+65를 하면 대문자 알파벳의 ASCII 코드 값이 나옴
    print(&D);  getchar();

    for (int i = 0; i < 2; i++)
        deleteRear(&D);
    print(&D);  getchar();

    for (int i = 0; i < 3; i++)
        deleteFront(&D);
    print(&D);  getchar();
*/

    char str[N];

    scanf("%s", &str);

    for ( int i = 0; i < strlen(str); i++)
        add_rear(&D, str[i]);

    int equal = 1;  // flag 변수 -> 상태정보 기억하는 변수

    while (getCount(&D) > 1 && equal)
    {
        char first = deleteFront(&D);
        char last = deleteRear(&D);
        if (first != last)
            equal = 0;
            break;
    }

    if (equal == 1)
        printf("YES");
    else
        printf("NO");

    return 0;
}