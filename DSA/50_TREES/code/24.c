#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

typedef struct node * node;

int search(int arr[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1; // Element not found
}

node constructTree(int preorder[], int preStart, int preEnd, int inorder[], int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    node root = newNode(preorder[preStart]);
    int elem = search(inorder, inStart, inEnd, root->data);

    int nleft = elem - inStart;
    int nright = inEnd - elem;

    root->left = constructTree (preorder,
                                preStart + 1, 
                                preStart + nleft, 
                                
                                inorder, 
                                inStart, 
                                elem - 1);

    root->right = constructTree(preorder, 
                                preStart + nleft + 1, 
                                preEnd, 
                                inorder, 
                                elem + 1, 
                                inEnd);

    return root;
}


void printInorder(struct node* node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main() {
    int preorder[] = { 10, 20, 40, 50, 30, 60 };
    int inorder[] = { 40, 20, 50, 10, 60, 30 };
    int preSize = sizeof(preorder) / sizeof(preorder[0]);
    int inSize = sizeof(inorder) / sizeof(inorder[0]);

    int preStart = 0, preEnd = preSize - 1;
    int inStart = 0, inEnd = inSize - 1;

    struct node* root = constructTree(preorder, preStart, preEnd, inorder, inStart, inEnd);

    printf("Inorder traversal of constructed tree is: ");
    printInorder(root);
    printf("\n");

    return 0;
}
