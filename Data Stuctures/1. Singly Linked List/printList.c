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

/*printing linked list in reverse using recursion*/
void printReverse(struct Node* head)
{
  //base case is when value equal NULL
  if (head == NULL)
  {
    return;
  }
  //recursive call
  printReverse(head->next);
  printf(" %d ", head->data);
}