#include <stdio.h>
#include <stdlib.h>

// Objective: Implement menu driven programme for :
// - Character ‘p’ call - Postorder(T) - is to print the post order traversal of a tree.
// – Character ‘z’ call - ZIG ZAG(T) - is to print the zig-zag traversal of the tree.
// – Character ‘m’ call - Level Max(T) - is to print max elements at each level.
// – Character ‘d’ call - Diameter(T) - is to print the diameter of a binary tree.
// – Character ‘s’ call - Left Leaf Sum(T) - is to print the sum of all left leaf nodes.

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Node * node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void postorder(node root);
void zigzag(node root);
void levelMax(node root);
void diameter(node root);
void leftLeafSum(node root);

struct queue{
    node data;
    struct queue *next;
};

void pop(struct queue **head){
    struct queue *temp = *head;
    *head = (*head)->next;
    free(temp);
    return ;
}
void push(struct queue **head, node data)
{
    struct queue *newNode = (struct queue *)malloc(sizeof(struct queue));
    newNode->data = data;
    newNode->next = NULL;
    
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct queue *temp = *head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

int isEmpty(struct queue *head)
{
    return head == NULL;
}

int search(int arr[], int start, int end, int data)
{
    for(int i = start; i <= end; i++)
    {
        if(arr[i] == data)
        {
            return i;
        }
    }
    return -1;
}

node createTree(int inorder[], int preorder[], int i1, int e1, int i2, int e2){
    if(i1 > e1 || i2 > e2)
        return NULL;

    node root = createNode(preorder[i2]);

    int j = search(inorder, i1, e1, root->data);
    
    root->left = createTree(inorder, preorder, i1, j-1, i2+1, i2 + (j - i1));
    root->right = createTree(inorder, preorder, j+1, e1, i2 + (j - i1) + 1, e2);

    return root;

}


int main()
{
    int n;
    scanf("%d", &n);
    node root = NULL;

    int inorder[n], preorder[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &inorder[i]);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &preorder[i]);
    }

    root = createTree(inorder, preorder, 0, n-1,0, n-1);

    char ch;
    while(1)
    {
        scanf(" %c", &ch);
        switch(ch)
        {
            case 'p':
                postorder(root);
                break;
            case 'z':
                zigzag(root);
                break;
            case 'm':
                levelMax(root);
                break;
            case 'd':
                diameter(root);
                break;
            case 's':
                leftLeafSum(root);
                break;
            case 'e':
                return 0;
        }
    }


        
    return 0;
}