#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the AVL node structure
typedef struct AVL
{
    int key;
    int val;
    int height;
    struct AVL *left;
    struct AVL *right;
} *node;

// Function to create a new node
node CreateNode(int x, int val){
    node newNode = (node)malloc(sizeof(struct AVL));
    if (newNode){
        newNode->key = x;
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 1;
    }
    return newNode;
}

int max(int x, int y){
    return x > y ? x : y;
}

int height(node T){
    if (T == NULL)
        return 0;
    return T->height;
}

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

    int temp = A->key;
    int val = A->val;
    A->key = B->key;
    A->val = B->val;
    B->key = temp;
    B->val = val;

    // Update heights
    A->height = 1 + max(height(A->right), height(A->left));
    B->height = 1 + max(height(B->right), height(B->left));

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

    int temp = A->key;
    int val = A->val;
    A->key = B->key;
    A->val = B->val;
    B->key = temp;
    B->val = val;

    // Update heights
    A->height = 1 + max(height(A->left), height(A->right));
    B->height = 1 + max(height(B->left), height(B->right));

    // Return the new root (B)
    return root;
}

// Function to insert a node into AVL tree
// a
node AVL_insert(node root, int key, int val){
    if (root == NULL)
    { // empty tree or leaf node
        node new = CreateNode(key, val);
        return new;
    }

    else if (key > root->key)
        root->right = AVL_insert(root->right, key, val);

    else if (key < root->key)
        root->left = AVL_insert(root->left, key, val);

    else{
        root->val = val; // update value if key already exists
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int bf = height(root->left) - height(root->right);

    if (bf <= -2 && key > root->right->key)
        root = L(root);

    else if (bf >= 2 && key < root->left->key)
        root = R(root);

    if (bf >= 2 && key > root->left->key){
        root->left = L(root->left);
        return R(root);
    }
    if (bf <= -2 && key < root->right->key){
        root->right = R(root->right);
        return L(root);
    }

    return root;
}
// b.
void lower_bound(node root, int key){
    // gives element with same or larger key
    if(root==NULL){
        printf("%d",-1);
        return;
    }
    else if(key > root->key){
        printf("%d %d\n",root->key,root->val);
        return;
    }
    else if(key< root->key){
        lower_bound(root->left->right,key);
    }
    else{
        printf("%d %d",root->key,root->val);
    }
}
// c.
void find(node root,int key){
    if (root == NULL)
    { // empty tree / reached leaf
        printf("%d",-1);
    }
    else if (key < root->key)
    { // go left
        find(root->left, key);
        return;
    }
    else if (key > root->key)
    {
        find(root->right, key); // go right
        return;
    }
    else
    { // found key
        printf("%d %d",root->key,root->val);
    }
    return;
}
//d.
int size(node root){
    if (root == NULL)
        return 0;
    return 1 + size(root->left) + size(root->right);
}
// e. 
int empty(node root){
    return root == NULL ? 1 : 0;
}
// f.
void printElements(node root)
{
    if (root == NULL)
    {
        return;
    }

    printElements(root->left);
    printf("%d ", root->key);
    printElements(root->right);
}

int search(node root, int key)
{
    if (root == NULL)
    { // empty tree / reached leaf
        return 0;
    }
    else if (key < root->key)
    { // go left
        return search(root->left, key);
    }
    else if (key > root->key)
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
        while (x != NULL)
        {
            printf("%d ", x->key);
            if (key == x->key)
            {
                break;
            }
            else if (key > x->key)
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




// Main function
int main()
{
    node root = NULL;
    char menu = 'o';

    int val, key;
    int a;

    while (1)
    {
        scanf(" %c", &menu); // Space before %c to consume newline characters

        switch (menu)
        {
        case 'i':
            scanf("%d %d", &key, &val);
            root = AVL_insert(root, key, val);
            break;

        case 'l':
            scanf("%d", &key);

            if(search(root,key)){
                find(root, key);
                break;
            }
            lower_bound(root,key);
            break;

        case 'f':
            scanf("%d", &key);
            find(root, key);
            break;

        case 's':
            printf("%d\n", size(root));
            break;

        case 'e':
            printf("%d\n", empty(root));
            break;

        case 'p':
            printElements(root);
            printf("\n");
            break;

        case 't':
            free(root);
            return 0;
            break;

        default:
            printf("Invalid menu option\n");
            break;
        }
    }

    return 0;
}
