#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

struct tree {
    struct tree *left;
    struct tree *right;
    int nodeValue;
};

struct tree *generateNewNode(int key) {
    struct tree *newNode;
    newNode = (struct tree *)malloc(sizeof(struct tree));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->nodeValue = key;
    return newNode;
}

struct tree *constructTree(char arr[], int size, int *preIndex) {
    if (*preIndex >= size || arr[*preIndex] == ')')
        return NULL;

    int num = 0;
    while (*preIndex < size && isdigit(arr[*preIndex])) {
        num = num * 10 + (arr[*preIndex] - '0');
        (*preIndex)++;
    }

    struct tree *root = generateNewNode(num);

    if (*preIndex < size && arr[*preIndex] == '(') {
        (*preIndex)++;
        root->left = constructTree(arr, size, preIndex);
        (*preIndex)++;
    }

    if (*preIndex < size && arr[*preIndex] == '(') {
        (*preIndex)++;
        root->right = constructTree(arr, size, preIndex);
        (*preIndex)++;
    }

    return root;
}

void Rightview(struct tree *root) {
    if (root == NULL) return;
    
    printf("%d ", root->nodeValue);
    if (root->right != NULL)
        Rightview(root->right);
    else
        Rightview(root->left);
}

int isBST(struct tree *root, int min, int max) {
    int left, right;
    if (root == NULL)
        return 1;
    if (root->nodeValue <= min || root->nodeValue >= max)
        return 0;

    return (isBST(root->left, min, root->nodeValue) && isBST(root->right, root->nodeValue, max));
}

int findmaxBST(struct tree *root) {
    int sum, leftSum, rightSum;

    if (root == NULL)
        return 0;

    if (isBST(root, INT_MIN, INT_MAX)) {
        sum = 0;
        sum += (root->left != NULL) ? findmaxBST(root->left) : 0;
        sum += (root->right != NULL) ? findmaxBST(root->right) : 0;
        return sum + root->nodeValue;
    } else {
        leftSum = findmaxBST(root->left);
        rightSum = findmaxBST(root->right);
        return (leftSum > rightSum) ? leftSum : rightSum;
    }
}

void LevelTraversal(struct tree *root) {
    struct tree *queue[100];
    int front = 0, rear = 0;

    printf("%d ", root->nodeValue);
    queue[rear++] = root;

    while (front < rear) {
        root = queue[front++];
        if (root->left) {
            printf("%d ", root->left->nodeValue);
            queue[rear++] = root->left;
        }
        if (root->right) {
            printf("%d ", root->right->nodeValue);
            queue[rear++] = root->right;
        }
    }
}

int main() {
    char inputString[100];

    scanf("%s", inputString);

    int preIndex = 0;
    int size = strlen(inputString);
    struct tree *root = constructTree(inputString, size, &preIndex);
    char input;
   
    while (1) {
        scanf("%c", &input);
        switch (input) {
            case 'l':
                LevelTraversal(root);
                printf("\n");
                break;
            case 'm':
                printf("%d\n", findmaxBST(root));
                break;
            case 'r':
                Rightview(root);
                printf("\n");
                break;
            case 'e':
                return 0;
                break;
        }
    }
}
