// WAP to implement Bubble sort and Heap Sort on 1D array of Employee structure (contains employee_name, emp_no, emp_salary), with key as emp_no. And count the number of swap performed.

#include <stdio.h>

struct employee
{
    char name[20];
    int emp_no;
    int salary;
};

void swap(struct employee *a, struct employee *b)
{
    struct employee temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(struct employee arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].emp_no > arr[j + 1].emp_no)
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void heapify(struct employee arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l].emp_no > arr[largest].emp_no)
        largest = l;

    if (r < n && arr[r].emp_no > arr[largest].emp_no)
        largest = r;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(struct employee arr[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void print_array(struct employee arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%s %d %d", arr[i].name, arr[i].emp_no, arr[i].salary);
    }
}

int main()
{
    int n;
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    struct employee arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the name of employee %d: ", i + 1);
        scanf("%s", arr[i].name);
        printf("Enter the employee number of employee %d: ", i + 1);
        scanf("%d", &arr[i].emp_no);
        printf("Enter the salary of employee %d: ", i + 1);
        scanf("%d", &arr[i].salary);
    }
    printf("Enter 1 for Bubble Sort and 2 for Heap Sort: ");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        bubble_sort(arr, n);
        break;
    case 2:
        heap_sort(arr, n);
        break;
    default:
        printf("Invalid choice");
        break;
    }
    print_array(arr, n);
    return 0;
}
