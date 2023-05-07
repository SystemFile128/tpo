#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct stack *addr;
}*temp;
struct node *top=NULL;
void main ()
{
    int ch,n;
    while(1)
    {
    printf("\n1]push \n2]pop \n3]display \n4]exit");
    scanf("%d",&ch);
    switch(ch)
       {
        case 1:
          printf("\nEnter element to push  : ");
            scanf("%d",&n);
            printf("%d is pushed",n);
             push(n);
             break;

        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4 :
            exit(0);
            break;
        default :
            printf("\nEnter correct choice");


       }
    }
	
}
void push(int n)
{
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=n;
    temp->addr=top;
    top=temp;
}
void pop()
{
    temp=top;
    printf("%d is poped ",top->data);
    top=top->addr;
    free(temp);

}
void display()
{
    if(top==NULL)
    {
        printf("\nStack is empty");

    }
    else
    {
        temp=top;
        while(temp!=NULL)
        {
            printf("\n%d",temp->data);
            temp=temp->addr;
        }
    }
}
