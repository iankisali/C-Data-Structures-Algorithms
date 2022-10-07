// Linked list implementation of stack

#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *top = 0;

/*implementing push operation in stack*/
void push(int num)
{
    //create new node and allocate memory
    struct node *newnode;
    newnode = malloc(sizeof(struct node));

    //data of new node will be num
    newnode->data = num;

    //new node will point to top which is initially 0
    newnode->link = top;

    //update top to be newnode
    top = newnode;
}

/*implementing pop operation*/
void pop()
{
    //create temp to store top value
    struct node *temp = top;

    if (top == NULL)
        printf("\nStack in empty ");

    else
    {
        printf("\nTop element to be popped is : %d ", top->data);
        //update top to next element
        top = top->link;
        //free unused memory
        free(temp);
    }
}

/*Implementing peek*/
void peek()
{
    if (top == NULL)
        printf("Stack is empty\n");
    else
    {
        printf("\nTop element is : %d ", top->data);
    }
}

/*Displaying elements in a stack from top element*/
void displayStack()
{
    struct node *temp = top;

    if (top == 0)
        printf("Stack is empty \n");

    else
    {
        while(temp != NULL)
        {
            printf(" %d ", temp->data);

            //update temp to point to next node
            temp = temp->link;
        }
    }
}

void main()
{
    push(4);
    push(9);
    push(7);

    printf("Printing stack : ");
    displayStack();

    pop();
    printf("\nPrinting stack : ");
    displayStack();

    peek();

    printf("\nPushing 15 and 3 : ");
    push(15);
    push(3);

    displayStack();

    pop();

    printf("\nPrinting stack : ");
    displayStack(); 

}
