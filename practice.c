#include<stdio.h>
#include<stdlib.h>

typedef char element;

typedef struct DlistNode{
	element data;
	struct DlistNode *prev;
	struct DlistNode *next;
}DlistNode;

typedef struct {
	DlistNode *H;
	DlistNode *T;
	int N;
}DlistType;

DlistNode* getNode()
{
	DlistNode *node = (DlistNode*)malloc(sizeof(DlistNode));
	node->next = node->prev = NULL;
	return node;
}

void init(DlistType *DL)
{
	DL->H = getNode();
	DL->T = getNode();
	DL->H->next = DL->T;
	DL->T->prev = DL->H;
	DL->N = 0;
}

void insertFirst(DlistType *DL, element e)
{
	DlistNode *node = getNode();
	DlistNode *p = DL->H;

	node->data = e;
	node->prev = p;
	node->next = p->next;

	p->next->prev = node;
	p->next = node;
	
	DL->N++;
}

void insertLast(DlistType *DL, element e)
{
	DlistNode *node = getNode();
	DlistNode *p = DL->T;

	node->data = e;
	node->next = p;
	node->prev = p->prev;

	p->prev->next = node;
	p->prev = node;
	
	DL->N++;
}

void insert(DlistType *DL, int pos, element e)
{
	if (pos <1 || pos>DL->N+1)
		printf("Invalid Position.\n");
	else if (pos == 1)
		insertFirst(DL,e);
	else if (pos == DL->N)
		insertLast(DL,e);
	else
	{
		DlistNode *node = getNode();
		DlistNode *p = DL->H;

		for(int i =1;i<pos;i++)
			p=p->next;
		node->data = e;
		node->prev = p;
		node->next = p->next;

		p->next->prev = node;
		p->next = node;
		
		DL->N++;
	}

}

void print(DlistType *DL)
{
	DlistNode *p ;
	for (p=DL->H->next; p!=DL->T; p=p->next)
		printf("[%c] <=> ", p->data);
	printf("\b\b\b\b   \n");
}

element delete(DlistType *DL, int pos)
{
	element e = -1;
	if (pos<1 || pos>DL->N+1)
		printf("Invalid Position.\n");
	else
	{
		DlistNode *p = DL->H;

		for (int i = 0; i<pos; i++)
			p=p->next;
		e = p->data;
		p->prev->next = p->next;
		p->next->prev = p->prev;

		free(p);
		DL->N--;
	}
	return e;
}


int main() {
	DlistType DL;
    init(&DL);

    insertFirst(&DL, 'A'); print(&DL);
    insertFirst(&DL, 'B'); print(&DL);
    insertLast(&DL, 'C'); print(&DL);
    insertLast(&DL, 'D'); print(&DL);
    insert(&DL, 1, 'E'); print(&DL);
    insert(&DL, 6, 'F'); print(&DL);
    insert(&DL, 5, 'G'); print(&DL); getchar();

    printf("[%c]is deleted.\n",delete(&DL,3)); print(&DL);
    printf("[%c]is deleted.\n",delete(&DL,6)); print(&DL);

    return 0;
}