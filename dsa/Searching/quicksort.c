#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int partition(int A[],int p, int q)
{
     int pivot = A[p];
        int i=p+1;
        int j=q;
    while(true)
    {
        while(A[i]<pivot)
        i++;
        while(A[j]>pivot)
        j--;
        if(i<j)
        {
            int t=A[i];
            A[i] = A[j];
            A[j] = t;
        }
        else
        {
            int t=A[p];
            A[p] = A[j];
            A[j] = t;
            break;
        }
    }
    return j;
}
void Quicksort(int A[],int p, int q)
{
    if(p<q)
    {
        int j = partition(A,p,q);
        Quicksort(A,p,j-1);
        Quicksort(A,j+1,q);
    }
}
void printarray(int* A,int n)
{
    for(int i=0;i<5;i++)
    printf("%d",A[i]);
}
int main()
{
    printf("enter the array ");
    int a[5];
    for(int i=0;i<5;i++)
    scanf("%d",&a[i]);
    Quicksort(a,0,4);
    printarray(a,5);
    return 0;
}
