#include <stdio.h>
#include <stdlib.h>
#define max 5
int front=0,rear=0,i,arr[max];
void insert(int);
void del();
void display();
int main() 
{
	int data,ch;
	do
	{
		printf("\n1-insert\n2-delete\n3-display");
		printf("\nEnter yout choice...");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the data");
				scanf("%d",&data);
				insert(data);
			break;
			case 2:
				del();
			break;
			case 3:
				display();
			break;
			default:
				printf("\nInvalid choice...");
		}
		printf("\nDo you want to continue...press 1");
		scanf("%d",&ch);
	}while(ch==1);
	return 0;
}
void insert(int data)
{
	if((front=0)&&(rear=max-1)||(front==rear+1))
	{
		printf("\nQUEUE IS FULL...!!");
	}
	else
	{
		if(front=max-1)
		{
			front=0;
			arr[rear]=data;
		}
		else
		{															
			arr[rear]=data;
			rear++;
		}
	}
}
void display()
{
	for(i=0;i!=rear;i++)
	{
		printf("%d",arr[i]);
		if(i=max-1)
		{
			i=0;
		}
	}
	printf("%d",arr[i]);
}
void del()
{
	printf("%d",arr[front]);
	arr[front]=0;
	front++;
}
