#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    char name[50];
    int emp_no;
    int salary;
};

void swap(struct Employee* a, struct Employee* b) {
    struct Employee temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort
void bubbleSort(struct Employee arr[], int n, int* count) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].emp_no > arr[j + 1].emp_no) {
                swap(&arr[j], &arr[j + 1]);
                (*count)++;
            }
        }
    }
}

// Heap Sort
void heapify(struct Employee arr[], int n, int i, int* count) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l].emp_no > arr[largest].emp_no) {
        largest = l;
    }
    if (r < n && arr[r].emp_no > arr[largest].emp_no) {
        largest = r;
    }
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        (*count)++;
        heapify(arr, n, largest, count);
    }
}

void heapSort(struct Employee arr[], int n, int* count) {
    int i;
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, count);
    }
    for (i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        (*count)++;
        heapify(arr, i, 0, count);
    }
}

int main() {
    int n, i, count_bubble = 0, count_heap = 0;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    struct Employee arr[n];
    printf("Enter the details of the employees:\n");
    for (i = 0; i < n; i++) {
        printf("Employee %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", arr[i].name);
        printf("Employee number: ");
        scanf("%d", &arr[i].emp_no);
        printf("Salary: ");
        scanf("%d", &arr[i].salary);
    }
    // Bubble Sort
    bubbleSort(arr, n, &count_bubble);
    printf("\nSorted array using Bubble Sort:\n");
    printf("Employee No.\tName\tSalary\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%s\t%d\n", arr[i].emp_no, arr[i].name, arr[i].salary);
    }
    printf("Number of swaps performed: %d\n", count_bubble);

    // Heap Sort
    heapSort(arr, n, &count_heap);
    printf("\n\nAfter Sorting using Heap Sort:\n");
printf("Emp No\t Emp Name\t Emp Salary\n");
for (int i = 0; i < n; i++) {
    printf("%d\t %s\t %d\n", arr[i].emp_no, arr[i].name, arr[i].salary);
}
printf("Number of Swaps: %d\n", count_heap);

return 0;
}
