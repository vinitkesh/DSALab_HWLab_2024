#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Define a structure to represent an edge
typedef struct Edge
{
    int src;
    int dest;
} Edge;

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

// Depth-First Search (DFS) function to count connected components
void DFS(Node *lists[], int visited[], int n, int index)
{
    visited[index] = 1; // Mark current node as visited
    Node *current = lists[index]; // Get the current list
    while (current != NULL)
    {
        int adjacentIndex = current->data - 1; // Convert node data to index
        if (visited[adjacentIndex] == 0) // If adjacent node is not visited
        {
            DFS(lists, visited, n, adjacentIndex); // Recursively visit adjacent node
        }
        current = current->next; // Move to the next node in the list
    }
}

int countConnectedComponents(Node *lists[], int n)
{
    int connectedComponents = 0;
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0; // Initialize visited array
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0) // If the node is not visited
        {
            DFS(lists, visited, n, i); // Perform DFS on unvisited node
            connectedComponents++; // Increment connected components count
        }
    }
    return connectedComponents;
}

void DFS_size(Node *lists[], int visited[], int n, int index, int *size)
{
    visited[index] = 1; // Mark current node as visited
    Node *current = lists[index]; // Get the current list
    while (current != NULL)
    {
        int adjacentIndex = current->data - 1; // Convert node data to index
        if (visited[adjacentIndex] == 0) // If adjacent node is not visited
        {
            (*size)++; // Increment size of connected component
            DFS_size(lists, visited, n, adjacentIndex, size); // Recursively visit adjacent node
        }
        current = current->next; // Move to the next node in the list
    }
}

void print_size_of_components(Node *lists[], int n)
{
    int visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0; // Initialize visited array
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0) // If the node is not visited
        {
            int size = 0;
            DFS_size(lists, visited, n, i, &size); // Perform DFS on unvisited node
            printf("%d ",  size+1);
            
        }
    }
}

int isBridge(Node *lists[], int n, int src, int dest)
{
    // Remove the edge from the graph
    Node *temp = lists[src];
    Node *prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == dest + 1)
        {
            if (prev == NULL)
            {
                lists[src] = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    // Count the number of connected components after removing the edge
    int connectedComponents = countConnectedComponents(lists, n);

    // Add the edge back to the graph
    insertAtEnd(&lists[src], dest + 1);

    // Return 1 if the edge is a bridge, 0 otherwise
    return (connectedComponents > 1) ? 1 : 0;
}

int countBridges(Node *lists[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        Node *current = lists[i];
        while (current != NULL)
        {
            int adjacentIndex = current->data - 1;
            if (i < adjacentIndex && isBridge(lists, n, i, adjacentIndex))
            {
                count++;
            }
            current = current->next;
        }
    }
    printf("Number of bridges: %d\n", count);
    return count;
}


void noOfArticualtionPointsUtil(Node *lists[], int visited[], int disc[], int low[], int parent[], int n, int u)
{
    static int time = 0;
    int children = 0;
    visited[u] = 1;
    disc[u] = low[u] = ++time;
    Node *current = lists[u];
    while (current != NULL)
    {
        int v = current->data - 1;
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            noOfArticualtionPointsUtil(lists, visited, disc, low, parent, n, v);
            low[u] = (low[u] < low[v]) ? low[u] : low[v];
            if (parent[u] == -1 && children > 1)
            {
                printf("%d ", u + 1);
            }
            if (parent[u] != -1 && low[v] >= disc[u])
            {
                printf("%d ", u + 1);
            }
        }
        else if (v != parent[u])
        {
            low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
        }
        current = current->next;
    }
}

void noOfArticualtionPoints(Node *lists[], int n)
{
    int visited[n], disc[n], low[n], parent[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        disc[i] = 0;
        low[i] = 0;
        parent[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            noOfArticualtionPointsUtil(lists, visited, disc, low, parent, n, i);
        }
    }
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

    int connectedComponents = countConnectedComponents(lists, n);
    printf("Number of connected components: %d\n", connectedComponents);

    print_size_of_components(lists, n);

    int bridges = countBridges(lists, n);

    noOfArticualtionPoints(lists, n);



    return 0;
}
