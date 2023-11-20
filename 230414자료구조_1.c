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

element deleteFirst(ListType *L)
{
    if (L->size == 0){
        printf("No element. \n");
        return -1;
    }
    ListNode *p = L->head;
    element e = L->head->data;
    L->head = p->next;
    free(p);
    L->size--;
    return e;
}

element deleteLast(ListType *L)
{
    ListNode *p, *q;
    element e;
    for (q = L->head; q->next != NULL; q = q->next);
    e = q->data;
    for (p = L->head; p->next != q; p = p->next);

    p->next = NULL;
    L->size--;
    return e;
}

element delete(ListType *L, int pos)
{
    if (L->size == 0){
        printf("No element. \n");
        return -1;
    }
    if (pos <1 || pos > L->size){
        printf("Invalid Pos. \n");
        return -1;
    }
    else{
        ListNode *p = L->head;
        ListNode *q = L->head;
        element e;
        if (pos == 1)
            deleteFirst(L);
        else
        {
            for (int i = 1; i < pos; i++){
                q = p;
                p = p->next;
            }
            e = p->data;
            q->next = p->next;
            L->size--;
        }
        return e;
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

    printf("[%c] is deleted.\n", deleteFirst(&L)); print(&L); 
    printf("[%c] is deleted.\n", deleteLast(&L)); print(&L); 
    printf("[%c] is deleted.\n", delete(&L,6)); print(&L); 

}