#include <stdio.h>
#include <stdlib.h>

typedef struct Test
{
    int id;
    int money;
}Test;

void add(Test *T, int amount)
{
    T->money += amount; // (*T).money 로도 가능
    printf("%d : %d\n", T->id, T->money);
}

int main()
{
    Test a;

    scanf("%d %d", &a.id, &a.money);
    printf("%d : %d\n", a.id, a.money);

    int amount;
    scanf("%d", &amount);

    add(&a,amount);
    printf("%d : %d\n", a.id, a.money);
    
    return 0;
}