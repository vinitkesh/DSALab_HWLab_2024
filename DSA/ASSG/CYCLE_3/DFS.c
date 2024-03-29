#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node *head)
{
    printf("Linked List: ");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


void dfs(Node **lists, int node, int *visited){
    visited[node] = 1;


    Node *temp = lists[node - 1];
    while (temp != NULL)
    {
        if (!visited[temp->data]){
            dfs(lists, temp->data, visited);
        }
        temp = temp->next;
    }
}

int main()
{
    int n;
    printf("Enter the number of linked lists (n): ");
    scanf("%d", &n);

    Node *lists[n];

    for (int i = 0; i < n; i++){
        lists[i] = NULL;
    }

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

    int visited[n + 1];

    for(int i=0;i<n+1;i++){
        visited[i]=0;
    }

    dfs(lists, 1, visited);



    return 0;
}
