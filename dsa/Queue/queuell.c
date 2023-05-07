#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node
{
	int data;
	struct node *addr;
}*front,*rear,*temp;
void insert(int);
void delete();
void display();
int main() 
{
	int n,ch,k;
	front=rear=NULL;
	do
	{
	printf("\n1-insert element\n2-delete element\n3 display");
	printf("\nEnter your choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			    printf("\nenter the element");
			    scanf("%d",&n);
			    insert(n);
			    break;
		case 2:
			    delete();
			    break;
		case 3:
			    display();
			    break;
		default:
			     printf("\nInvalid choice...!!");
			     
	}
	printf("\ndo you want to contiue....presss 1");
	scanf("%d",&k);
  }while(k==1); 
	return 0;
}
void insert(int n)
{
	if(rear==NULL)
	{
		rear=malloc(sizeof(struct node*));
		rear->data=n;
		rear->addr=NULL;
		front=rear;
	}
	else
	{
		temp=malloc(sizeof(struct node*));
		rear->addr=temp;
		temp->data=n;
		temp->addr=NULL;
		rear=temp;
	}
}
void delete()
{
	if(front==NULL)
	{
		printf("\nthe queue is empty");
	}
	else
	{
		printf("\nthe deleted elemt is %d",front->data);
		temp=front;
		front=front->addr;
		free(temp);
	}
}
void display()
{
	temp=front;
	while(temp!=rear)
	{
		printf("| %d | %u |",temp->data,temp->addr);
		temp=temp->addr;
	}
}
