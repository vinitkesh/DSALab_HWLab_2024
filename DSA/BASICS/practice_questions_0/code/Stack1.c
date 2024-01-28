#include <stdio.h>

struct stack {
    int arr[10000];
    int head;
};

struct stack st;

void push(int x) {
    st.arr[++st.head] = x;
}

void pop() {
    if (st.head != -1) 
        st.head--;
}

void peek() {
    if (st.head != -1) 
        printf("%d\n", st.arr[st.head]);
}

void display() {
    int y = st.head;
    while (y>=0) {
        printf("%d ", st.arr[y]);
        y--;
    }
    printf("\n");
}

int main() {
    st.head = -1;
    char c = '1';
    int x;
    while (c != 't') {
        scanf(" %c", &c); // Use a space before %c to consume any leading whitespace
        switch (c) {
            case 'p':
                
                scanf("%d", &x);
                push(x);
                break;

            case 'r':
                pop();
                break;

            case 's':
                peek();
                break;

            case 'd':
                display();
                break;
        }
    }
    return 1;
}
