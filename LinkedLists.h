/* File containing the prototypes used for the linked lists */

/* self-referential structure */
struct listNode {
    //char data; /* each listNode contains a character */
    int x;
    int y;
    struct listNode *nextPtr; /* pointer to next node */
}; /* end structure listNode */


typedef struct listNode ListNode; /* synonym for struct listNode */
typedef ListNode *ListNodePtr; /* synonym for ListNode* */

/* prototypes */
void insert( ListNodePtr *sPtr, int newRow, int newCol );
void printList( ListNodePtr currentPtr );
void delete( ListNodePtr *sPtr );


