// WAP to implement Bubble sort and Heap Sort on 1D array of Employee structure (contains employee_name, emp_no, emp_salary), with key as emp_no. And count the number of swap performed.

#include <stdio.h>

struct employee
{
    char employee_name[100];
    int emp_no;
    int emp_salary;
};

void swap(struct employee *a, struct employee *b)
{
    struct employee temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(struct employee e[], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (e[i].emp_no < e[j].emp_no)
            {
                swap(&e[i], &e[j]);
            }
        }
    }
    printf("Bubble Sort\n\n");

    for (int i = 0; i < n; i++)
    {
        printf("%s %d %d\n", e[i].employee_name, e[i].emp_no, e[i].emp_salary);
    }
}

int main()
{
    int n = 3;
    struct employee e[n];
    printf("Enter 10 Employes (Name, Emp. No., Salary)\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d", e[i].employee_name, &e[i].emp_no, &e[i].emp_salary);
    }

    bubblesort(e, n);

    return 0;
}