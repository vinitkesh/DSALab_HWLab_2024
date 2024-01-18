#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    int priority;
    char admitTime[5];
} Patient;

typedef struct {
    Patient* heap;
    int capacity;
    int size;
} PriorityQueue;

void initPQ(PriorityQueue* pq, int capacity) {
    pq->heap = (Patient*)malloc(capacity * sizeof(Patient));
    pq->capacity = capacity;
    pq->size = 0;
}

void swapPatients(Patient* a, Patient* b) {
    Patient temp = *a;
    *a = *b;
    *b = temp;
}

int comparePatients(Patient* a, Patient* b) {
    if (a->priority > b->priority)
        return 1;
    else if (a->priority < b->priority)
        return -1;
    else
        return strcmp(b->admitTime, a->admitTime);
}

void heapify(PriorityQueue* pq, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < pq->size && comparePatients(&pq->heap[left], &pq->heap[largest]) > 0)
        largest = left;

    if (right < pq->size && comparePatients(&pq->heap[right], &pq->heap[largest]) > 0)
        largest = right;

    if (largest != i) {
        swapPatients(&pq->heap[i], &pq->heap[largest]);
        heapify(pq, largest);
    }
}

void admit(PriorityQueue* pq, char* name, int priority, char* admitTime) {
    if (pq->size == pq->capacity) {
        return;
    }

    Patient newPatient;
    strcpy(newPatient.name, name);
    newPatient.priority = priority;
    strcpy(newPatient.admitTime, admitTime);

    pq->heap[pq->size] = newPatient;
    int i = pq->size;
    pq->size++;

    while (i > 0 && comparePatients(&pq->heap[i], &pq->heap[(i - 1) / 2]) > 0) {
        swapPatients(&pq->heap[i], &pq->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void treat(PriorityQueue* pq) {
    if (pq->size == 0) {
        return;
    }

    Patient nextPatient = pq->heap[0];
    printf("%s %d %s\n", nextPatient.name, nextPatient.priority, nextPatient.admitTime);

    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;

    heapify(pq, 0);
}

void check(PriorityQueue* pq) {
    if (pq->size == 0) {
        return;
    }

    Patient nextPatient = pq->heap[0];
    printf("%s %d %s\n", nextPatient.name, nextPatient.priority, nextPatient.admitTime);
}

void discharge(PriorityQueue* pq, char* name, char* admitTime) {
    int i;
    for (i = 0; i < pq->size; i++) {
        if (strcmp(pq->heap[i].name, name) == 0 && strcmp(pq->heap[i].admitTime, admitTime) == 0)
            break;
    }

    if (i == pq->size) {
        return;
    }

    pq->heap[i] = pq->heap[pq->size - 1];
    pq->size--;

    heapify(pq, i);
}

void update(PriorityQueue* pq, char* name, char* admitTime, int newPriority) {
    int i;
    for (i = 0; i < pq->size; i++) {
        if (strcmp(pq->heap[i].name, name) == 0 && strcmp(pq->heap[i].admitTime, admitTime) == 0)
            break;
    }

    if (i == pq->size) {
        return;
    }

    pq->heap[i].priority = newPriority;

    while (i > 0 && comparePatients(&pq->heap[i], &pq->heap[(i - 1) / 2]) > 0) {
        swapPatients(&pq->heap[i], &pq->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void printAll(PriorityQueue* pq) {
    if (pq->size == 0) {
        return;
    }

    PriorityQueue temp;
    initPQ(&temp, pq->size);
    memcpy(temp.heap, pq->heap, pq->size * sizeof(Patient));
    temp.size = pq->size;

    for (int i = temp.size / 2 - 1; i >= 0; i--)
        heapify(&temp, i);

    for (int i = temp.size - 1; i >= 0; i--) {
        Patient patient = temp.heap[0];
        printf("%s %d %s\n", patient.name, patient.priority, patient.admitTime);

        temp.heap[0] = temp.heap[i];
        temp.size--;

        heapify(&temp, 0);
    }

    free(temp.heap);
}

int main() {
    PriorityQueue pq;
    initPQ(&pq, 100);

    char option;
    char name[100];
    int priority;
    char admitTime[100];
    int newPriority;

    while (option != 'e') {
        scanf(" %c", &option);

        switch (option) {
            case 'a':
                scanf("%s %d %s", name, &priority, admitTime);
                admit(&pq, name, priority, admitTime);
                break;
            case 't':
                treat(&pq);
                break;
            case 'c':
                check(&pq);
                break;
            case 'd':
                scanf("%s %s", name, admitTime);
                discharge(&pq, name, admitTime);
                break;
            case 'u':
                scanf("%s %s %d", name, admitTime, &newPriority);
                update(&pq, name, admitTime, newPriority);
                break;
            case 'p':
                printAll(&pq);
                break;
            case 'e':
                break;
            default:
                break;
        }
    }

    free(pq.heap);

    return 0;
}
