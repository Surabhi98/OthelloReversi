#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disksAndPlayers.h"
#include "LinkedLists.h"
/* Contains the functions used to create a stack using linked lists implementation
 and hence forth insert the possible moves for the desired player in the list,
 print the list and free the list when not required. */


/* Insert a new value into the list in sorted order */
 void insert (ListNodePtr *sPtr, int newRow, int newCol )
{
    ListNodePtr newPtr = malloc( sizeof( ListNode ) ); /* create node */

        newPtr->x = newRow; /* place value of position x in node */
		newPtr->y = newCol; /* place value of position y in node */
		if( *sPtr == NULL)
        newPtr->nextPtr = NULL; /* node does not link to another node */

        else
			newPtr->nextPtr = *sPtr;

            *sPtr = newPtr;



}


void delete( ListNodePtr *sPtr )
{
    /* delete first node */

        ListNodePtr tempPtr = *sPtr; /* hold onto node being removed */
        *sPtr = ( *sPtr )->nextPtr; /* de-thread the node */
        free( tempPtr ); /* free the de-threaded node */



} /* end function delete */


void printList( ListNodePtr currentPtr )
{

       /* while not the end of the list */
        while ( currentPtr != NULL ) {
            printf( "\n*) %d%d    ", currentPtr->x , currentPtr->y); //prints the list of possible positions

            currentPtr = currentPtr->nextPtr;
        } /* end while */


}












