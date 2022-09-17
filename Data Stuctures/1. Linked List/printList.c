#include "header.h"

/*Function to print Linked List*/
void printList(struct Node* n)
{
  //as long as list is not NULL
  while (n != NULL)
  {
    //print the data of the node
    printf(" %d ", n->data);
    //update to the next data in node
    n = n->next;
  }
}