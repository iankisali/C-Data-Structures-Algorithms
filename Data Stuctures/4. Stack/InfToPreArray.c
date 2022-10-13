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
    if (isFull)
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

void reverse(char *expression)
{

}

void brackets(char* expression)
{

}

int getPost(char* expression)
{

}

void infixToPrefix(char *expression)
{

}

int main()
{

}