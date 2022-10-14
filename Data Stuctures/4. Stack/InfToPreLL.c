/*Imlementation of infix to prefix in Stack using Linked List*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack
{
    int top;
    unsigned capacity;
    //sorting string in int array
    int* array;
};

//creating stack
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));

    stack->top = -1;
    stack->capacity =capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));

    return stack;
}

//chack is stack is full
int isFull(struct Stack* stack)
{
    if (stack->top == stack->capacity - 1)
        printf("Overflow ");
    
    return stack->top == stack->capacity - 1; 
}

//check is stack is empty
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

//insert value in stack
void push(struct Stack* stack, char ch)
{
    if (isFull(stack))
        return;

    stack->array[++stack->top] = ch;
}

//removing top element
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

//return top without removing it
int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;

    return stack->array[stack->top];
}

//check operand
int operand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

//check precedence
//larger value == high precedence
int precedence(char ch)
{
    switch(ch)
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

//infix to prefix driver function
int getPrefix(char* expression)
{
    int i, j;

    //stack size equal to expression
    struct Stack* stack = createStack(strlen(expression));

    //check stack created
    if (!stack)
        return -1;

    for (i = 0, j = -1; expression[i]; ++i)
    {
        //check if operand
        if (operand(expression[i]))
            expression[++j] = expression[i];

        //if ( push to stack
        else if (expression[i] == '(')
            push(stack, expression[i]);

        //if ) pop and print till (
            else if (expression[i] == ')')
            {
                while (!isEmpty(stack) && peek(stack) != '(')
                    expression[++j] = pop(stack);

                if (!isEmpty(stack) && peek(stack) != '(')
                    return -1;

                else
                    pop(stack);
            }
            //if operator
            else
            {
                while (!isEmpty(stack) && precedence(expression[i]) <= precedence(peek(stack)))
                    expression[++j] = pop(stack);
                push(stack, expression[i]);
            }
    }
    while (!isEmpty(stack))
        expression[++j] = pop(stack);
    expression[++j] = '\0';
}

//reversing expression
void reverse(char *expression)
{
    int size = strlen(expression);
    int j = size, i = 0;
    char temp[size];

    temp[j--] = '\0';
    while (expression[i] != '\0')
    {
        temp[j] = expression[i];
        j--;
        i++;
    }
    strcpy(expression, temp);
}

//check for brackets 
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

void infixToPrefix(char *expression)
{
    //reversing expression
    reverse(expression);

    //change brackets
    brackets(expression);

    //get prefix
    getPrefix(expression);

    //reverse 
    reverse(expression);
}

int main()
{
    printf("Infix is :");

    char expression[] = "a+b*(c+d)";
    printf("%s", expression);
    infixToPrefix(expression);

    printf("\nPrefix is :");
    printf("%s", expression);

    return 0;
}