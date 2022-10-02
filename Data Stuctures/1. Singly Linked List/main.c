#include "header.h"


//this is the main function i.e driver program to test the functions
int main()
{
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;

    //dynamic memory allocation i.e allocating 3 nodes in heap
    head = (struct Node*)malloc(sizeof(struct Node)); // head = 
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

     /* Three blocks have been allocated dynamically.
     We have pointers to these three blocks as head,
     second and third
       head           second           third
        |                |               |
        |                |               |
    +---+-----+     +----+----+     +----+----+
    | #  | #  |     | #  | #  |     |  # |  # |
    +---+-----+     +----+----+     +----+----+
 
   # represents any random value.
   Data is random because we haven’t assigned
   anything yet  */

   //now let's assign data to these nodes
    head->data = 2; //assigns 2 as the head node
    head->next = second; //links first node with second node

     /* data has been assigned to the data part of the first
     block (block pointed by the head). And next
     pointer of first block points to second.
     So they both are linked.
 
       head          second         third
        |              |              |
        |              |              |
    +---+---+     +----+----+     +-----+----+
    | 2  | o----->| #  | #  |     |  #  | #  |
    +---+---+     +----+----+     +-----+----+  */
  
    //now let us assign data to second node
    second->data = 4; //assigns 4 to second node
    second->next = third; //links second node with third node
    /* data has been assigned to the data part of the second
     block (block pointed by second). And next
     pointer of the second block points to the third
     block. So all three blocks are linked.
 
       head         second         third
        |             |             |
        |             |             |
    +---+---+     +---+---+     +----+----+
    | 2  | o----->| 4 | o-----> |  # |  # |
    +---+---+     +---+---+     +----+----+      */
    //now let us assign data to third node
    third->data = 6; //assigns 6 to last node
    third->next = NULL; //links the last pointer to NULL

    /* data has been assigned to data part of third
    block (block pointed by third). And next pointer
    of the third block is made NULL to indicate
    that the linked list is terminated here.
 
     We have the linked list ready.
 
           head
             |
             |
        +---+---+     +---+---+       +----+------+
        | 2  | o----->|  4 | o-----> |  4 | NULL |
        +---+---+     +---+---+       +----+------+  */

        //printing the list by calling the function printlist()
        printf("This is the initial list : ");
        printList(head);

        printf("\nPrinting list recursively in reverse : ");
        printReverse(head);

        printf("\n Inserting 5 as new head : ");

        insertHead(&head, 5);
        printList(head);

        printf("\n Inserting 15 after a node : ");
        insertAfter(head->next, 15);
        printList(head);

        printf("\n Inserting 9 as the end : ");
        insertEnd(&head, 9);
        printList(head);

        printf("\n Reversing the linked list using iterative approach becomes : ");
        reverseIterative(&head);
        printList(head);

        printf("\n Deleting the end : ");
        deleteEnd(&head);
        printList(head);

        printf("\n Reversing linked list using tail recursive approach : ");
        reverseTailRec(&head);
        printList(head);


        printf("\n Deleting the head : ");
        deleteHead(&head);
        printList(head);

      printf("\n Deleting at position 2 ");
      deleteUser(&head, 2);
      printf(" The list becomes : ");
      printList(head);

      /*printf("\n Reversing linked list using head recursive approach : ");
      reverseHeadRec(&head);
      printList(head);*/

      //I have commented out the deleteList since i dont want do delete my list at the moment
      /*
      printf("\n Deleting whole list : ");
      deleteList(&head);
      printList(head);
      */

        return 0;
}