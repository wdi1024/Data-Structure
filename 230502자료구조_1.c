#include <stdio.h>
#include <stdlib.h>

#define N 10
typedef int element;

typedef struct TreeNode
{
    element key;
    struct TreeNode *left, *right;
}TreeNode;

typedef struct
{
    TreeNode* Stack[N];
    int top;
}StackType;

typedef struct 
{
    TreeNode* Queue[N];
    int front, rear;
}QueueType;

int isEmpty(QueueType *Q)
{
    return Q->front == (Q->rear)%N;
}

void enqueue(QueueType *Q, TreeNode *e)
{
    Q->rear = (Q->rear +1) % N;
    Q->Queue[Q->rear] = e;
}

TreeNode* dequeue(QueueType *Q)
{
    Q->front = (Q->front+1)%N;
    return Q->Queue[Q->front];
}

void initQueue(QueueType *Q)
{
    Q->front = Q->front = 0;
}

void levelOrder(TreeNode *root)
{
    QueueType Q;
    initQueue(&Q);

    enqueue(&Q, root);
    while(!isEmpty(&Q))
    {
        root = dequeue(&Q);
        printf("[%d] ", root->key);

        if(root->left)
            enqueue(&Q, root->left);
        
        if (root->right)
            enqueue(&Q, root->right);
    }
}

void initStack(StackType *S)
{
    S->top = -1;
}

void push(StackType *S, TreeNode* e)
{
    if (S->top < N-1)
        S->Stack[++S->top] = e;
}

TreeNode* pop(StackType *S)
{
    TreeNode *e = NULL;
    if (S->top >= 0)
        e= S->Stack[S->top--];
    
    return e;
}

void iterOrder(TreeNode *root)
{
    StackType S;
    initStack(&S);

    while (1)
    {
        for (; root!=NULL; root = root->left)
            push(&S, root);
        
        root = pop(&S);

        if (root == NULL)
            break;

        printf("[%d]", root->key);

        root = root->right;
    }
}

TreeNode* makeNode(element key, TreeNode *left, TreeNode *right)
{
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->key = key;
    node->left = left;
    node->right = right;

    return node;
}

void preOrder(TreeNode *root)
{
    if(root != NULL)
    {
        printf("[%d]", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TreeNode *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("[%d]", root->key);
        inOrder(root->right);
    }
}

void postOrder(TreeNode *root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("[%d]", root->key);
    }
}

int main()
{
    TreeNode *N4=makeNode(1,NULL,NULL);
    TreeNode *N6=makeNode(16,NULL,NULL);
    TreeNode *N7=makeNode(25,NULL,NULL);
    TreeNode *N2=makeNode(4,N4,NULL);
    TreeNode *N3=makeNode(20,N6,N7);
    TreeNode *N1=makeNode(15,N2,N3);

    printf("pre : "); preOrder(N1); printf("\n");
    printf("in : "); inOrder(N1); printf("\n");
    printf("post : "); postOrder(N1); printf("\n");
    printf("level : "); levelOrder(N1);
}