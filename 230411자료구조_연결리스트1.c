#include <stdio.h>
#include <stdlib.h>

typedef char element;

typedef struct ListNode{
    element data;
    struct ListNode *next;
}ListNode;

typedef struct ListType 
{
    ListNode *head;
    int size;
}ListType;

void init(ListType *L)
{
    L->head = NULL;
    L->size = 0;
}

void insertFirst(ListType *L, element e)
{
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = e;
    node->next = L->head;
    L->head = node;
    L->size++;
}

void insertLast(ListType *L, element e)
{
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->data = e;
    node->next = NULL;

    if (L->size == 0)
        L->head = node;
    else
    {
    ListNode *p;
    for (p = L->head; p->next != NULL; p = p->next);

    p->next = node;
    }
    L->size++;
}

void insert(ListType *L, int pos, element e)
{
    if (pos == 1)
        insertFirst(L, e);
    else if (pos == L->size+1)
        insertLast(L, e);
    else
    {
        ListNode *node = (ListNode*)malloc(sizeof(ListNode));
        ListNode *p = L->head;

        for (int i = 1; i < pos; i++)
            p = p->next;
        node->data = e;
        node->next = p->next;
        p->next = node;
        L->size++;
    }
}

void print(ListType *L)
{
    ListNode *p;
    for (p = L->head; p != NULL; p = p->next)
        printf("%c => ", p->data);
    printf("\b\b\b   \n");
}

void deleteFirst(ListType *L)
{
    ListNode *p = L->head;
    L->head = p->next;
    L->size--;
}

void deleteLast(ListType *L)
{
    ListNode *p, *q;
    for (q = L->head; q->next != NULL; q = q->next);
    for (p = L->head; p->next != q; p = p->next);

    p->next = NULL;
    L->size--;
}

void delete(ListType *L, int pos)
{
    if (pos == 1)
        deleteFirst(L);
    else if (pos == L->size)
        deleteLast(L);
    else
    {
        ListNode *p = L->head;
        ListNode *q = L->head;
        for (int i = 1; i < pos-1; i++)
            q = q->next;
        for (int j = 1; j < pos; j++)
            p = p->next;
        
        q->next = p->next;
        L->size--;
    }
}

int main()
{
    ListType L;
    init(&L);

    insertLast(&L, 'E'); print(&L); 

    insertFirst(&L, 'A'); print(&L);
    insertFirst(&L, 'B'); print(&L); getchar();

    insertLast(&L, 'C'); print(&L); 
    insertLast(&L, 'D'); print(&L); getchar();

    insert(&L, 1, 'F'); print(&L); 
    insert(&L, 4, 'G'); print(&L);
    insert(&L, 8, 'H'); print(&L);

    deleteFirst(&L); print(&L);
    deleteLast(&L); print(&L); 
    delete(&L, 3); print(&L);

}