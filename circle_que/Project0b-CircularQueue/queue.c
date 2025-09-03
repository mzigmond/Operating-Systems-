#include <stdio.h>
#include "queue.h"
/* This method is used to initialize a variable to be tail pointer to a 
process queue. Return a pointer to the tail of an empty process queue; 
i.e. NULL. */
struct queueNode * makeEmptyQueue() {
    return NULL;
}

/* Return TRUE if the queue whose tail is pointed to by q is empty.
Return FALSE otherwise. */
int emptyQ(struct queueNode *q) {
    if (q == NULL){
        return 1; // Returns TRUE 
    } else {
        return 0; // Returns FALSE
    }
}

/* Insert the queueNode pointed to by p into the queue whose 
tail-pointer is pointed to by q. */
void insertQ(struct queueNode **q, struct queueNode *p) {
    struct queueNode *s;
    if (emptyQ(*q))
    {
        p -> next = p; // circular queue, points to itself
        *q = p; // only thing in queue is p, so p is tail and points to itself
    }
    else
    {
        s = (*q) -> next;
        p->next = s;
        (*q) -> next = p;
        *q = p;
    }
}

/* Remove the first (i.e. head) element from the queue whose 
tail-pointer is pointed to by q. Return NULL if the queue is empty; 
otherwise return the pointer to the removed queueNode. Update the 
queue’s tail pointer if necessary. (Note: since *q is a pointer to the tail,
(*q)->next is the head, if it exists)*/
struct queueNode *removeQ(struct queueNode **q) {
    struct queueNode *s;
    if (emptyQ(*q))
    {
        return NULL;
    }

    if (*q == (*q) -> next){
        s = *q;
        *q = NULL;
        return s;
    }
    else
    {
        s = (*q) -> next;
        (*q) -> next = s ->next;
        return s;
        /* disconnect the head node from the queue, update the tail,
        return the head */
    }
    return NULL;
}

/* Return a pointer to the first queueNode from the queue whose tail is 
pointed to by q. Do not remove this queueNode from the queue. Return NULL 
if the queue is empty. */
struct queueNode *headQ(struct queueNode *q)
{
    if (emptyQ(q)) return NULL;
    else return q->next;
}

