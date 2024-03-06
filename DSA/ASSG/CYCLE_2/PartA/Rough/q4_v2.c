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

node CreateNode(int x, char color) {
    node newNode = (node)malloc(sizeof(struct RB));
    if (newNode) {
        newNode->key = x;
        newNode->c = color;
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
    node z = CreateNode(key, 'R');

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

node create_tree(node root, char *str, int *index) {
    while (str[*index] == ' ')
        (*index)++;
    if (str[*index] == '(') {
        (*index)++;
        if (str[*index] != ')') {
            int value = 0;
            int sign = 1;

            if (str[*index] == '-') {
                sign = -1;
                (*index)++;
            }

            while (str[*index] >= '0' && str[*index] <= '9') {
                value = value * 10 + (str[*index] - '0');
                (*index)++;
            }

            value *= sign;
            node newNode = CreateNode(value, str[*index + 1]);
            root = newNode;
            *index += 2;

            root->left = create_tree(root->left, str, index);
            root->left->parent = root;

            root->right = create_tree(root->right, str, index);
            root->right->parent = root;

            (*index)++;
        }
    }

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

    char str[200];
    printf("Enter the parenthesis representation of the Red-Black tree: ");
    scanf("%s", str);

    int index = 0;
    root = create_tree(root, str, &index);

    printf("Constructed Red-Black tree: ");
    print_tree(root);

    return 0;
}
