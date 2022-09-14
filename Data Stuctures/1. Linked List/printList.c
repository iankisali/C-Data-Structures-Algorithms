#include "header.h"

void printList(struct Node* n)
{
  while (n != NULL)
  {
    printf(" %d ", n->data);
    n = n->next;
  }
}