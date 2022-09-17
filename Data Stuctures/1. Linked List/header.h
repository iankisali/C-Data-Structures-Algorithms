#ifndef _HEADER_
#define _HEADER_

#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node* next;
};

void printList(struct Node* temp);
void insertHead(struct Node** head_ref, int new_data);
void insertAfter(struct Node* prev_node, int new_data);
void insertEnd(struct Node**, int new_data);
void deleteHead(struct Node** head);
void deleteList(struct Node** head);
void deleteEnd(struct Node** head);
void deleteUser(struct Node** head, int position);
void reverseIterative(struct Node** head);
void reverseTail(struct Node* current, struct Node* previous, struct Node** head);
void reverseTailRec(struct Node** head);
void reverseHead(struct Node* current, struct Node* previous, struct Node** head);
void reverseHeadRec(struct Node** head);

#endif 