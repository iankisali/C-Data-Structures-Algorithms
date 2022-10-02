/* This is a function to reverse a linked list*/
#include "header.h"

/*Reversing Linked List Iteratively*/

void reverseIterative(struct Node** head)
{
    /*initializing 3 pointers prev&next as NULL and current as head*/
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    /*iterating the linked list*/
    while (current != NULL)
    {
        //store next node as next
        next = current->next;

        //change next of current - actual reversing
        current->next = prev;

        //move prev and current pointer one position ahead
        prev = current;
        current = next;
    }
    *head = prev;
}


//Reversing Linked List using Recursion
/*struct Node* head;
void reverseRecursively(struct Node** p)
{
    if ((*p)->next == NULL)
    {
        
        return *p;
    }
    reverseRecursively((*p)->next);
    struct Node* rest = (*p)->next;
    rest->next = head;
    (*head)->next = NULL;
}*/


/*Reversing Linked list using tail recursive approach*/

void reverseTail(struct Node* current, struct Node* previous, struct Node** head)
{
    //Base Case make last node to be head
    if (!current->next)
    {
        //current node to be head
        *head = current;
        //update next node to previous node
        current->next = previous;
        return;
    }
    //save current->next node for recursive call
    struct Node* next = current->next;
    //update next
    current->next = previous;
    reverseTail(next, current, head);
}

void reverseTailRec(struct Node** head)
{
    if (!head)
        return;
    
    //call reverseTail with prev as NULL
    reverseTail(*head, NULL, head);
}



/*Reversing linked list using head recursive method*/

/*void reverseHead(struct Node* current, struct Node* previous, struct Node** head)
{
    //base case - if current is last node
    if (current->next = NULL)
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
    if (*head == NULL || (*head)->next == NULL)
        return;

    //call reverseHead with prev as NULL
    reverseHead(*head, NULL, head);
}
*/