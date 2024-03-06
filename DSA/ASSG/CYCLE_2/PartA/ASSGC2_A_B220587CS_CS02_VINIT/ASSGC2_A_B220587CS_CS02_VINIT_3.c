//q3

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

void LEFT_ROT(node *root, node x) {
    node y = x->right;
    x->right = y->left;
    if (y->left != NULL) {
        y->left->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    
    y->left = x;
    x->parent = y;
}

void RIGHT_ROT(node *root, node x) {
    node y = x->left;
    x->left = y->right;
    if (y->right != NULL) {
        y->right->parent = x;
    }

    y->parent = x->parent;

    if (x->parent == NULL) {
        *root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    
    y->right = x;
    x->parent = y;
}

void RB_insert_fixup(node *root, node z) {
    while (z->parent != NULL && z->parent->c == RED) {
        if (z->parent == z->parent->parent->left) { // propagating towards left
            node y = z->parent->parent->right;
            if (y != NULL && y->c == RED) { // Case 1
                z->parent->c = BLACK;
                y->c = BLACK;
                z->parent->parent->c = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    LEFT_ROT(root, z);
                }
                z->parent->c = BLACK;
                z->parent->parent->c = RED;
                RIGHT_ROT(root, z->parent->parent);
            }
        } else {
            node y = z->parent->parent->left;
            if (y != NULL && y->c == RED) { // Case 1
                z->parent->c = BLACK;
                y->c = BLACK;
                z->parent->parent->c = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    RIGHT_ROT(root, z);
                }
                z->parent->c = BLACK;
                z->parent->parent->c = RED;
                LEFT_ROT(root, z->parent->parent);
            }
        }
    }
    (*root)->c = BLACK;
}

node insertRB(node root, int key) {
    node y = NULL;
    node x = root;
    node z = CreateNode(key);

    while (x != NULL) {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    z->parent = y;

    if (y == NULL) {
        root = z;
    } else if (z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }

    z->c = 'R';

    RB_insert_fixup(&root, z);

    return root;
}

void print_tree_helper(node root) {
    if (root == NULL) {
        printf("( ) ");
        return;
    }
    printf("(%d %c ", root->key, root->c);
    print_tree_helper(root->left);
    print_tree_helper(root->right);
    printf(") ");
}

void print_tree(node root) {
    print_tree_helper(root);
    printf("\n");
}

int main() {
    node root = NULL;

    char str[10];

    while(1){
        for(int i =0;i<10;i++){
            str[i]='\0';
        }
        scanf("%s",str);

        if(str[0]=='e'){
            return 0;
        }
        else{
            int key = 0;
            for(int i=0;str[i]!='\0';i++){
                key = key*10 + str[i]-'0';
            }
            root = insertRB(root,key);
            print_tree(root);
            
        }
    }


    return 0;
}
