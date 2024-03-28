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

// Function to insert a node at the end of the linked list
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

// Function to print the linked list
void printList(Node *head){
    printf("Linked List: ");
    while (head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to perform DFS on a node
void dfs_print(Node **lists, int node, int *visited) {
    visited[node] = 1; // Mark the current node as visited
    printf("%d ", node);

    Node *temp = lists[node - 1];
    while(temp != NULL){
        if (visited[temp->data]==0){
            dfs_print(lists, temp->data, visited); // Recursive call for adjacent nodes
        }
        temp = temp->next;
    }
}

void dfs(Node **lists, int node,int n) {
    int visited[n+1];

    for(int i=0;i<n+1;i++){
        visited[i]=0;
    }

    for(int i=1;i<n;i++){
        if(visited[i]==0){
            dfs_print(lists, i, visited);
        }
    }
}

int islandCout(Node **lists, int node,int n) {
    int visited[n+1];
    int count= 0;

    for(int i=0;i<n+1;i++){
        visited[i]=0;
    }

    for(int i=1;i<n;i++){
        if(visited[i]==0){
            dfs_print(lists, i, visited);
            count++;
        }
        
    }
    return count;
}

int dfs_count_nodes(Node **lists, int node, int *visited) {
    visited[node] = 1; // Mark the current node as visited
    int count=1;

    Node *temp = lists[node - 1];
    while(temp != NULL){
        if (visited[temp->data]==0){
            count+=dfs_count_nodes(lists, temp->data, visited); // Recursive call for adjacent nodes
        }
        temp = temp->next;
    }
    return count;
}

void vertex_count(Node **lists, int n) {
    int visited[n+1];

    for(int i=0;i<n+1;i++){
        visited[i]=0;
    }

    int vertex_count[n+1];
    for(int i=0;i<n+1;i++){vertex_count[i]=0;}
    int j=0;
    for(int i=1;i<n;i++){
        if(visited[i]==0){
            vertex_count[j]=dfs_count_nodes(lists, i, visited);
            j++;
        }
    }
    printf("Number of vertices in each island: ");
    for(int i=0;i<j;i++){
        printf("%d ",vertex_count[i]);
    }
}



int main(){
    int n;
    printf("Enter the number of linked lists (n): ");
    scanf("%d", &n);

    Node *lists[n]; // Array of linked lists

    // Initialize all linked lists to NULL
    for (int i = 0; i < n; i++){
        lists[i] = NULL;
    }

    for (int i = 0; i < n; i++){
        int adr; // Address of the linked list
        scanf("%d", &adr);

        int num;char c;
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

    
    printf("Number of islands: %d\n", islandCout(lists, 1,n));

    // counting vertices in each islandL
    printf("Number of vertices in each island: ");
    vertex_count(lists, n);
    
    printf("\n");
    return 0;
}

