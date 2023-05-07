#include <stdio.h>
#include <stdlib.h>

struct faculty
{
    int id;
    char name[20];
    int age;
    int salary;
};

void swap(struct faculty *a, struct faculty *b)
{
    struct faculty temp = *a;
    *a = *b;
    *b = temp;
}

void print(struct faculty faculties[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("ID: %d\tName: %s\tAge: %d\tSalary: %d\n", faculties[i].id, faculties[i].name, faculties[i].age, faculties[i].salary);
    }
}

void bubblesort(struct faculty faculties[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (faculties[j].id > faculties[j + 1].id)
            {
                swap(&faculties[j], &faculties[j + 1]);
            }
        }
    }
    printf("The sorted list is: \n");
    print(faculties, n);
}

void merge(struct faculty faculties[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    struct faculty L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = faculties[l + i];
    for (j = 0; j < n2; j++)
        R[j] = faculties[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i].id <= R[j].id)
        {
            faculties[k] = L[i];
            i++;
        }
        else
        {
            faculties[k] = L[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        faculties[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        faculties[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(struct faculty faculties[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(faculties, l, m);
        mergesort(faculties, m + 1, r);
        merge(faculties, l, m, r);
    }
}

int partition(struct faculty faculties[], int l, int r)
{
    int pivot = faculties[r].id;
    int i = (l - 1);
    for (int j = l; j <= r - 1; j++)
    {
        if (faculties[j].id < pivot)
        {
            i++;
            swap(&faculties[i], &faculties[j]);
        }
    }
    swap(&faculties[i + 1], &faculties[r]);
    return (i + 1);
}

void quicksort(struct faculty faculties[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(faculties, l, r);
        quicksort(faculties, l, pi - 1);
        quicksort(faculties, pi + 1, r);
    }
}

void selectionsort(struct faculty faculties[], int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (faculties[j].id < faculties[min].id)
            {
                min = j;
            }
        }
        swap(&faculties[min], &faculties[i]);
    }
    printf("The sorted list is: \n");
    print(faculties, n);
}

void insertionsort(struct faculty faculties[], int n)
{
    int i, j;
    struct faculty key;
    for (i = 1; i < n; i++)
    {
        key = faculties[i];
        j = i - 1;
        while (j >= 0 && faculties[j].id > key.id)
        {
            faculties[j + 1] = faculties[j];
            j = j - 1;
        }
        faculties[j + 1] = key;
    }
    printf("The sorted list is: \n");
    print(faculties, n);
}

void heapify(struct faculty faculties[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && faculties[l].id > faculties[largest].id)
        largest = l;

    if (r < n && faculties[r].id > faculties[largest].id)
        largest = r;

    if (largest != i)
    {
        swap(&faculties[i], &faculties[largest]);
        heapify(faculties, n, largest);
    }
}

void heapsort(struct faculty faculties[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(faculties, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(&faculties[0], &faculties[i]);
        heapify(faculties, i, 0);
    }
    printf("The sorted list is: \n");
    print(faculties, n);
}

int main()
{
    int n;
    printf("Enter the number of faculties: ");
    scanf("%d", &n);
    struct faculty faculties[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the id of the faculty: ");
        scanf("%d", &faculties[i].id);
        printf("Enter the name of the faculty %d: ", i + 1);
        scanf("%s", faculties[i].name);
        printf("Enter the age of the faculty %d: ", i + 1);
        scanf("%d", &faculties[i].age);
        printf("Enter the salary of the faculty %d: ", i + 1);
        scanf("%d", &faculties[i].salary);
    }

    int ch;

    while (1)
    {
        printf("1. Bubble Sort\n2. Merge Sort\n3. Quick Sort\n4. Selection Sort\n5. Insertion Sort\n6. Heap Sort\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            bubblesort(faculties, n);
            break;
        case 2:
            mergesort(faculties, 0, n - 1);
            printf("The sorted list is: \n");
            print(faculties, n);
            break;
        case 3:
            quicksort(faculties, 0, n - 1);
            printf("The sorted list is: \n");
            print(faculties, n);
            break;
        case 4:
            selectionsort(faculties, n);
            break;
        case 5:
            insertionsort(faculties, n);
            break;
        case 6:
            heapsort();
            break;
        default:
            printf("Invalid choice");
            break;
        }
    }

    return 0;
}