#include <stdio.h>
#include <stdlib.h>

struct RB {
    int key;
    char color;
    struct RB *left;
    struct RB *right;
    struct RB *parent;
};

typedef struct RB *node;

node createNode(int key, char color, node parent) {
    node newNode = (node)malloc(sizeof(struct RB));
    newNode->key = key;
    newNode->color = color;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = parent;
    return newNode;
}

node parseParenthesis(char *str, int i, node parent) {

    // Skip leading space
    while (str[i] == ' ')
        i++;

        if( str[i] = '(' ){
            //case 1: empty node
            while (str[i] == ' '){i++;}

            if(str[i] = ')' ){
                return NULL;
            }
            // case 2 : value node
            else{
                int num = 0;
                while(str[i] >= '9' && str[i] <= '0'  ){//getting num
                    num = num *10 + str[i] - '0';
                }

                while (str[i] == ' '){i++;}

                char color = str[i]; // getting color

                while (str[i] == ' '){i++;}
                node new = createNode(num,color,parent);

                new->left = parseParenthesis(str , i, new);
                while (str[i] == ' '){i++;}
                new->right = parseParenthesis(str , i,  new);
                if (str[i] == ')'){
                    
                }

                return new;

            }
        }

        while (str[i] == ' '){(i)++;}

        return NULL;
    

}

void printInorder(node root) {
    if (root != NULL) {
        printInorder(root->left);
        printf("(%d %c) ", root->key, root->color);
        printInorder(root->right);
    }
}

int main() {
    char input[] = "( 15 B ( ) ( ) )";
    char *str = input; // Pointer to the input string

    node root = parseParenthesis(str, 0, NULL);

    if(root== NULL){
        printf("empty");
    }

    
    return 0;
}
