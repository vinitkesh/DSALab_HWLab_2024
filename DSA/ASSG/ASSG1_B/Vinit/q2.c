#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node * node;

node createNode(int data)
{
    node newNode = (node)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct queue{
    node data;
    struct queue *next;
};

struct queue{
    node data;
    struct queue* next;
};

int pop(struct queue **head){
    if(*head ==NULL){
        return NULL;
    }
    int data = (*head)->data;

    (*head) = (*head)->next;
    return data;
}

void push(int data, struct queue **head){
    struct queue *newNode = (struct queue *)malloc(sizeof(struct queue));
    newNode -> data = data;
    newNode -> next = NULL;

    if(head == NULL){
        *head = newNode;
        return;
    }
    newNode -> next = *head;
    *head = newNode;
    return;
    
}

int isEmpty(struct queue *head)
{
    return head == NULL;
}

void levelOrderTraversal(node root)
{
    // Implementation of level order traversal

    node temp = root;

    if(root==NULL){
        return;
    }

    struct queue *head = NULL;//pointer to the head of the queue

    push(&head, temp);
    
    while(!isEmpty(head)){
        temp = head->data;
        printf("%d ", temp->data);

        pop(&head);

        if(temp->left != NULL)
            push(&head, temp->left);
        if(temp->right != NULL)
            push(&head, temp->right);
    }

}

int isBST(node root){
    if(root == NULL){
        return 1;
    }
    int flag = 0;
    if(root->left != NULL && root->left->data < root->data){
        flag = 1;
    }
    if(root->right != NULL && root->right->data > root->data){
        flag = 1;
    }

    return flag && isBST(root->left) && isBST(root->right);
}

int maximumSumBST(node root){
    // Implementation of finding maximum sum of BST in a binary tree

    if(root == NULL){
        return 0;
    }

}

void rightView(node root)
{
    // Implementation of printing the right view of the binary tree
}

int main()
{
    node root = NULL;
    // Read the Parenthesis repr of the tree and construct the tree
    
    char input;
    while (1)
    {
        scanf(" %c", &input);
        switch (input)
        {
            case 'l':
                levelOrderTraversal(root);
                break;
            case 'm':
                
                int maxSum = maximumSumBST(root);
                printf("Maximum sum of BST in the binary tree: %d\n", maxSum);
                
                break;
            case 'r':
                rightView(root);
                break;
            case 'e': 
                break;
            default:
                printf("Invalid input\n");
        }
    }
        
    return 0;
}