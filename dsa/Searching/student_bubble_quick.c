#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char student_name[50];
    int student_roll_no;
    int total_marks;
} Student;

void bubbleSort(Student arr[], int n, int *swap_count) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j].student_roll_no > arr[j+1].student_roll_no) {
                Student temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                (*swap_count)++;
            }
        }
    }
}

int partition(Student arr[], int low, int high, int *swap_count) {
    Student pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].student_roll_no < pivot.student_roll_no) {
            i++;
            Student temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            (*swap_count)++;
        }
    }
    Student temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    (*swap_count)++;
    return (i + 1);
}

void quickSort(Student arr[], int low, int high, int *swap_count) {
    if (low < high) {
        int pi = partition(arr, low, high, swap_count);
        quickSort(arr, low, pi - 1, swap_count);
        quickSort(arr, pi + 1, high, swap_count);
    }
}

int main() {
    int n, i, swap_count = 0;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    Student arr[n];
    for (i = 0; i < n; i++) {
        printf("Enter the details of student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", arr[i].student_name);
        printf("Roll No.: "); 
        scanf("%d", &arr[i].student_roll_no);
        printf("Total Marks: ");
        scanf("%d", &arr[i].total_marks);
    }
    printf("\nUnsorted array of students:\n");
    for (i = 0; i < n; i++) {
        printf("Name: %s, Roll No.: %d, Total Marks: %d\n", arr[i].student_name, arr[i].student_roll_no, arr[i].total_marks);
    }
    bubbleSort(arr, n, &swap_count);
    printf("\nSorted array of students using Bubble sort:\n");
    for (i = 0; i < n; i++) {
        printf("Name: %s, Roll No.: %d, Total Marks: %d\n", arr[i].student_name, arr[i].student_roll_no, arr[i].total_marks);
    }
    printf("Number of swaps performed: %d\n", swap_count);
    swap_count = 0;
    quickSort(arr, 0, n-1, &swap_count);
    printf("\nSorted array of students using Quick sort:\n");
    for (i = 0; i < n; i++) {
        printf("Name: %s, Roll No.: %d, Total Marks: %d\n", arr[i].student_name, arr[i].student_roll_no, arr[i].total_marks);
    }
    printf("Number of swaps performed: %d\n", swap_count);
    return 0;
}