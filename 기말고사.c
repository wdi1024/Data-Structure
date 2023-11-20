#include <stdio.h>
#include <stdlib.h>
#define N 10
#define element int

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct AVLNode
{
    int key;
    struct AVLNode *left;
    struct AVLNode *right;
}AVLNode;

typedef struct 
{
    AVLNode* Queue[N];
    int front, rear;
}QueueType;

int isEmpty(QueueType *Q)
{
    return Q->front == (Q->rear)%N;
}

void enqueue(QueueType *Q, AVLNode *e)
{
    Q->rear = (Q->rear +1) % N;
    Q->Queue[Q->rear] = e;
}

AVLNode* dequeue(QueueType *Q)
{
    Q->front = (Q->front+1)%N;
    return Q->Queue[Q->front];
}

void initQueue(QueueType *Q)
{
    Q->front = Q->front = 0;
}

int getHeight(AVLNode* node)
{
    int height = 0;
    if(node != NULL)
        height = 1 + max(getHeight(node->left), getHeight(node->right));
    
    return height;
}

int getBalance(AVLNode* node)
{
    if(node == NULL)
        return 0;
    
    return getHeight(node->left) - getHeight(node->right);
}

AVLNode* rotateRight(AVLNode* p)
{
    AVLNode* c = p->left;
    p->left = c->right;
    c->right = p;
    return c;
}

AVLNode* rotateLeft(AVLNode* p)
{
    AVLNode* c = p->right;
    p->right = c->left;
    c->left = p;
    return c;
}

AVLNode* createNode(int key)
{
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key;
    node->left = node->right = NULL;

    return node;
}

AVLNode* insert(AVLNode* node, int key)
{
    if (node == NULL)
        return createNode(key);
    
    if(key < node->key)
        node->left = insert(node->left, key);
    else if(key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key) // LL
        return rotateRight(node);
    
    if (balance > 1 && key > node->left->key) // LR
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && key > node->right->key) // RR
        return rotateLeft(node);
    if (balance < -1 && key < node->right->key) // RL
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

AVLNode* insertKey(AVLNode* node, int A[], int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low + high) / 2;
        node = insert(node, A[mid]);
        node = insertKey(node, A, low, mid);
        node = insertKey(node, A, mid + 1, high);
    }
    return node;
}


void Order(AVLNode* root){
    QueueType Q;
    initQueue(&Q);

    enqueue(&Q, root);
    while (!isEmpty(&Q))
    {
        printf("%d", root->key);
        root = dequeue(&Q);
        if (root->left != NULL)
            enqueue(&Q, root->left);
        if (root->right != NULL)
            enqueue(&Q, root->right);
    }
}

int main()
{
    AVLNode* root = NULL;
    int low = 0, high = 10;
    int A[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    insertKey(root, A, low, high);
    
    Order(root);
}
