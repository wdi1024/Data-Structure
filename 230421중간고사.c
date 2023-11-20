#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int element;

typedef struct ListNode{
    element data;
    struct ListNode *next;
}ListNode;

typedef struct ListType{
    ListNode *H;
}ListType;

void init(ListType *L){
    L->H = NULL;
}

void makeSet(ListType *L, element e)
{
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = e;
    if (L->H == NULL){
        node->next = L->H;
        L->H = node;
    }
    else{
        ListNode *p;
        for (p=L->H; p->next!=NULL; p=p->next)
            if (e == p->data)
                break;
        if(p->next == NULL){
            node->next = p->next;
            p->next = node;
        }
    }
}

void print(ListType *L){
    ListNode *p = L->H;
    printf("{");
    do{
        printf("%d,", p->data);
        p=p->next;
    }while(p!=NULL);
    printf("\b}\n");
}

void intersect(ListType *L1, ListType *L2)
{
    printf("Interrsect : {");
    ListNode *p = L1->H;
    for (; p!=NULL; p=p->next){
        ListNode *q = L2->H;
        for(; q!=NULL; q=q->next)
            if (p->data==q->data)
                printf("%d, ",p->data);
    }
    printf("\b\b}     ");
}

int main()
{
    ListType L1;
    ListType L2;
    init(&L1);
    init(&L2);   
    srand(time(NULL));
    for (int i = 0; i<10; i++){
        makeSet(&L1, rand()%30+1);
        makeSet(&L2, rand()%30+1);
    }
    print(&L1);
    print(&L2);
    intersect(&L1, &L2);
}