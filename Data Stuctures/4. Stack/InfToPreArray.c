/*Implementing infix to prefix conversing in stack using Arrays*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

# define MAXSIZE 50
char stack[MAXSIZE];
int top = -1; 

//check if stack empty
int isEmpty()
{
    return top == -1;
}

//check if is full
int isFull()
{
    return top == MAXSIZE - 1;
}

//return top value in stack
int peek()
{
    if (isEmpty())
        return INT_MIN;
    return stack[top];
}

//inserting value and increasint top
void push(char item)
{
    if (isFull())
        return;
    top++;
    stack[top] = item;
}

//removing top value
int pop()
{
    if (isEmpty())
        return INT_MIN;

    return stack[top--];
}

//check is operand
int operand(char symbol)
{
    return (symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z');
}

//checking precedence
int precedence(char ch)
{
    switch (ch)
    {
        case '+': case '-':
            return 1;

        case '*': case '/':
            return 2;

        case '^':
            return 3;
    }
    return -1;
}

/*reversing prefix*/
void reverse(char *expression)
{
    int size = strlen(expression);
    int j = size, i = 0;
    char temp[size];

    temp[j--] = '\0';
    while(expression[i] != '\0')
    {
        temp[j] = expression[i];
        j--;
        i++;
    }
    strcpy(expression, temp);
}

/*reversing brackets*/
void brackets(char* expression)
{
    int i = 0;
    while(expression[i] != '\0')
    {
        if (expression[i] == '(')
            expression[i] = ')';
        
        else if (expression[i] == ')')
            expression[i] = '(';
        i++;
    }
}

/*driver function*/
int getPost(char* expression)
{
    int i, j;

    for (i = 0, j = -1; expression[i]; i++)
    {
        //check if operand and add to output
        if (operand(expression[i]))
            expression[++j] = expression[i];

        else if(expression[i] == '(')
            push(expression[i]);

        //if ) pop &print from stack till (
        else if (expression[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                expression[++j] = pop(stack);

            if (!isEmpty(stack) && peek(stack) != '(')
                return -1;

            else
                pop(stack);
        }
        else //operator
        {
            while (!isEmpty(stack) && precedence(expression[i]) <= precedence(peek(stack)))
                expression[++j] = pop(stack);

            push(expression[i]);
        }
    }
    while (!isEmpty(stack))
        expression[++j] = pop(stack);

    expression[++j] = '\0';
}

void infixToPrefix(char *expression)
{

    int size = strlen(expression);
    //reverse
    reverse(expression);

    //change brackets
    brackets(expression);

    //get postfix
    getPost(expression);

    //reverse 
    reverse(expression);
}

int main()
{
    printf("Infix is :");
    
    char expression[] = "a+b*(c+d)";
    printf("%s\n", expression);
    infixToPrefix(expression);

    printf("Prefix is : ");
    printf("%s", expression);

    return 0;
}