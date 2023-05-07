#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void push(int);
void pop();
void display();
int a[5],top=-1;
int main()
{
	int ch,number,k;
	
	do
	{
	
	printf("\n\t1-push in stack\t\t2-pop from stack\t\t3-display stack");
	printf("\n\nenter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("\nenter value to push in stack:");
			scanf("\n%d",&number);
			push(number);
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		default:
		    printf("\nINVALID CHOICE....!!!");
			
	}  
	printf("\ndo you want to continue...press 1:");
	scanf("%d",&k);
	}while(k==1);
	return 0;
}
void push(int n)
{
	if(top>=n-1)
	{
		printf("\nSTACK OVERFLOW");
	}
	else
	{
		top++;   // first we have to increament top by 1 and then place the element.
		a[top]=n;
	}
}
void pop()
{
	if(top<=-1) 
	{
		printf("\nSTACK UNDERFLOW");
	}
	else
	{
		printf("\nthe popped element is:%d",a[top]);
		top--;
	}
}
void display()
{
	int i;
	if(top>=0)
	{
		printf("\nstack elements are:");
		for(i=top;i>=0;i--)
		{
			printf("\n%d",a[i]);
		}
	}
	else
	{
		printf("\nstack is empty:");
	}
}
