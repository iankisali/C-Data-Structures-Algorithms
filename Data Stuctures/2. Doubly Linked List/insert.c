#include "header.h"

/*Inserting node at head*/

/*Given a reference (pointer to pointer) to head and an int as new_data, inserts node on front of list*/
void insertHead(struct Node** head, int new_data)
{
    //allocating a new node
    struct Node* newNode = malloc(sizeof(struct Node));

    //assigning data to new node
    newNode->data = new_data;

    //make previous as NULL
    newNode->prev = NULL;

    //make next point to head node
    newNode->next = (*head);

    //make previous of head node to new node
    if ((*head) != NULL)
        (*head)->prev = newNode;

    //make head to be new node
    (*head) = newNode; 
}

/*Inserting a node after given node*/
void insertAfter(struct Node* prevNode, int new_data)
{
    //allocating memory to new node
    struct Node* newNode = malloc(sizeof(struct Node));

    //allocate data to new node
    newNode->data = new_data;

    //make newNode.prev equal to prevNode.prev
    newNode->next = prevNode->next;

    //make prevNode.next equal newNode
    prevNode->next = newNode;

    //make newNode.prev equal prevNode
    newNode->prev = prevNode;

    if (newNode->next != NULL)
        newNode->next->prev = newNode;
}

/*Insrting node at end*/
void insertEnd(struct Node** head, int newData)
{
    //allocate memory of node
    struct Node* newNode = malloc(sizeof(struct Node));

    //assign data to new node
    newNode->data = newData;

    //assign NULL to next of newNode
    newNode->next = NULL;

    //store head node temporarily
    struct Node* temp = *head;

    //if LL empty make newNode head and return
    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;   
    }
    //traverse LL to last node
    while (temp->next != NULL)
        temp = temp->next;

    //make temp.next equal newNode
    temp->next = newNode;
    //prev will be temp
    newNode->prev = temp;
}