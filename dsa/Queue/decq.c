#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int front = -1;
int rear = -1;
int arr[SIZE];
void insertfront(int x);
void insertrear(int x);
int deletefront();
int deleterear();
void traverse();
int main()
{
    int choice, x, z;
    while (1)
    {
        printf("\n Enter your choice \n1 for insertfront\n2 for insertrear\n3 for deletefront\n4 for deleterear\n5 for exit    ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter the element to be inserted from front ");
            scanf("%d", &x);
            insertfront(x);
            printf("\n Queue after insertion  \n");
            traverse();
            break;
        case 2:
            printf("\n Enter the element to be inserted from rear ");
            scanf("%d", &x);
            insertrear(x);
            printf("\n Queue after insertion  \n");
            traverse();
            break;
        case 3:
            z = deletefront();
            if (z != 0)
                printf("\n Deleted value is %d", z);
            printf("\n Queue after deletion  \n");
            traverse();
            break;
        case 4:
            z = deleterear();
            if (z != 0)
                printf("\n Deleted value is %d", z);
            printf("\n Queue after deletion  \n");
            traverse();
            break;
        case 5:
            exit(1);
        }
    }
}
void insertfront(int x)
{
    if ((front == 0 && rear == SIZE - 1) || front == rear + 1)
        printf("\n Queue is full  ");
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        arr[front] = x;
    }
    else if (front == 0)
    {
        front = SIZE - 1;
        arr[front] = x;
    }
    else
    {
        front--;
        arr[front] = x;
    }
}
void insertrear(int x)
{
    if ((front == 0 && rear == SIZE - 1) || front == rear + 1)
        printf("\n Queue is full  ");
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        arr[rear] = x;
    }
    else if (rear == SIZE - 1)
    {
        rear = 0;
        arr[rear] = x;
    }
    else
    {
        rear++;
        arr[rear] = x;
    }
}
int deletefront()
{
    int k;
    if (front == -1 && rear == -1)
    {
        printf("\n Queue is empty ");
        return 0;
    }
    else if (front == SIZE - 1)
    {
        k = arr[front];
        front = 0;
    }
    else if (front == rear)
    {
        k = arr[front];
        front = -1;
        rear = -1;
    }
    else
    {
        k = arr[front];
        front++;
    }
    if (k != 0)
        return k;
}
int deleterear()
{
    int k;
    if (front == -1 && rear == -1)
    {
        printf("\n Queue is empty ");
        return 0;
    }
    else if (rear == 0)
    {
        k = arr[rear];
        rear = SIZE - 1;
    }
    else if (front == rear)
    {
        k = arr[rear];
        front = -1;
        rear = -1;
    }
    else
    {
        k = arr[rear];
        rear--;
    }
    if (k != 0)
        return k;
}
void traverse()
{
    int i = front;
    while (i != rear)
    {
        printf("%d  ", arr[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d", arr[rear]);
}