#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct AVL{
    int val;
    int height;
    struct AVL * left;
    struct AVL * right;
    struct AVL * parent;

}* node;

int rRot=0, lRot=0;

int max(int x, int y){
    return x>y ? x : y;
}

node CreateNode(int x){
    node newNode =  (node)malloc(sizeof(struct AVL));
    newNode->val    = x;
    newNode->left   = NULL;
    newNode->right  = NULL;
    newNode->parent = NULL;
    newNode->height = 1;
}


// node constructTree(char arr[], int n, int i) {
//     if (i >= n || arr[i] == ')')
//         return NULL;

//     // extracting number from the string:
//     int num = 0;
//     while (i < n && isdigit(arr[i])) {
//         num = num * 10 + (arr[i] - '0');
//         i++;
//     }

//     node root = CreateNode(num);

//     if (i < n && arr[i] == '(') {
//         i++;
//         root->left = constructTree(arr, n, i);
//         i++;
//     }

//     if (i < n && arr[i] == '(') {
//         i++;
//         root->right = constructTree(arr, n, i);
//         i++;
//     }

//     return root;
// }

int height(node T)
{
    if (T == NULL)
        return 0;
    return T->height;
}

node R( node root){
    node A=root,B=root->left,C=root->left->left;
    node AL=A->left,BL=B->left;

    node temp = A;
    A = B;
    B = temp;
    

    return root;

}
node L( node root){
//   A
//  / \
// AL  B
//    / \
//   BL  C
    node A=root,B=root->right,C=root->right->right;
    node AL=A->right,BL=B->right;

    
    A->left = B;
    A->right = C;

    B->left = BL;
    B->right = AL;   

//    A
//   / \
//  B   C
// / \ 
//BL  AL


    node temp = A;
    A = B;
    B = temp;

//    B
//   / \
//  A   C
// / \ 
//BL  AL

    // Updating height:
    // height of A and B changes unpredictably, so we should call the height function
    // height of C decreases by 1;
    // hieght of AL inc by 1

    return A;
}
node LR( node root){
    return root;
}
node RL( node root){
    return root;
}

node AVL_insert(node root, int key);
node AVL_find(node root, int key);
void AVL_preorder(node root);
int AVL_cal(node root,int key);



////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    // char input[100];
    // scanf("%s", input);

    // int len = strlen(input);
    // node root = constructTree(input, len, 0);

    // printf("%s",input);

    node root = NULL;

    char menu='o';
    

    while(1){

        scanf("%c",menu);

        switch (menu){
            case 'i':
            
                int a;
                scanf("%d", &a);
                root = AVL_insert(root, a);
                break;
            
            case 'x':
            
                int key;scanf("%d", &key);

                node result = AVL_find(root, key);
                if (result != NULL)
                {
                    printf("Path from root to node containing key: ");
                }
                else
                {
                    printf("-1\n");
                }
                break;
            
            case 'p':
                AVL_preorder(root);
                break;

            case 's':
            
                int point;
                scanf("%d", &point);
                AVL_cal(root, point);
                break;
            
            case 'e':
                return 0;
                break;
            default:
                printf("Invalid menu option\n");
                break;
        }

    }

    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
node AVL_insert(node root, int key){
    if(root == NULL){ // empty tree or leaf node
        node new = CreateNode(key);
        return new;
    }
    else if(key > root->right->val){
        root->right = AVL_insert(root->right,key);
    }
    else if(key < root->right->val){
        root->left = AVL_insert(root->left,key);
    }
    else{
        return root;//node already exists
    }

    root->height = 1 + max(height(root->left),height(root->right));

    int bf = height(root->left) - height(root->right);

    if( bf <= -2 && key > root->right->val){
        root = L(root);
    }
    else if(bf >= 2 && key < root->left->val){
        root = R(root);
    }

    if(bf >= 2 && key > root->left->val){
        root->left = L(root->left);
        return R(root);
    }
    if(bf <= -2 && key < root->right->val ){
        root->right = R(root->right);
        return L(root);
    }

    return root;
}

void AVL_preorder(node root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->val);
    AVL_preorder(root->left);
    AVL_preorder(root->right);
}

node AVL_find(node root, int key){
    return root;
}
int AVL_cal(node root,int key){
    return 0;
}