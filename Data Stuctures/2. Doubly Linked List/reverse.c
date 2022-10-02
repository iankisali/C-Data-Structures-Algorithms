#include "header.h"
/*Program to reverse a doubly linked list*/

void reverseDLL(struct Node** head)
{
    struct Node* temp = NULL;
    struct Node* current = *head;

    /*swapping next and prev of all nodes of DLL*/
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    /*changing head but check list if empty or has one node*/
    if (temp != NULL)
        *head = temp->prev;
}