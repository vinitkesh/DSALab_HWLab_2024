// Stack implementation by Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL; 

void push(int value);
void pop();
void display();
int peek();

int main() {
    char choice;
    int value;
    while (1) {
        printf("Stack Menu:\n");
        printf("a. Push\n");
        printf("b. Pop\n");
        printf("c. Display\n");
        printf("d. Peek\n");
        printf("e. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 'b':
                pop();
                break;
            case 'c':
                display();
                break;
            case 'd':
                printf("Top element: %d\n", peek());
                break;
            case 'e':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (top == NULL)
        return;
    struct Node* temp = top;
    top = top->next;
    free(temp);
}

void display() {
    if (top == NULL) {
        return;
    }
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int peek() {
    if (top == NULL) {
        return -1;
    }
    return top->data;
}
