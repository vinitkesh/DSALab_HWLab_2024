#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

typedef struct Node *node;

node newnode(int value) {
    node newNode = (node)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node insertnode(node root, int key) {
    if (root == NULL) 
        return newnode(key);

    node current = root;
    node parent = NULL;

    while (current != NULL) {
        parent = current;

        if (key < current->value)
            current = current->left;
        else if (key > current->value)
            current = current->right;
        else
            return root;
    }

    node newNode = newnode(key);

    if (key < parent->value)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

void printrange(node root, int min, int max) {
    if (root == NULL) 
        return;

    if (root->value > min)
        printrange(root->left, min, max);

    if (root->value >= min && root->value <= max)
        printf("%d ", root->value);

    if (root->value < max)
        printrange(root->right, min, max);
}

int printAncestors(node root, int key) {
    if (root == NULL) 
        return 0;

    if (root->value == key || printAncestors(root->left, key) || printAncestors(root->right, key)) {
        printf("%d ", root->value);
        return 1;
    }

    return 0;
}

int main() {
    node root = NULL;
    char command;
    int min, max, key;

    char treeInput[100];
    fgets(treeInput, sizeof(treeInput), stdin);

    int index = 0;
    while (treeInput[index] != '\0') {
        if (treeInput[index] >= '0' && treeInput[index] <= '9') {
            int key = 0;
            while (treeInput[index] >= '0' && treeInput[index] <= '9') {
                key = key * 10 + (treeInput[index] - '0');
                index++;
            }
            root = insertnode(root, key);
        } else {
            index++;
        }
    }

    do {
        scanf(" %c", &command);
        switch (command) {
            case 'p':
                scanf("%d %d", &min, &max);
                printrange(root, min, max);
                printf("\n");
                break;
            case 'a':
                scanf("%d", &key);
                printAncestors(root, key);
                printf("\n");
                break;
            case 'e':
                break;
            default:
                printf("Invalid\n");
                break;
        }

    } while (command != 'e');

    return 0;
}