#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

struct Node
{
    int key;
    struct Node *next;
    struct Node *prev;
};

struct HashMap
{
    struct Node *array[SIZE];
};

struct HashMap *createHashMap(int maxSize)
{
    struct HashMap *map = (struct HashMap *)malloc(sizeof(struct HashMap));
    for (int i = 0; i < maxSize; i++)
    {
        map->array[i] = NULL;
    }
    return map;
}

int hashFunction(int key, int maxSize)
{
    return key % maxSize;
}

void insert(struct HashMap *map, int key, int maxSize)
{
    int index = hashFunction(key, maxSize);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (map->array[index] == NULL)
    {
        map->array[index] = newNode;
    }
    else
    {
        struct Node *current = map->array[index];
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void search(struct HashMap *map, int key, int maxSize)
{
    int index = hashFunction(key, maxSize);
    struct Node *current = map->array[index];

    int position = 1;

    while (current != NULL)
    {
        if (current->key == key)
        {
            printf("%d %d\n", index, position);
            return;
        }
        current = current->next;
        position++;
    }

    printf("-1\n");
}

void delete(struct HashMap *map, int key, int maxSize)
{
    int index = hashFunction(key, maxSize);
    struct Node *current = map->array[index];

    int position = 1;

    while (current != NULL)
    {
        if (current->key == key)
        {
            if (current->prev != NULL)
            {
                current->prev->next = current->next;
            }
            else
            {
                map->array[index] = current->next;
            }

            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            }

            free(current);
            printf("%d %d\n", index, position);
            return;
        }
        current = current->next;
        position++;
    }

    printf("-1\n");
}

void update(struct HashMap *map, int oldKey, int newKey, int maxSize)
{
    delete (map, oldKey, maxSize);
    insert(map, newKey, maxSize);
}

void printElementsInChain(struct HashMap *map, int index, int maxSize)
{
    if (index < 0 || map->array[index] == NULL)
    {
        printf("-1\n");
        return;
    }

    struct Node *current = map->array[index];
    while (current != NULL)
    {
        printf("%d ", current->key);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    int maxSize;
    scanf("%d", &maxSize);
    struct HashMap *map = createHashMap(maxSize);
    int key, oldKey, newKey, index;
    char option;
    do
    {
        scanf(" %c", &option);
        switch (option)
        {
        case 'i':
            scanf("%d", &key);
            insert(map, key, maxSize);
            break;

        case 'd':
            scanf("%d", &key);
            delete (map, key, maxSize);
            break;

        case 'u':
            scanf("%d %d", &oldKey, &newKey);
            update(map, oldKey, newKey, maxSize);
            break;

        case 's':
            scanf("%d", &key);
            search(map, key, maxSize);
            break;

        case 'p':
            scanf("%d", &index);
            printElementsInChain(map, index, maxSize);
            break;

        case 'e':
            break;
        }

    } while (option != 'e');

    return 1;
}
