#include <stdio.h>
#include <conio.h>

#define MAX 3
int stack[MAX];
int top = -1;

/*checking if stack is empty*/
int isEmpty()
{
    if (top == -1)
        return 1;
    
    else 
        return 0;
}
/*check if stack is full*/
int isFull()
{
    if (top == MAX)
        return 1;
    else
        return 0;
}

/*Display stack from top element*/
void displayStack()
{
    int i;
    for (i = top; i >= 0; i--)
    {
        printf(" %d -> ",stack[i]);
    }
}

/*check top element value*/
void peek()
{
    if (top == -1)
    {printf("Stack is empty :\n");}
    else
        printf("\nTop element is %d ",stack[top]); 
}

/*pushing into stack - passing by value*/
/*void push(int data)
{
    if (!(isFull))
    {
        top = top + 1;
        stack[top] = data;
    }
    else
    {
        printf("Stack is full.\n");
    }
}*/
/*pushing into stack - passing by reference*/
void push()
{
    int num;
    printf("\nEnter value to push : ");
    scanf("%d", &num);

    if (top == (MAX - 1)) // or use if (isFull) op == (MAX - 1)
    {
        printf("Overflow condition ");
        printf("\nFinal List is : ");
        displayStack();
        return;
    }
    else
    {
        top++;
        stack[top] = num;
    }
}

/*popping*/
int pop()
{
    int data;

    if (top == -1)
    {
        printf("Underflow condition :\n");
    }
    else
    {
        data = stack[top];
        top--;
        printf("\nThe popped value is %d \n", data);
    }
}



int main()
{
    int ch;
    
    push();
    printf("Stack becomes :");
    displayStack();

    push();
    printf("Stack becomes :");
    displayStack();

    peek();

    push();
    printf("Stack becomes :");
    displayStack();

    pop();
    printf("Stack becomes :");
    displayStack();

    push();
    printf("Stack becomes :");
    

}