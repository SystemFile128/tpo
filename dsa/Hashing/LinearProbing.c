#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10 // Hash table size
#define EMPTY -1 // Empty slot in hash table
#define DELETED -2 // Deleted slot in hash table

typedef struct Faculty {
    char name[50];
    char department[50];
    int id;
} Faculty;

int hash(int key) {
    return key % SIZE;
}

void insert(Faculty faculty, Faculty table[]) {
    int i, j, k;
    i = hash(faculty.id);
    j = i;
    k = 1;
    while (table[j].id != EMPTY && table[j].id != DELETED && table[j].id != faculty.id) {
        j = (i + k) % SIZE;
        k++;
    }
    if (table[j].id == faculty.id) {
        printf("Error: Faculty with ID %d already exists\n", faculty.id);
    } else {
        table[j] = faculty;
    }
}

void delete(int id, Faculty table[]) {
    int i, j, k;
    i = hash(id);
    j = i;
    k = 1;
    while (table[j].id != EMPTY && (table[j].id == DELETED || table[j].id != id)) {
        j = (i + k) % SIZE;
        k++;
    }
    if (table[j].id == id) {
        table[j].id = DELETED;
        printf("Faculty with ID %d deleted successfully\n", id);
    } else {
        printf("Error: Faculty with ID %d not found\n", id);
    }
}

void search(int id, Faculty table[]) {
    int i, j, k;
    i = hash(id);
    j = i;
    k = 1;
    while (table[j].id != EMPTY && (table[j].id == DELETED || table[j].id != id)) {
        j = (i + k) % SIZE;
        k++;
    }
    if (table[j].id == id) {
        printf("Faculty found:\nName: %s\nDepartment: %s\nID: %d\n", table[j].name, table[j].department, table[j].id);
    } else {
        printf("Error: Faculty with ID %d not found\n", id);
    }
}

void display(Faculty table[]) {
    printf("Faculty table:\n");
    printf("%-15s%-15s%-15s\n", "Name", "Department", "ID");
    for (int i = 0; i < SIZE; i++) {
        if (table[i].id == EMPTY) {
            printf("%-15s%-15s%-15s\n", "-", "-", "-");
        } else if (table[i].id == DELETED) {
            printf("%-15s%-15s%-15s\n", "-", "-", "deleted");
        } else {
            printf("%-15s%-15s%-15d\n", table[i].name, table[i].department, table[i].id);
        }
    }
}

int main() {
    Faculty table[SIZE];
    for (int i = 0; i < SIZE; i++) {
        table[i].id = EMPTY;
    }
    int choice, id;
    Faculty faculty;
    while (1) {
        printf("\n1. Insert faculty\n2. Delete faculty\n3. Search faculty\n4. Display faculty table\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);
                switch (choice) {
            case 1:
            getchar();
                printf("\nEnter faculty name: \n");
                scanf("%[^\n]", faculty.name);
                getchar();
                printf("Enter department name: \n");
                scanf("%[^\n]", faculty.department);
                printf("Enter faculty ID: ");
                scanf("%d", &faculty.id);
                insert(faculty, table);
                break;
            case 2:
                printf("\nEnter faculty ID to delete: ");
                scanf("%d", &id);
                delete(id, table);
                break;
            case 3:
                printf("\nEnter faculty ID to search: ");
                scanf("%d", &id);
                search(id, table);
                break;
            case 4:
                display(table);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice\n");
        }
    }
    return 0;
}



