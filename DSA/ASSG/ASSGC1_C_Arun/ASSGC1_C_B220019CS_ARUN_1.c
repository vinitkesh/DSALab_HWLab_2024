#include <stdio.h>
#include <stdlib.h>

#define SIZE 200
#define EMPTY -1

struct Node
{
    int key;
    char value;
};

struct HashMap
{
    struct Node *array[SIZE];
};

int hashFunction(int key)
{
    return key % SIZE;
}

struct HashMap *createHashmap(int maxSize)
{
    struct HashMap *map = (struct HashMap *)malloc(sizeof(struct HashMap));
    for (int i = 0; i < maxSize; i++)
    {
        map->array[i] = NULL;
    }
    return map;
}

struct HashMap *clearHashmap(struct HashMap *map, int maxSize)
{
    for (int i = 0; i < maxSize; i++)
    {
        map->array[i] = NULL;
    }
    return map;
}

int search(struct HashMap *map, int key)
{
    int index = hashFunction(key);

    while (map->array[index] != NULL)
    {
        if (map->array[index]->key == key)
        {
            return 1;
        }
        index = (index + 1) % SIZE;
    }

    return 0;
}

void insertLinear(struct HashMap *map, int key)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->key = key;

    int index = hashFunction(key);

    while (map->array[index] != NULL)
    {
        index = (index + 1) % SIZE;
    }

    map->array[index] = newNode;
}

void unionFunc(int *A, int *B, int sizeA, int sizeB, int maxSize, struct HashMap *map)
{
    clearHashmap(map, maxSize);

    for (int i = 0; i < sizeA; i++)
    {
        if (!search(map, A[i]))
        {
            insertLinear(map, A[i]);
            printf("%d ", A[i]);
        }
    }

    for (int i = 0; i < sizeB; i++)
    {
        if (!search(map, B[i]))
        {
            insertLinear(map, B[i]);
            printf("%d ", B[i]);
        }
    }
}

void intersectionFunc(int *A, int *B, int sizeA, int sizeB, int maxSize, struct HashMap *map)
{
    clearHashmap(map, maxSize);

    for (int i = 0; i < sizeB; i++)
    {
        insertLinear(map, B[i]);
    }

    for (int i = 0; i < sizeA; i++)
    {
        if (search(map, A[i]))
        {
            printf("%d ", A[i]);
            map->array[hashFunction(A[i])] = NULL;
        }
    }
}

void setDifferenceFunc(int *A, int *B, int sizeA, int sizeB, int maxSize, struct HashMap *map)
{

    clearHashmap(map, maxSize);

    for (int i = 0; i < sizeB; i++)
    {
        insertLinear(map, B[i]);
    }

    int isEmpty = 1;
    for (int i = 0; i < sizeA; i++)
    {
        if (!search(map, A[i]))
        {
            printf("%d ", A[i]);
            insertLinear(map, A[i]);
            isEmpty = 0;
        }
    }

    if (isEmpty)
    {
        printf("-1");
    }
}

int main()
{
    int sizeA, sizeB;
    scanf("%d %d", &sizeA, &sizeB);
    int A[sizeA];
    int B[sizeB];

    for (int i = 0; i < sizeA; i++)
    {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < sizeB; i++)
    {
        scanf("%d", &B[i]);
    }

    int maxSize = 2 * (sizeA + sizeB);

    struct HashMap *map = createHashmap(maxSize);

    char char1, char2;

    char option;
    do
    {
        scanf(" %c", &option);
        switch (option)
        {
        case 'u':
            scanf(" %c %c", &char1, &char2);
            if (char1 == 'A' && char2 == 'B')
            {
                unionFunc(A, B, sizeA, sizeB, maxSize, map);
                clearHashmap(map, maxSize);
            }
            else if (char1 == 'B' && char2 == 'A')
            {
                unionFunc(B, A, sizeB, sizeA, maxSize, map);
                clearHashmap(map, maxSize);
            }
            else
            {
                printf("-1");
            }
            printf("\n");
            break;

        case 'i':
            scanf(" %c %c", &char1, &char2);
            if (char1 == 'A' && char2 == 'B')
            {
                intersectionFunc(A, B, sizeA, sizeB, maxSize, map);
                clearHashmap(map, maxSize);
            }
            else if (char1 == 'B' && char2 == 'A')
            {
                intersectionFunc(B, A, sizeB, sizeA, maxSize, map);
                clearHashmap(map, maxSize);
            }
            else
            {
                printf("-1");
            }
            printf("\n");

            break;

        case 's':
            scanf(" %c %c", &char1, &char2);
            if (char1 == 'A' && char2 == 'B')
            {
                setDifferenceFunc(A, B, sizeA, sizeB, maxSize, map);
                clearHashmap(map, maxSize);
            }
            else if (char1 == 'B' && char2 == 'A')
            {
                setDifferenceFunc(B, A, sizeB, sizeA, maxSize, map);
                clearHashmap(map, maxSize);
            }
            else
            {
                printf("-1");
            }
            printf("\n");
            break;

        case 'e':
            break;
        }

    } while (option != 'e');

    return 1;
}
