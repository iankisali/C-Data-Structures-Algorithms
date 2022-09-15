#include "header.h"
/*Given a reference (pointer to pointer) to head of list and an int, 
inserts new node at front*/
void insertHead(struct Node** head_ref, int new_data)
{
    /*1.allocate node*/
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    
    /* 2. put in data */
    new_node->data = new_data;

    /* 3. make next of new node as head */
    new_node->next = (*head_ref);

    /* 4.move head to point to new node */
    (*head_ref) = new_node;
}

void insertAfter(struct Node* prev_node, int new_data)
{
    /*1. check if previous node is NULL*/
    if (prev_node == NULL)
    {
        printf("Previous node cannot be NULL");
        return;
    }
    /*2. allocate new node*/
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    /*3. put in data*/
    new_node->data = new_data;

    /*4. make next of new node as prev node*/
    new_node->next = prev_node->next;

    /*5. move next of prev node as new node*/
    prev_node->next = new_node;

}

/*given a reference (pointer to pointer) to head of list and an int, appends nw node at end*/
void insertEnd(struct Node** head_ref, int new_data)
{
    /*1. allocate node*/
    struct Node* new_node = malloc(sizeof(struct Node));

    struct Node *last = *head_ref;
    /*2. Put in data*/
    new_node->data = new_data;

    /*3. new node going to be last node, so make next of ot as NULL */
    new_node->next =  NULL;

    /*4. if linked list empty make new node as head*/
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    /*5. else traverse till find last node */
    while (last->next != NULL)
        last = last->next;

    /*6. change next of last node */
    last->next = new_node;
    return;
}