#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *addr;
}*start,*temp,*curr,*prev;

void create(int);
void traverse();
void insertLoc(int,int);
void insertNode(int,int);
void deleteLoc(int);
void deleteNode(int);

int main()
{
    int ch,n,loc,data;
    do{
    printf("\n1-create\n2-traverse\n3-Insert at given location\n4-Insert after given Data\n5-Delete after given location");
    scanf("\n%d",&ch);
    switch (ch)
    {
    case 1:
        printf("\nEnter the Number to add in singly linked List : ");
        scanf("\n%d",&n);
        create(n);
        break;
    case 2:
        traverse();
        break;
    case 3:
        printf("\nEnter the Number to add in singly linked List : ");
        scanf("\n%d",&n);
        printf("\nEnter the Location :");
        scanf("\n%d",&loc);
        insertLoc(n,loc);
        break;
    case 4:
        printf("\nEnter the Number to add in singly linked List : ");
        scanf("\n%d",&n);
        printf("\nEnter the data :");
        scanf("\n%d",&data);
        insertNode(n,data);
        break;
    case 5:
        printf("\nEnter the Location :");
        scanf("\n%d",&loc);
        deleteLoc(loc);
        break;
    case 6:
        printf("\nEnter the data :");
        scanf("\n%d",&data);
        deleteNode(data);
        break;
    default:
        break;
    }
    printf("Do you want to continue press 1 :");
    scanf("%d",&ch);
    }while(ch==1);
    return 0;
}
void create(int n)
{
    temp=malloc(sizeof(struct node));
    temp->data=n;
    temp->addr=NULL;
    if (start==NULL)
    {
        start=temp;
    }
    else
    {
        curr=start;
        while (curr->addr!=NULL)
        {
            curr=curr->addr;
        }
        curr->addr=temp;
    }
}
void traverse()
{
   if (start==NULL)
   {
    printf("Linked List is EMPTY..!!");
   }
   else
   {
    curr=start;
    while (curr!=NULL)
    {
        printf("|%d||%u|-->",curr->data,curr->addr);
        curr=curr->addr;   
    }
   }
}
void insertLoc(int n,int loc)
{
    temp=malloc(sizeof(struct node));
    temp->data=n;
    curr=start;
    for(int i=1;i<loc-1;i++)
    {
        curr=curr->addr;
    }
    temp->addr=curr->addr;
    curr->addr=temp;
}
void insertNode(int n,int data)
{
    temp=malloc(sizeof(struct node));
    temp->data=n;
    curr=start;
    while(curr->data!=data)
    {
        curr=curr->addr;
    }
    temp->addr=curr->addr;
    curr->addr=temp;
}

void deleteLoc(int loc)
{
    curr=start;
    for(int i=1;i<=loc;i++)
    {
        prev=curr;
        curr=curr->addr;
    }
    prev->addr=curr->addr;
    curr->addr=NULL;
    free(curr);
}
void deleteNode(int data)
{
    curr=start;
    while(curr->data!=data)
    {
        prev=curr;
        curr=curr->addr;
    }
    prev->addr=curr->addr;
    curr->addr=NULL;
    free(curr);
}
