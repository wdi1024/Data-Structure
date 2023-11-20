#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int evaluate(char exp[])
{
    StackType S;
    init(&S);

    int op1, op2, value;
    char c;

    int n = strlen(exp);

    for (int i = 0; i < n; i++)
    {
        c = exp[i];

        if (c != '+' && c != '-' && c != '*' && c != '/')
        {
            value = c - '0';
            push(&S, value);
        }
        else
        {
            op2=pop(&S);
            op1=pop(&S);

            switch(c)
            {
                case '+' :
                    push(&S, op1 + op2);
                    break;
                case '-' :
                    push(&S, op1 - op2);
                    break;
                case '*' :
                    push(&S, op1 * op2);
                    break;
                case '/' :
                    push(&S, op1 / op2);
                    break;
            }
        }
    }
    return pop(&S);
}

int prec(char op)
{
    switch(op){
    case '(': case ')':
        return 0;
    case '+': case '-':
        return 1;
    case '*': case '/':
        return 2;
    }
}

void convert(char exp[])
{
    StackType S;
    init(&S);

    char c, t;
    int n = strlen(exp);

    for (int i = 0; i < n; i++)
    {
        c = exp[i];
        switch (c)
        {
        case '+' :
        case '-' :
        case '*' :
        case '/' :
            while (!isEmpty(&S) && prec(c) <= prec(peek(&S)))
                printf("%c", pop(&S));
            push(&S, c);
            break;
        case '(' :
            push(&S, c);
            break;
        case ')' :
            t = pop(&S);
            while(t != '(')
            {
                printf("%c", t);
                t = pop(&S);
            }
            break;
        default :
        {
            printf("%c",c);
            break;
        }
        }
    }
    while (!isEmpty(&S))
        printf("%c", pop(&S));
    printf("\n");
}

int main()
{
    char exp[N];
    scanf("%s", exp);

    convert(exp);

    printf("%d \n", evaluate(exp));

    return 0;
}