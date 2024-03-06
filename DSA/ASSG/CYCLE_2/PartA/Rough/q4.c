#include <stdio.h>
#include <stdlib.h>

struct RB {
    int key;
    char c;
    struct RB *left;
    struct RB *right;
    struct RB *parent;
};

typedef struct RB *node;

char RED = 'R';
char BLACK = 'B';

node CreateNode(int x) {
    node newNode = (node)malloc(sizeof(struct RB));
    if (newNode) {
        newNode->key = x;
        newNode->c = 'B';
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}





int main() {
    node root = NULL;
    node parent = NULL;

    char str[200];
    for(int i =0;i<200;i++){
            str[i]='\0';
        }
    scanf("%s",str);

    root = create_tree(root,str,parent);


    return 0;
}
