#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
typedef struct Node{
    int data;
    struct Node *next;
} Node;

// Function to create a new node
Node *createNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL){
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node **head, int data){
    Node *newNode = createNode(data);
    if (*head == NULL){
        *head = newNode;
    }
    else{
        Node *temp = *head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node *head){
    printf("Linked List: ");
    while (head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to perform DFS on a node
void dfs(Node **lists, int node, int *visited) {
    visited[node] = 1; // Mark the current node as visited

    // Traverse the linked list of the current node
    Node *temp = lists[node - 1];
    while (temp != NULL) {
        if (!visited[temp->data]) {
            dfs(lists, temp->data, visited); // Recursive call for adjacent nodes
        }
        temp = temp->next;
    }
}

// Function to count the number of islands
int countIslands(Node **lists, int n) {
    int *visited = (int *)calloc(n + 1, sizeof(int)); // Array to track visited nodes
    int islandCount = 0;

    for(int i=0;i<n+1;i++){
        visited[i]=0;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(lists, i, visited); // Perform DFS on unvisited nodes
            islandCount++;
        }
    }

    free(visited);
    return islandCount;
}


int main(){
    int n;
    printf("Enter the number of linked lists (n): ");
    scanf("%d", &n);

    Node *lists[n];

    // Initialize all linked lists to NULL
    for (int i = 0; i < n; i++){
        lists[i] = NULL;
    }

    // Input integers for each linked list
    for (int i = 0; i < n; i++){
        int adr;
        scanf("%d", &adr);
        int num;
        char c;
        while (1){
            scanf("%d%c", &num, &c);
            insertAtEnd(&lists[adr - 1], num);
            if (c == '\n')
                break;
        }
    }

    for (int i = 0; i < n; i++){
        printf("%d : ", i + 1);
        printList(lists[i]);
    }

    for (int i = 0; i < n; i++){
        while (lists[i] != NULL){
            Node *temp = lists[i];
            lists[i] = lists[i]->next;
            free(temp);
        }
    }

    int islandCount = countIslands(lists, n);
    printf("Number of islands: %d\n", islandCount);

    return 0;
}

