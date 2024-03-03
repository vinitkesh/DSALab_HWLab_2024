#include <stdio.h>
#include <stdlib.h>

void insertHash(int *HashA, int key, int m) {
    int index = key % m;
    while (HashA[index] != -1) {
        index = (index + 1) % m;
    }
    HashA[index] = key;
}

int searchHash(int *HashA, int key, int m) {
    int i = key % m;
    while (HashA[i] != -1) {
        if (HashA[i] == key) {
            return 1;
        }
        i = (i + 1) % m;
    }
    return 0;
}

void SetUnion(int A[], int m, int B[], int n, int HashA[], int HashB[]) {

    printf("Set Union: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", A[i]);
    }
    for (int i = 0; i < n; i++) {
        if (!searchHash(HashA, B[i], m)) {
            printf("%d ", B[i]);
        }
    }
    printf("\n");
}

void intersection(int A[], int m, int B[], int n,int HashA[],int HashB[]) {
    // Implementation of intersection function
    printf("Intersection: ");

    for(int i=0 ;i < m;i++){
        if(searchHash(HashB,A[i],n)){
            printf("%d ",A[i]);
        }
    }
}

void setDifference(int A[], int m, int B[], int n,int HashA[],int HashB[]) {
    // Implementation of setDifference function

    printf("Set Difference: ");

    for(int i=0;i<m;i++){
        if(!searchHash(HashB,A[i],n)){
            printf("%d ",A[i]);
        }
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int A[m];
    int B[n];
    int HashA[m];
    int HashB[n];

    for (int i = 0; i < m; i++) {
        HashA[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        HashB[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &A[i]);
        insertHash(HashA, A[i], m);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &B[i]);
        insertHash(HashB, B[i], n);
    }

    char operation, array1, array2;

    while (1) {
    scanf(" %c", &operation); // Include space before %c

    printf("Operation: %c\n", operation);

    switch (operation) {
        case 'u':
            scanf(" %c %c", &array1, &array2); // Include space before %c
            if (array1 == 'A' && array2 == 'B') {
                printf("Union: ");
                SetUnion(A, m, B, n, HashA, HashB);
            } else if (array1 == 'B' && array2 == 'A') {
                SetUnion(B, n, A, m, HashB, HashA);
            }
            break;
        case 'i':
            scanf(" %c %c", &array1, &array2); // Include space before %c
            if (array1 == 'A' && array2 == 'B') {
                intersection(A, m, B, n, HashA, HashB);
            } else if (array1 == 'B' && array2 == 'A') {
                intersection(B, n, A, m,  HashB, HashA);
            }
            break;
        case 's':
            scanf(" %c %c", &array1, &array2); // Include space before %c
            if (array1 == 'A' && array2 == 'B') {
                setDifference(A, m, B, n, HashA, HashB);
            } else if (array1 == 'B' && array2 == 'A') {
                setDifference(B, n, A, m, HashB, HashA);
            }
            break;
        case 'e':
            return 0;
    }
}


    return 0;
}
