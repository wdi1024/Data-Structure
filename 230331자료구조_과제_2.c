#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 100

typedef struct {
    char data[N];
    int top;
} StackType;

void init(StackType *S)
{
    S->top = -1;
}

int isEmpty(StackType *S)
{
    return S->top == -1;
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
        S->top++;
        S->data[S->top] = c;
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

void check(char str[])
{
    int i = 0, j = 0;
    StackType S;
    while (str[i] != '\0') 
    {
        if (isspace(str[i]) && isalpha(str[i])) 
        {
            push(&S, tolower(str[i]));
        }
        i++;
    }

    while (!isEmpty(&S))
    {
        str[j++] = pop(&S); 
    }
    

    int len = strlen(str);
    for (int k = 0; k < len / 2; k++) 
    {
        if (str[k] != str[len - 1 - k]) 
        {
            printf("회문이 아닙니다.\n");
            return ;
        }
    }
    printf("회문입니다.\n");
}

int main()
{
    char k[N];
    printf("문자열을 입력하세요: ");
    scanf("%s", k);

    check(k);
    
    return 0;
}
