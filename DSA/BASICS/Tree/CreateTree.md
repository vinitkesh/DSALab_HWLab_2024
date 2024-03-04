## Creating Tree from paranthesis representation

```
f(string, n, i_ptr){
}
```

```c
nodeconstructTree(char arr[], int n, int i) {
    if (i >= n || arr[i] == ')')
        return NULL;

    // extracting number from the string:
    int num = 0;
    while (i < n && isdigit(arr[i])) {
        num = num * 10 + (arr[i] - '0');
        i++;
    }

    node root = generateNewNode(num);

    if (i < n && arr[i] == '(') {
        i++;
        root->left = constructTree(arr, n, i);
        i++;
    }

    if (i < n && arr[i] == '(') {
        i++;
        root->right = constructTree(arr, n, i);
        i++;
    }

    return root;
}
```

```c

#include <stdio.h>
#include <stdlib.h>

char* getStringInput() {
    char* str = NULL;
    int capacity = 0;
    int length = 0;
    char c;

    while ((c = getchar()) != '\n') {
        if (length == capacity) {
            capacity += 16;
            str = realloc(str, capacity * sizeof(char));
            if (!str) {
                free(str);
                return NULL;
            }
        }
        str[length++] = c;
    }

    str = realloc(str, (length + 1) * sizeof(char));
    if (!str) {
        free(str);
        return NULL;
    }

    str[length] = '\0';
    return str;
}

int main() {
    char* input = getStringInput();
    if (input) {
        printf("You entered: %s\n", input);
        free(input);
    } else {
        printf("Failed to allocate memory for input\n");
    }
    return 0;
}

```