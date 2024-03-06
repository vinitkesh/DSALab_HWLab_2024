#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define the AVL node structure
typedef struct AVL
{
    int val;
    int height;
    struct AVL *left;
    struct AVL *right;
    struct AVL *parent;
} *node;

// Function to create a new node
node CreateNode(int x)
{
    node newNode = (node)malloc(sizeof(struct AVL));
    if (newNode)
    {
        newNode->val = x;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = NULL;
        newNode->height = 1;
    }
    return newNode;
}

int max(int x, int y)
{
    return x > y ? x : y;
}

// Function to get the height of a node
int height(node T)
{
    if (T == NULL)
        return 0;
    return T->height;
}

int LRot = 0, RRot = 0;

// Function to perform right rotation
node R(node root)
{
    node A = root;
    node B = root->left;
    node AR = A->right;
    node BR = B->right;
    node C = B->left;

    // Perform the rotation
    A->right = B;
    B->left = BR;
    B->right = AR;
    A->left = C;

    int temp = A->val;
    A->val = B->val;
    B->val = temp;

    // Update heights
    A->height = 1 + max(height(A->right), height(A->left));
    B->height = 1 + max(height(B->right), height(B->left));

    RRot++;

    // Return the new root (B)
    return root;
}

// Function to perform left rotation
node L(node root)
{
    // Store the relevant nodes
    node A = root;
    node B = root->right;
    node AL = A->left;
    node BL = B->left;
    node C = B->right;

    // Perform the rotation
    A->left = B;
    A->right = C;
    B->right = BL;
    B->left = AL;
    

    int temp = A->val;
    A->val = B->val;
    B->val = temp;

    // Update heights
    A->height = 1 + max(height(A->left), height(A->right));
    B->height = 1 + max(height(B->left), height(B->right));

    // Return the new root (B)
    LRot++;
    return root;
}



// Function to insert a node into AVL tree
node AVL_insert(node root, int key)
{
    if (root == NULL)
    { // empty tree or leaf node
        node new = CreateNode(key);
        return new;
    }
    else if (key > root->val)
    {
        root->right = AVL_insert(root->right, key);
    }
    else if (key < root->val)
    {
        root->left = AVL_insert(root->left, key);
    }
    else
    {
        return root; // node already exists
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int bf = height(root->left) - height(root->right);

    if (bf <= -2 && key > root->right->val)
    {
        root = L(root);
    }
    else if (bf >= 2 && key < root->left->val)
    {
        root = R(root);
    }

    if (bf >= 2 && key > root->left->val)
    {
        root->left = L(root->left);
        return R(root);
    }
    if (bf <= -2 && key < root->right->val)
    {
        root->right = R(root->right);
        return L(root);
    }

    return root;
}

// Function to perform preorder traversal of AVL tree
void AVL_preorder(node root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->val);
    AVL_preorder(root->left);
    AVL_preorder(root->right);
}

int search(node root, int key)
{
    if (root == NULL)
    { // empty tree / reached leaf
        return 0;
    }
    else if (key < root->val)
    { // go left
        return search(root->left, key);
    }
    else if (key > root->val)
    {
        return search(root->right, key); // go right
    }
    else
    { // found key
        return 1;
    }
    return 1;
}

void AVL_find(node root, int key)
{
    node x = root;
    if (search(root, key))
    {
        while (x!=NULL)
        {
            printf("%d ", x->val);
            if (key == x->val)
            {
                break;
            }
            else if (key > x->val)
                x = x->right;
            else
                x = x->left;
        }
        printf("\n");
    }
    else
    {
        printf("%d\n", -1);
    }
}

node AVL_cal(node root)
{
    printf("%d %d\n", LRot, RRot);
    return NULL;
}

// Main function
int main()
{
    node root = NULL;
    char menu = 'o';

    int key;
    int a;

    while (1)
    {
        scanf(" %c", &menu); // Space before %c to consume newline characters

        switch (menu)
        {
        case 'i':

            scanf("%d", &a);
            root = AVL_insert(root, a);
            break;

        case 'x':

            scanf("%d", &key);
            AVL_find(root, key);

            break;

        case 'p':
            AVL_preorder(root);
            printf("\n");
            break;

        case 's':
            AVL_cal(root);
            break;

        case 'e':
            // Free memory before exiting
            // FreeMemory(root);
            return 0;
            break;

        default:
            printf("Invalid menu option\n");
            break;
        }
    }

    return 0;
}
