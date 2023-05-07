#include <stdio.h>
#include <stdlib.h>
void insertionsort(int A[],int n)
{
    int key,j;
    for(int i=1;i<=n-1;i++)
    {
        key = A[i];
        j=i-1;
        while(j>=0&&A[j]<key)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1] = key;
    }
    for(int i=0;i<5;i++)
    printf("%d",A[i]);
}

int main()
{
    int a[5];
    printf("enter 5 numbers");
    for(int i=0;i<5;i++)
    scanf("%d",&a[i]);
    insertionsort(a,5);
    return 0;
}
