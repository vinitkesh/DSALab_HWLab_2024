#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity);
bool isEmpty(struct Stack* stack);
void push(struct Stack* stack, char item);
char pop(struct Stack* stack);
bool checkRedundancy(char* str);
void findRedundant(char* str);
void displayStack(struct Stack* stack);

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int main() {
    int n;
    scanf("%d", &n);
    char str[n];
    scanf("%s", str);
    findRedundant(str);
    return 0;
}

bool isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}

bool checkRedundancy(char* str) {
    struct Stack* stack = createStack(strlen(str));

    for (int i = 0; str[i]; i++) {
        if (str[i] == ')') {
            char top = pop(stack);
            bool flag = true;

            while (!isEmpty(stack) && top != '(') {
                if (top == '+' || top == '-' || top == '*' || top == '/')
                    flag = false;

                top = pop(stack);
            }

            if (flag == true)
                return true;
        } 
        else
            push(stack, str[i]);
    }
    return false;
}

void findRedundant(char* str) {
    bool ans = checkRedundancy(str);
    if (ans == true)
        printf("1\n");
    else
        printf("0\n");
}

void displayStack(struct Stack* stack) {
    
    for (int i = 0; i <= stack->top; i++) {
        printf("%c ", stack->array[i]);
    }
    printf("\n");
}
