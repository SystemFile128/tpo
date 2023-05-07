#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *addr_next;
	struct node *addr_prev;
}*start,*curr,*temp,*prev;

void create(int);
void traverse();
void insertloc(int,int);
void insertnode(int,int);
void deleteloc(int);
void deletenode(int);

int main()
{
    int ch,n,loc,data;
    do{
    printf("\n1-create\n2-traverse\n3-Insert at given location\n4-Insert after given Data\n5-Delete after given location\n6-Delete after given data");
    scanf("\n%d",&ch);
    switch (ch)
    {
    case 1:
        printf("\nEnter the Number to add in Doubly linked List : ");
        scanf("\n%d",&n);
        create(n);
        break;
    case 2:
        traverse();
        break;
    case 3:
        printf("\nEnter the Number to add in Doubly linked List : ");
        scanf("\n%d",&n);
        printf("\nEnter the Location :");
        scanf("\n%d",&loc);
        insertloc(n,loc);
        break;
    case 4:
        printf("\nEnter the Number to add in Doubly linked List : ");
        scanf("\n%d",&n);
        printf("\nEnter the data :");
        scanf("\n%d",&data);
        insertnode(n,data);
        break;
    case 5:
        printf("\nEnter the Location :");
        scanf("\n%d",&loc);
        deleteloc(loc);
        break;
    case 6:
        printf("\nEnter the data :");
        scanf("\n%d",&data);
        deletenode(data);
        break;
    default:
        break;
    }
    printf("\nDo you want to continue press 1 :");
    scanf("%d",&ch);
    }while(ch==1);
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
void traverse()
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
void insertloc(int n,int loc)
{
   printf("Hello");
   curr=start;
   temp=malloc(sizeof(struct node));
   temp->data=n;
   temp->addr_next=NULL;
   temp->addr_prev=NULL;
   for (int i = 1; i < loc-1; i++)
   {
    curr=curr->addr_next;
   }
   curr->addr_next=temp;
   temp->addr_prev=curr;
   traverse();
}
void insertnode(int n,int data)
{
   curr=start;
   temp=malloc(sizeof(struct node));
   temp->data=n;
   temp->addr_next=NULL;
   temp->addr_prev=NULL;
   while(curr->data!=data)
    {
        curr=curr->addr_next;
    }
    temp->addr_next=curr->addr_next;
    curr->addr_next->addr_prev=temp;
    curr->addr_next=temp;
    temp->addr_prev=curr;
}
void deleteloc(int loc)
{
    curr=start;
    for(int i=1;i<loc;i++)
    {
        prev=curr;
        curr=curr->addr_next;
    }
    prev->addr_next=curr->addr_next;
    prev->addr_next->addr_prev=prev;
    free(curr);
}
void deletenode(int n)
{
     curr=start;
    while(curr->data!=n)
    {
        prev=curr;
        curr=curr->addr_next;
    }
    prev->addr_next=curr->addr_next;
    prev->addr_next->addr_prev=prev;
    free(curr);
}