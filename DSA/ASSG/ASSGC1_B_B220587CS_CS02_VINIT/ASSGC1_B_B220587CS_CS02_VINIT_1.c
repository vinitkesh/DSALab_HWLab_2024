#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* root = NULL;

typedef struct Node* node;

node createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node buildTree(int inorder[], int preorder[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    node newNode = createNode(preorder[*preIndex]);
    (*preIndex)++;

    if (inStart == inEnd) {
        return newNode;
    }

    int inIndex;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == newNode->data) {
            inIndex = i;
            break;
        }
    }

    newNode->left = buildTree(inorder, preorder, inStart, inIndex - 1, preIndex);
    newNode->right = buildTree(inorder, preorder, inIndex + 1, inEnd, preIndex);

    return newNode;
}

void postorder(node root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void zigzagtraversal(struct Node* root)
{
    if (root == NULL) {
        return;
    }

    bool leftToRight = true;
    node* currentLevel = (node*)malloc(sizeof(node) * 1000000);
    node* nextLevel = (node*)malloc(sizeof(node) * 1000000);
    int currentLevelSize = 0;
    int nextLevelSize = 0;

    currentLevel[currentLevelSize++] = root;

    while (currentLevelSize > 0) {
        node temp = currentLevel[--currentLevelSize];
        printf("%d ", temp->data);

        if (leftToRight) { //goes left to right 
            if (temp->left) {
                nextLevel[nextLevelSize++] = temp->left;
            }
            if (temp->right) {
                nextLevel[nextLevelSize++] = temp->right;
            }
        } 
        
        else { //goes right to left
            if (temp->right) {
                nextLevel[nextLevelSize++] = temp->right;
            }
            if (temp->left) {
                nextLevel[nextLevelSize++] = temp->left;
            }
        }

        if (currentLevelSize == 0) {
            leftToRight = !leftToRight;
            node* tempPtr = currentLevel;
            currentLevel = nextLevel;
            nextLevel = tempPtr;
            currentLevelSize = nextLevelSize;
            nextLevelSize = 0;
        }
    }

    free(currentLevel);
    free(nextLevel);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(node root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight) ;
}

void level_max(node root) {
    if (root == NULL) {
        return;
    }

    int h = height(root);
    int* maxValues = (int*)malloc(sizeof(int) * h);

    for (int i = 0; i < h; i++) {
        maxValues[i] = INT_MIN;
    }

    node* queue = (node*)malloc(sizeof(node) * 1000000);
    int front = -1, rear = -1;
    queue[++rear] = root;

    int level = 0;
    while (front != rear) {
        int count = rear - front;

        for (int i = 0; i < count; i++) {
            node temp = queue[++front];
            maxValues[level] = max(maxValues[level], temp->data);

            if (temp->left) {
                queue[++rear] = temp->left;
            }

            if (temp->right) {
                queue[++rear] = temp->right;
            }
        }

        level++;
    }

    for (int i = 0; i < h; i++) {
        printf("%d ", maxValues[i]);
    }

    free(maxValues);
    free(queue);
}

int diameter(node root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);

    return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
}

int isLeaf(node root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    return 0;
}

int left_leaf_sum(node root) {
    if (root == NULL) {
        return 0;
    }

    int sum = 0;
    node* stack = (node*)malloc(sizeof(node) * 1000000);
    int top = -1;
    stack[++top] = root;

    while (top != -1) {
        node temp = stack[top--];

        if (isLeaf(temp->left)) {
            sum += temp->left->data;
        }

        if (temp->right) {
            stack[++top] = temp->right;
        }

        if (temp->left) {
            stack[++top] = temp->left;
        }
    }

    free(stack);
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n];
    int preorder[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    int preIndex = 0;
    root = buildTree(inorder, preorder, 0, n - 1, &preIndex);

    char option;
    while (1) {
        scanf(" %c", &option);

        if (option == 'p') {
            postorder(root);
            printf("\n");
        } else if (option == 'z') {
            zigzagtraversal(root);
            printf("\n");
        } else if (option == 'm') {
            level_max(root);
            printf("\n");
        } else if (option == 'd') {
            int dia = diameter(root);
            printf("%d\n", dia);
        } else if (option == 's') {
            int sum = left_leaf_sum(root);
            printf("%d\n", sum);
        } else if (option == 'e') {
            break;
        }
    }

    return 0;
}
