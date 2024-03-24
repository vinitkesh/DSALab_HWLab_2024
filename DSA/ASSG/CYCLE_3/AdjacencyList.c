#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to create a new node
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

// Function to insert a node at the end of the linked list
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

// Function to print the linked list
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

int main()
{
    int n;
    printf("Enter the number of linked lists (n): ");
    scanf("%d", &n);

    Node *lists[n];

    // Initialize all linked lists to NULL
    for (int i = 0; i < n; i++)
    {
        lists[i] = NULL;
    }

    // Input integers for each linked list
    for (int i = 0; i < n; i++)
    {
        int adr;
        scanf("%d", &adr);
        int num;
        char c;
        while (1)
        {
            scanf("%d%c", &num, &c);
            insertAtEnd(&lists[adr - 1], num);
            if (c == '\n')
                break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d : ", i + 1);
        printList(lists[i]);
    }

    for (int i = 0; i < n; i++)
    {
        while (lists[i] != NULL)
        {
            Node *temp = lists[i];
            lists[i] = lists[i]->next;
            free(temp);
        }
    }

    return 0;
}

