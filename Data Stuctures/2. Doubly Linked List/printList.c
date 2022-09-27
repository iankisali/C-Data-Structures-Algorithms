#include "header.h"

/*This is a fuction to print the list*/
void printList(struct Node* temp)
{
    while(temp != NULL)
    {
        //print temp data
        printf(" %d ", temp->data);
        //make temp point to next data
        temp = temp->next;
    }
}

/*Function to print reverse list recursively*/
void printReverseRec(struct Node* temp)
{
    if(temp == NULL)
    {
        return;
    }
    
    //traverse list to end
    printReverseRec(temp->next);

    //print data starting from end
    printf(" %d ", temp->data);
}