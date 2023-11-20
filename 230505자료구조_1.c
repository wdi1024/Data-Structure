#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct TreeNode
{
    element key;
    struct TreeNode *left, *right;
}TreeNode;


TreeNode* makeNode(element key)
{
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

TreeNode* insertNode(TreeNode *root, element key)
{
    if(root == NULL)
        return makeNode(key);
        
    if(key < root->key)
        root->left = insertNode(root->left, key);
    else if(key > root->key)
        root->right = insertNode(root->right, key);
        
    return root;    
}

TreeNode* minValueNode(TreeNode *root)
{
    TreeNode* p = root;
    while(p->left != NULL) 
        p=p->left;
    
    return p;
}

TreeNode* deleteNode(TreeNode *root, element key)
{
    if (root == NULL)
        return NULL;
    
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if(root->left == NULL)
        {
            TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            TreeNode *temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }
    return root;
}

int getNodeCount(TreeNode *root)
{
    int count = 0;

    if (root != NULL)
        count = 1 + getNodeCount(root->left) + getNodeCount(root->right);

    return count;
}

int getLeafCount(TreeNode *root)
{
    int count = 0;

    if (root != NULL)
    {
        if (root->left == NULL && root->right == NULL)
            return 1;
        else
            count = getLeafCount(root->left) + getLeafCount(root->right);
    }

    return count;
}

void preOrder(TreeNode *root)
{
    if(root != NULL)
    {
        printf("[%d] ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TreeNode *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("[%d] ", root->key);
        inOrder(root->right);
    }
}

void postOrder(TreeNode *root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("[%d] ", root->key);
    }
}

int main()
{
    TreeNode *root = NULL;
    
    root = insertNode(root, 35); root = insertNode(root, 68);
    root = insertNode(root, 99); root = insertNode(root, 18);
    root = insertNode(root, 7); root = insertNode(root, 3);
    root = insertNode(root, 12); root = insertNode(root, 26);
    root = insertNode(root, 22); root = insertNode(root, 30);
    
    preOrder(root); printf("\n");getchar();
    printf("%d %d\n", getNodeCount(root), getLeafCount(root));
    //deleteNode(root, 18);preOrder(root); printf("\n");
    
    
    return 0;
}







