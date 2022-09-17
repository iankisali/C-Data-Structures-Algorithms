#include "header.h"
/* This is a function for deletion of a node


/*This is a function to delete the head*/
void deleteHead(struct Node** head)
{
    //new temp to store head node
    struct Node* temp = *head;

    //point head to the next node
    *head = (*head)->next;

    //free unused memory temp
    free(temp);
}


/*2. Deletion at end*/
void deleteEnd(struct Node** head)
{
    //new temp to store head
    struct Node* temp = *head;
    //while temp data is not equal to NULL
    while (temp->next->next != NULL)
    {
        //next node equal to temp
        temp = temp->next;
    }
    //make the last node equal no NULL
    temp->next = NULL;

    //free unused memory
    //free(temp);
}



/*This is function to delete the whole list*/
void deleteList(struct Node** head)
{
    //make prev equal to head
  struct Node* prev = *head;
  
  //while value is head
  while (*head)
  {
    //next value equal to head value
    *head = (*head)->next;
    //delete prev
    free(prev);
    //update head value to equal prev
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