#include "header.h"

/*Function to print Linked List*/
void printList(struct Node* temp)
{
  //as long as list is not NULL
  while (temp != NULL)
  {
    //print the data of the node
    printf(" %d ", temp->data);
    //update to the next data in node
    temp = temp->next;
  }
}