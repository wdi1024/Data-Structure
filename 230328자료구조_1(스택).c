#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef struct // 연결된 표현법이 아닐 때는 이름을 쓰지 않음
{
    char data[N];
    int top;
}StackType;

void init(StackType *S)
{
    S-> top = -1;
}

int isEmpty(StackType *S)
{
    return S-> top == -1;
}

int isFull(StackType *S)
{
    return S->top == N-1;
}

void push(StackType *S, char c)
{
    if(isFull(S))
        printf("Full\n");
    else
    {
        S-> top++;
        S-> data[S->top] = c;
    }
}

char pop(StackType *S)
{
    if(isEmpty(S))
    {
        printf("Empty\n");
        return -1;
    }

    char c = S->data[S->top];
    S->top--;
    return c;
}

char peek(StackType *S)
{
    if(isEmpty(S))
    {
        printf("Empty\n");
        return -1;
    }

    return S->data[S->top];
}

void print(StackType *S)
{
    for (int i = 0; i <= S->top; i++)
        printf("%c", S->data[i]);
    printf("\n");
}

int main()
{
    StackType S;
    init(&S);
    push(&S, 'C'); push(&S, 'a'); push(&S, 't'); push(&S, 's');
    print(&S);

    printf("pop : %c\n", pop(&S));
    print(&S);

    printf("peek : %c\n", peek(&S));
    print(&S);
    
    return 0;
}