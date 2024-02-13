#include <stdio.h>

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

int main()
{
    node root = NULL;

    printf("Enter the number of elements to be inserted: ");
    int n;
    scanf("%d", &n);

    printf("Enter the elements: ");
    for(int i = 0; i < n; i++)
    {
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
    }
    


    
    return 0;
}
