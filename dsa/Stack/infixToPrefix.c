#include <stdio.h>
#include <string.h>
#define MAX 10      //Global variables
char infix[MAX], prefix[MAX], stack[MAX];//Global variables
int top = -1;//Global variables

// Function to reverse string
void reverse(char arr[])
{
    int i, j = 0;
    for (i = 0; i < strlen(arr); i++)
    {
        top++;
        stack[top] = arr[i];
    }
    while (top != -1)
    {
        arr[j] = stack[top];
        j++;
        top--;
    }
    arr[j] = '\0';
}

void push(char c) // function for push
{
    top++;
    stack[top] = c;
}
char pop() // function for pop
{
    char val = stack[top];
    top--;
    return val;
}
int isempty() // function to check is empty
{
    if (top == -1)
        return 1;
    else
        return 0;
}

// Precedence function
int precedence(char c)
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



void infix_to_prefix() // Function for conversion of infix to prefix
{
    int i, j = 0;
    char symbol, val;
    for (i = 0; i < strlen(infix); i++) // to scan the infix expression
    {
        symbol = infix[i];
        switch (symbol)
        {
        case ')': //to push ) to stack
            push(symbol);
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            while (!isempty() && precedence(symbol) <= precedence(stack[top]))
                prefix[j++] = pop();
            push(symbol);
            break;
        case '(':
            while ((val = pop()) != ')')  // to pop all elements untill ( encounters
                prefix[j++] = val;
            break;
        default:     // if incoming character is operand then it would be pushed to stack
            prefix[j++] = symbol;
            break;
        }
    }
    while (!isempty())
        prefix[j++] = pop();
    prefix[j] = '\0';     //adds null at the end
    reverse(prefix);
}

// Main function
int main()
{
    printf("Enter the infix expression:");
    gets(infix); //stores the value entered in infix expression
    reverse(infix); // function call to reverse the infix expression
    infix_to_prefix();// function call
    printf("Prefix Expression is: ");
    for (int i = 0; i < MAX + 1; i++)
        printf("%c", prefix[i]);
        return 0;
}