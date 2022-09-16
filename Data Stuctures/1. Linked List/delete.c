#include "header.h"
/* This is a function for deletion of a node


/*This is a function to delete the head*/
void deleteHead(struct Node** head)
{
    struct Node* temp = *head;
    *head = (*head)->next;

    //free unused memory
    free(temp);
}


/*2. Deletion at end*/
void deleteEnd(struct Node** head)
{
    struct Node* temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;

    //free unused memory
    //free(temp);
}



/*This is function to delete the whole list*/
void deleteList(struct Node** head)
{
  struct Node* prev = *head;

  while (*head)
  {
    *head = (*head)->next;
    free(prev);
    prev = *head;
  }
}

/*This is a function to delete at a position specified by user*/

void deleteUser(struct Node** head, int position)
{
    struct Node* temp = *head;

    int num;
    if (position == 0)
    {
        printf("\n Element deleted is : %d\n",temp->data);
        *head = (*head)->next;
        temp->next = NULL;
        free(temp);
    }
    else 
    {
        for(num = 0; num < position - 1; num++)
        {
            temp = temp->next;
        }
        struct Node* delete = temp->next;

        temp->next = temp->next->next;
        printf(" and element deleted is : %d\n", delete->data);
        delete->next = NULL;
        free(delete);
    }
    
}