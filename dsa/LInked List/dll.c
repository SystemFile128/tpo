#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct node
{
	int data;
	struct node *addr_next;
	struct node *addr_prev;
}*start,*curr,*temp,*prev;
void create(int);
void display();
int main() 
{
	int n,ch;
	start=NULL;
	do
	{
		printf("\nEnter the element in doubly linked list");
		scanf("%d",&n);
		create(n);
		display();
		printf("\ndo you want to continue...press 1");
	    scanf("%d",&ch);
	}while(ch==1);
	printf("\nfinal doubly linked list is:");
	display();
	return 0;
}
void create(int n)
{
   temp=malloc(sizeof(struct node));
   temp->data=n;
   temp->addr_next=NULL;
   temp->addr_prev=NULL;
   if(start==NULL)	
   {
   	  start=temp;
   }
   else
   {
   	   curr=start;
   	   while(curr->addr_next!=NULL)
   	   {
   	   	  curr=curr->addr_next;
	   }
	   curr->addr_next=temp;
	   temp->addr_prev=curr;
   }
}
void display()
{
	if(start==NULL)
	{
		printf("double linked list is empty...");
	}
	else
	{
		curr=start;
		
		printf("\n--------------------------------------------------------------------------");
		printf("\n");
		while(curr!=NULL)
		{
			printf("| %u | %d | %u |->",curr->addr_prev,curr->data,curr->addr_next);
			curr=curr->addr_next;
		}
		printf("\n----------------------------------------------------------------------------");
	}
}








