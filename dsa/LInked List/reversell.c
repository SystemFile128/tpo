#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node
{
	int data;
	struct node *addr;
}*start,*temp,*curr,*ptr1,*ptr2,*ptr3;
void create(int);
void display();
void reverse();
int main() 
{
	int n,ch,k;
	start=NULL;
	do
	{
		printf("enter the element in linked list");
		scanf("%d",&n);
		create(n);
		display();
		printf("\nDo you want to continue...press 1");
		scanf("%d",&ch);
	}while(ch==1);
	printf("\nDo you want to reverse the linked list...press 1");
	scanf("%d",&k);
	if(k==1)
	{
		reverse();
		display();
	}
	return 0;
}
void create(int n)
{
	temp=malloc(sizeof(struct node));
	temp->data=n;
	temp->addr=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		curr=start;
		while(curr->addr!=NULL)
		{
			curr=curr->addr;
		}
		curr->addr=temp;
	}
}
void display()
{
	if(start==NULL)
	{
		printf("\nLinked list is empty");
	}
	else
	{
		curr=start;
		printf("\n");
		while(curr!=NULL)
		{
			printf("| %d | %u |-->",curr->data,curr->addr);
			curr=curr->addr;
		}
	}
}
void reverse()
{
	ptr1=start;
	ptr2=ptr1->addr;
	ptr3=ptr2->addr;
	while(ptr3!=NULL)
	{
		ptr2->addr=ptr1;
		ptr1=ptr2;
		ptr2=ptr3;
		ptr3=ptr3->addr;
	}
	ptr2->addr=ptr1;
	start->addr=NULL;
	start=ptr2;
}








