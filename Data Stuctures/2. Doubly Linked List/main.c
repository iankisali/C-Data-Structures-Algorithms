#include "header.h"

int main()
{
    /*Let us create a DLL with three nodes*/
    /*We first initialize the nodes */
    struct Node *head;
    struct Node *first = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    /*We now allocate memory to the nodes*/
    first = malloc(sizeof(struct Node));
    second = malloc(sizeof(struct Node));
    third = malloc(sizeof(struct Node));

    
    /*Assigning values and connecting the nodes*/

    /*First node with data as 5 and connection*/
    first->data = 5;
    first->next = second;
    first->prev = NULL;

    /*Second node with data as 9 and connection*/
    second->data = 9;
    second->next = third;
    second->prev = first;

    /*Third node with data as 6 and connection*/
    third->data = 6;
    third->next = NULL;
    third->prev = second;
    
    /*save address of first node as head*/
    head = first;

    printf("The initial list is : ");
    printList(head);

    printf("\nPrinting recursively in reverse : ");
    printReverseRec(head);

    printf("\nInserting 7 at the head :");
    insertHead(&head, 7);
    printList(head);

    printf("\nInserting 8 after a node :");
    insertAfter(head->next, 8);
    printList(head);

    printf("\nInserting 3 at end :");
    insertEnd(&head, 3);
    printList(head);

     printf("\nDeleting head node becomes : ");
    deleteHead(&head);
    printList(head);

    printf("\nDeleting at position 3");
    deleteUser(&head, 3);
    printf(" and the list becomes :");
    printList(head);

    printf("\nDeleting last node becomes : ");
    deleteEnd(&head);
    printList(head);

    printf("\nReversing DLL iteratively : ");
    reverseDLL(&head);
    printList(head);

    // deleteUserInput(&head);
    // printf("The list becomes : ");
    // printList(head);

    return 0;
}