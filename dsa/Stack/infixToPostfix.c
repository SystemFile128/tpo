#include <stdio.h>
#include <string.h>
#define MAX 10                  //Global variables
int stack[MAX];                 //Global variaa*(b+c)/dbles
char infix[MAX], postfix[MAX];                  //Global variables
int top = -1;                   //Global variables


void push(char c)               // function for push
{
    top++;
    stack[top] = c;
}
char pop()              // function for pop
{
    char val = stack[top];
    top--;
    return val;
}
int isempty()               // function to check is empty
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int precedence(char c)      //Precedence function
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

void infix_to_postfix()     // Conversion function
{
    int i, j = 0;
    char symbol, val;
    for (i = 0; i < strlen(infix); i++)  // to scan the infix expression
    {
        symbol = infix[i];
        switch (symbol)
        {
        case '(':   //to push ( to stack
            push(symbol);
            break;
        case ')':    // to pop all elements untill ) encounters
            while ((val = pop()) != '(')
            {
                postfix[j] = val;
                j++;
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            while ((precedence(symbol) <= precedence(stack[top])) && !isempty())//checks the incoming operator to topmost operator of stack and performs operations accordingly
            {
                postfix[j] = pop();
                j++;
            }
            push(symbol);
            break;
        default:  // if incoming character is operand then it would be pushed to stack
        {
            postfix[j] = symbol;
            j++;
        }
        break;
        }
    }
    while (!isempty())
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';  //adds null at the end
}

// Main function
void main()
{
    printf("Enter the infix Expression:");
    gets(infix); //stores the value entered in infix expression
    infix_to_postfix(); // function call
    printf("Postfix Expression is: ");
    for (int i = 0; i < MAX + 1; i++)
        printf("%c", postfix[i]);
}