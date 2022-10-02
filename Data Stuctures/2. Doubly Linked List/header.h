#ifndef _HEADER_
#define _HEADER_

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
} ;

void printList(struct Node* temp);
void printReverseRec(struct Node* temp);
void insertHead(struct Node** head, int new_data);
void insertAfter(struct Node* prevNode, int new_data);
void insertEnd(struct Node** head, int newData);
void deleteHead(struct Node** head);
void deleteUser(struct Node** head, int position);
void deleteEnd(struct Node** head);
void deleteUserInput(struct Node** head);
void reverseDLL(struct Node** head);

#endif 