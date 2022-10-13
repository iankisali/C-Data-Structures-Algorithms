/*  C program to implement Infix to postfix using linked list*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//stack type
struct Stack
{
    int top;
    unsigned capacity;
    int* array;
};


//creating a stack
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = malloc(sizeof(struct Stack));

    if (!stack)
        return NULL;

    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));

    return stack;
}

//check is stack empty
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

//peek top value
char peek(struct Stack* stack)
{
    return stack->array[stack->top];
}

//pop fuction
char pop(struct Stack* stack)
{
    if(!isEmpty(stack))
        return stack->array[stack->top--];
}

//push function
char push(struct Stack* stack, char c)
{
    stack->array[++stack->top] = c;
}

//chack for operand
int isOperand(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

//function to return precedence of operator
//higher value returned is high precedence
int precedence(char c)
{
    switch (c)
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

//infix to postfix function
int infixPostfix(char* expression)
{
    int x, y;

    //create stack equal to size
    struct Stack* stack = createStack(strlen(expression));

    //check if stack created successful
    if (!stack)
        return -1;

    for (x = 0, y = -1; expression[x]; ++x)
    {
        //if operand, add to output
        if (isOperand(expression[x]))
            expression[++y] = expression[x];

        //if ( push to stack
        else if (expression[x] == '(')
            push(stack, expression[x]);

        //if scanned output is ) pop and output till ( encountered

        else if (expression[x] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                expression[++y] = pop(stack);

            if (!isEmpty(stack) && peek(stack) != '(')
                return -1;

            else
                pop(stack);
        }

        //operator encountered
        else
        {
            while (!isEmpty(stack) && precedence(expression[x]) <= precedence(peek(stack)))
                expression[++y] = pop(stack);

            push(stack, expression[x]);
        }
    }

    //pop all operator from stack
    while (!isEmpty(stack))
        expression[++y] = pop(stack);

    expression[++y] = '\0';
    printf("%s", expression);
}

//main function
int main()
{
    char exp[] = "K+L-M*N+(O^P)*W/U/V*T+Q";

    
    infixPostfix(exp);
    return 0;
}