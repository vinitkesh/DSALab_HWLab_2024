//q2

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node* next;
};

typedef struct Node* node;

node createNode(int k) {
    node newNode = (node)malloc(sizeof(struct Node));
    newNode->key = k;
    newNode->next = NULL;
    return newNode;
}

void listInsert(node* L, node x) {
    if (*L == NULL) {
        *L = x;
    } else {
        node temp = *L;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = x;
    }
}

void listDelete(node* L, int i) {
    if (*L == NULL) {
        printf("-1\n");
        return;
    }
    if (i == 1) {
        node temp = *L;
        *L = (*L)->next;
        printf("%d\n", temp->key);
        free(temp);
        return;
    }

    
    node temp = *L;
    int count = 1;
    while (temp != NULL && count < i - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("-1\n");
        return;
    }
    node deletedNode = temp->next;
    temp->next = temp->next->next;
    printf("%d\n", deletedNode->key);
    free(deletedNode);
}

void listRemoveDuplicates(node* L) {
    if (*L == NULL) {
        return;
    }

    int hash[1000] = {0};
    node current = *L;
    node prev = NULL;

    while (current != NULL) {
        if (hash[current->key] == 1) {
            // Duplicate found, remove the node
            if (prev == NULL) {
                // If the duplicate is the first node
                node temp = *L;
                *L = (*L)->next;
                free(temp);
                current = *L;
            } else {
                // If the duplicate is not the first node
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
        } else {
            // First occurrence of the number
            hash[current->key] = 1;
            prev = current;
            current = current->next;
        }
    }
}


char listIsPalindrome(node head) {
  
    node L= head;
    if (L == NULL) {
        return 'N';
    }

    int reverse[1000];
    int n=0;
    L=head;
    while(L != NULL) {
        reverse[n]=L->key;
        n++;
        L = L->next;
    }
    
    int i=0;
    L=head;
    while (L != NULL) {
        if (L->key != reverse[n-i-1]) {
            return 'N';
        }
        i++;
        L = L->next;
    }

    return 'Y';
}

void listDisplay(node L) {
    node temp = L;
    while (temp != NULL) {
        printf("%d ", temp->key);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    node L = NULL;
    char choice;
    int key, index;
    do {
        scanf(" %c", &choice);
        switch (choice) {
            case 'a':
                scanf("%d", &key);
                listInsert(&L, createNode(key));
                break;
            case 'r':
                scanf("%d", &index);
                listDelete(&L, index);
                break;
            case 'd':
                listRemoveDuplicates(&L);
                listDisplay(L);
                break;
            case 'p':
                printf("%c\n", listIsPalindrome(L));
                break;
            case 's':
                listDisplay(L);
                break;
        }
    } while (choice != 'e');
    return 0;
}
