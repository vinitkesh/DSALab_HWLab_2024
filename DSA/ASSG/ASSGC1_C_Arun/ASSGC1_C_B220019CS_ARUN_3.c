#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char firstName[100];
    char branch[3];
    struct Student *next;
};

typedef struct Student Student;

int hashFunction(char *name, int age)
{
    int sum = 0;
    int i = 0;

    while (i < strlen(name))
    {
        sum += name[i++];
    }

    return (sum + age) % 4;
}

void initializeHashMap(Student *map[4])
{
    for (int i = 0; i < 4; i++)
    {
        map[i] = NULL;
    }
}

void convertToLowercase(char *str)
{
    if (str[0] >= 'A' && str[0] <= 'Z')
    {
        str[0] = str[0] + ('a' - 'A');
    }

    if (str[1] >= 'A' && str[1] <= 'Z')
    {
        str[1] = str[1] + ('a' - 'A');
    }
}

void insert(Student *hash_table[4], char *name, char *branch, int age)
{
    int index = hashFunction(name, age);
    Student *newStudent = (Student *)malloc(sizeof(Student));
    strcpy(newStudent->firstName, name);
    convertToLowercase(branch);
    strcpy(newStudent->branch, branch);
    newStudent->next = NULL;

    if (hash_table[index] == NULL)
    {
        hash_table[index] = newStudent;
    }
    else
    {
        Student *temp = hash_table[index];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newStudent;
    }
}

void displayCountAndNames(Student *current)
{
    if (current != NULL)
    {
        displayCountAndNames(current->next);
        printf("%s ", current->firstName);
    }
}

void displayCount(int index, Student *hash_table[4])
{
    Student *temp = hash_table[index];
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("%d ", count);

    displayCountAndNames(hash_table[index]);
}

void displayBranch(int index, Student *hash_table[4], char *branch)
{
    Student *temp = hash_table[index];
    int count = 0;

    while (temp != NULL)
    {
        if (!strcmp(branch, temp->branch))
        {
            printf("%s ", temp->firstName);
            count++;
        }
        temp = temp->next;
    }

    if (count == 0)
    {
        printf("%d\n", -1);
    }
    else
    {
        printf("\n");
    }
}

int main()
{
    char name[100];
    char Roll_no[10];
    char branch[3];
    char option;
    int index;

    int n, age;
    scanf("%d", &n);

    Student *hash_table[4];
    initializeHashMap(hash_table);

    int i = 0;

    while (i < n)
    {
        scanf("%s %s %d", name, Roll_no, &age);
        strncpy(branch, &Roll_no[7], 2);
        insert(hash_table, name, branch, age);
        i++;
    }

    while (1)
    {
        scanf(" %c", &option);

        switch (option)
        {
        case 'c':
        {
            scanf(" %d", &index);
            if (index >= 0 && index <= 3)
            {
                displayCount(index, hash_table);
                printf("\n");
            }
            else
                printf("-1\n");
            break;
        }

        case '0':
        {
            scanf(" %s", branch);
            convertToLowercase(branch);
            displayBranch(0, hash_table, branch);
            break;
        }

        case '1':
        {
            scanf(" %s", branch);
            convertToLowercase(branch);
            displayBranch(1, hash_table, branch);
            break;
        }

        case '2':
        {
            scanf(" %s", branch);
            convertToLowercase(branch);
            displayBranch(2, hash_table, branch);
            break;
        }

        case '3':
        {
            scanf(" %s", branch);
            convertToLowercase(branch);
            displayBranch(3, hash_table, branch);
            break;
        }

        case 'e':
            return 0;
        }
    }
}
