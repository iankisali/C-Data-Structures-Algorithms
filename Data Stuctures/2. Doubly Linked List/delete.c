#include "header.h"

/*This files contains functions for deletion*/

/*delete from beginning*/
void deleteHead(struct Node** head)
{
    //create a temp variable to store head
    struct Node* temp;

    if (*head == NULL)
    {
        printf(" Cannot delete from an empty list ");
        return;
    }
    else
    {
        temp = *head;

        //update head value to next value in LL
        *head = (*head)->next;

        //head.Prev will equal NULL
        (*head)->prev = NULL;

        //free memory
        free(temp);
    }
    
}

void deleteUser(struct Node** head, int position)
{
    struct Node* temp = *head;
    
    while (position > 1)
    {
        temp = temp->next;
        position--;
    }
    //this line will make the the next of previous node point to the next node
    temp->prev->next = temp->next;

    //this line makes the previous of next node to be deleted point to prev node
    temp->next->prev = temp->prev;

    //free unused memory
    free(temp);
}

/*Function to delete last node*/
void deleteEnd(struct Node** head)
{
    //if head has one node
    if ((*head)->next == NULL)
        {
            //free the memory
            free(head);
            head = NULL;
        }
    //struct variable called temp
    struct Node* temp = *head, *prev_node;

    //traverse through DLL
    while(temp->next != NULL)
    {
        prev_node = temp;
        temp = temp->next;
    }
    //free memory of last node
    free(temp);
    //make previous nod.Next equal to NULL
    prev_node->next = NULL;
}

void deleteUserInput(struct Node** head)
{
    int position, num = 0;
    struct Node* temp = *head;
    printf("\nEnter positiion to delete a node : ");
    scanf("%d", &position);
    if (position == 1)
    {
        deleteHead;
        return;
    }
    while (num < position)
    {
        temp = temp->next;
        num++; 
    }
    //this line will make the the next of previous node point to the next node
    temp->prev->next = temp->next;

    //this line makes the previous of next node to be deleted point to prev node
    temp->next->prev = temp->prev;

    //free unused memory
    free(temp);
}