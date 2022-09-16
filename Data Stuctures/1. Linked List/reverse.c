/* This is a function to reverse a linked list*/
#include "header.h"

/*Reversing Linked List Iteratively*/

void reverseIterative(struct Node** head)
{
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL)
    {
        //store nxt
        next = current->next;

        //reverse current one position
        current->next = prev;

        //move pointer one position ahead
        prev = current;
        current = next;
    }
    *head = prev;
}

/*Reversing Linked list using tail recursive approach*/

void reverseTail(struct Node* current, struct Node* previous, struct Node** head)
{
    if (!current->next)
    {
        *head = current;
        current->next = previous;
        return;
    }
    struct Node* next = current->next;
    current->next = previous;
    reverseTail(next, current, head);
}

void reverseTailRec(struct Node** head)
{
    if (!head)
        return;

    reverseTail(*head, NULL, head);
}

/*Reversing linked list using head recursive method*/

void reverseHead(struct Node* current, struct Node* previous, struct Node** head)
{
    //base case - if current is last node
    if (current->next= NULL)
    {
        //update head of linked list
        *head = current;
        //update next to previous node
        current->next = previous;
        return;
    }

    //recursive call for next node
    reverseHead(current->next, current, head);
    //update next to prev node
    current->next = previous;
}

void reverseHeadRec(struct Node** head)
{
    //if linked list is empty or contains single node
    if (!head)
        return;

    //call reverseHead with prev as NULL
    reverseHead(*head, NULL, head);
}
