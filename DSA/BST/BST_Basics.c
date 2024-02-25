#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
//gg
typedef struct Node* node;

node createNode(int data)
{
    node temp = (node)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

node insert(node root, int data);
node delete(node root, int data);
node search(node root, int data);
node inorderSuccessor(node root);
void printTree(node root);

int main()
{
    node root = NULL;

    printf("Enter the number of elements to be inserted: ");
    int n;
    scanf("%d", &n);

    printf("Enter the elements: ");
    for(int i = 0; i < n; i++){
        int data;
        scanf("%d", &data);
        root = insert(root, data);
    }

    char option='y';

    // s : search
    // i : insert
    // d : delete
    // e : exit

    while(1){
        printf("Enter the option: ");
        scanf(" %c", &option);
        if(option == 'i'){
            printf("Enter the element to be inserted: ");
            int data;
            scanf("%d", &data);
            root = insert(root, data);
        }
        else if(option == 'd'){
            printf("Enter the element to be deleted: ");
            int data;
            scanf("%d", &data);
            root = delete(root, data);
        }
        else if(option == 's'){
            printf("Enter the element to be searched: ");
            int data;
            scanf("%d", &data);
            node temp = search(root, data);
            if(temp == NULL){
                printf("Element not found\n");
            }
            else{
                printf("Element found\n");
            }
        }
        else if(option == 'e'){
            break;
        }
        else if(option == 'p'){
            printTree(root);
            printf("\n");
        }
        else{
            printf("Invalid option\n");
        }
    } 
    
    return 0;
}

node search(node root, int data)
    {
        if(root == NULL || root->data == data){
            return root;
        }
        if(data < root->data){
            return search(root->left, data);
        }
        else{
            return search(root->right, data);
        }
        return NULL;
    }
node insert(node root, int data){
    if(root==NULL){
        return createNode(data);
    }
    if(data < root->data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
}

node delete(node root, int data){

    // Case 0: If the tree is empty
    if(root == NULL){
        return root;
    }
    // Case 1: If the node to be deleted is a leaf node
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    // Case 2: If the node to be deleted has only one child
    else{
        // Find the inorder successor of the node to be deleted
        node temp = inorderSuccessor(search(root, data));
        // Copy the data of the inorder successor to the current node
        root->data = temp->data;
        // Delete the inorder successor node recursively
        root->right = delete(root->right, temp->data);
        return root;
    }
}

// Function to find the inorder successor of a given node
node inorderSuccessor(node root){
    node temp = root;
    // Traverse to the leftmost node to find the inorder successor
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

void printTree(node root){
    if(root == NULL){
        return;
    }
    printTree(root->left);
    printf("%d ", root->data);
    printTree(root->right);
}
