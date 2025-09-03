#include "stack.h"

void push(struct node_t **stack, char value[])
{
    struct node_t * insertMe = malloc(sizeof(struct node_t));
    strncpy(insertMe->value, value, 20);
    insertMe->next = *stack;
    *stack = insertMe;
}

void pop(struct node_t **stack, char result[])
{
    /* pops the top node off the stack
       the value in the node is stored into result
       if the stack is empty (and equals NULL) the result should be returned as ""
    */
    struct node_t *popMe = *stack;
    strncpy(result,"", 20);
    if (popMe == NULL) return;
    strncpy(result,popMe->value, 20);
    *stack = popMe->next;
    popMe->next = NULL;
    free(popMe);
}

void dump(struct node_t *stack)
{
    /* prints out each value in the stack, starting from the top item and
       working your way to the bottom of the stack
    */
    
}
