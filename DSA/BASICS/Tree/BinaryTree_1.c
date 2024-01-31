#include <stdio.h>
#include <stdlib.h>

struct BT
{
    int data;
    struct BT *left, *right;
};

typedef struct BT * node;

node createNode(int x);
void printTree(node root);


int main()
{
    
    return 0;
}

node createNode(int x){
    node new = (node)malloc(sizeof(struct BT));

    new->data = x;
    new->left = NULL;
    new->right = NULL;

}

void printTree(node root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    printTree(root->left);
    printTree(root->right);
}

void createtreefrominorderpreorder (int inorder[], int preorder[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (inorder[i] == preorder[0])
            break;
    }
    if (i != 0)
        createtreefrominorderpreorder (inorder, preorder + 1, i);
    if (i != n - 1)
        createtreefrominorderpreorder (inorder + i + 1, preorder + i + 1, n - i - 1);
    
    printf ("%d ", preorder[0]);
}


