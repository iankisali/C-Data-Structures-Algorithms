/*C program to convert Infix to Postfix Using Stack implemented using array*/


#include <stdio.h>
#include <ctype.h> // isDigit()
#include <stdlib.h> // exit()
#include <string.h>

/*Size of array*/
#define MAXSIZE 100
char stack[MAXSIZE];
int top = -1;

void push(char x)
{
    if (top >= MAXSIZE)
    {
        printf("Overflow condition ");
    }
    else
    {
        top++;
        stack[top] = x;
        //stack[++top] = x 
    }
}

char pop()
{
    if (top < 0)
    {
        printf("Underflow condition");
        getchar();
        exit(1);
    }
    else
    {
        top--;
        return stack[top];
        // return stack[top--]
    }
}

int operators(char symbol)
{
    if (symbol == '^' || symbol == '*' || symbol == '+' || symbol == '/' || symbol == '-')
         return 1;
    else
        return 0;
}


int precedence(char symbol)
{
    if (symbol == '^') /*highest precedence*/
        return 3;
    else if (symbol == '*' || symbol == '/')
        return 2;
    else if (symbol == '+' || symbol == '-') /*lowest precedence*/
        return 1;
    else
        return 0;
}

void InfixPostfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    char item;
    char x;
    push('(');
    strcat(infix, ")");

    item = infix[i];

    while (item != '\0')
    {
        if (item == '(')
            push(item);

        else if (isdigit(item) || isalpha(item))
        {
            postfix[j] = item;
            j++;
        } 
        else if (operators(item) == 1) 
        {
            x = pop();
            while (operators(x) == 1 && precedence(x) >= precedence(item))
            {
                postfix[j] = x;
                j++;
                x = pop();
            }
            push(x);
            push(item);
        }
        else if (item == ')')
        {
            x = pop();
            while (x != '(')
            {
                postfix[j] = x;
                j++;
                x = pop();
            }
        }
        else{
            printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
			getchar();
			exit(1);
        }
        i++;
        item = infix[i];
    }
    if (top > 0)
    {
        printf("\nInvalid infix Expression.\n");        /* the it is illegeal  symbol */
		getchar();
		exit(1);
    }
    postfix[j] = '\0';
}

int main()
{
    char infix[MAXSIZE], postfix[MAXSIZE];

    printf("Enter infix expression : ");
    gets(infix);
    InfixPostfix(infix, postfix);
    printf("\nPostfix expression : ");
    puts(postfix);

    return 0;
}