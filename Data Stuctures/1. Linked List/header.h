#ifndef _HEADER_
#define _HEADER_

#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node* next;
};

void printList(struct Node* n);
void insertHead(struct Node** head_ref, int new_data);
void insertAfter(struct Node* prev_node, int new_data);
void insertEnd(struct Node**, int new_data);
#endif 