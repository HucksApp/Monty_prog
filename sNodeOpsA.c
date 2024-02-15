#include "monty.h"


/**
 * createSNode - Create a new node of stack_t
 * @num: data value of new stack node
 * Return: Pointer to the newly created node or NULL on failure
 */
stackk_t *createSNode(const int num)
{
    stackk_t *new;


    new = malloc(sizeof(stackk_t));
    if(!new)
        return (NULL);

    new->n = num;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}



/**
 * _deleteSNodeAt - Remove a node at a specific pos in the stack
 * @head: Pointer to the head pointing to the stack
 * @pos: index of the node to be removed
 * Return: TRUE if the node is successfully removed, FALSE otherwise
 */
int _deleteSNodeAt(stackk_t **head, unsigned int pos)
{
    unsigned int index = 0;
    stackk_t *curr = *head;


    if(!pos) /* index is top 0*/
    { /* advance the head to next*/    
        (*head) = curr->next;
        if((*head))
        /* the new head node  */
            (*head)->prev = NULL;
        curr->next = NULL; /*detach the del node*/
        free(curr);
        return(_TRUE);
    }
    while (index < pos)
    {
        curr = curr->next;
        index++;
        if(!curr)
            return (_FALSE);
    }
    /* node is at pos, detach del node*/
    curr->prev->next  = curr->next;
    if (curr->next) /*reattached is not last */
        curr->next->prev = curr->prev;
    free(curr);
    return(_TRUE);

}





/**
 * _prependSNode- Add a node to the beginning stack
 * @head: pointer to stack
 * @num: Number to be stored in the new node
 * Return: Pointer to the newly added node or NULL on failure
 */
stackk_t *_prependSNode(stackk_t **head, const int num)
{
    stackk_t *top;


    if(!head)
        return (NULL);
    top = createSNode(num);
    if(top)
    {
    /* attach at start and point to the rest*/
    top->next = *head;

    if((*head))
    /*point the previous 1st node to the new 1st node*/
        (*head)->prev = top;
    *head = top;

    return (top);
    }
    return (NULL);
    

}





/**
 * _printStack - prints data value in all stack nodes
 * @head: pointer to stack
 * Return: stack size or node length
 */
size_t _printStack(const stackk_t *head)
{
    size_t stack ;

    if(!head)
        return (0);

    for(stack = 0; head; head = head->next, stack++)
        printf("%d\n", head->n);

    return(stack);
}




/**
 * _getSNodeAt - Get the  node at a given position
 * @head: Pointer to the head of the stack
 * @pos: position of the node
 * Return: node at position or NULL
 */
stackk_t *_getSNodeAt(stackk_t *head, unsigned int pos)
{
    unsigned int index = 0;

    stackk_t * curr = head;

    if(!curr)
        return (NULL);
    
   for (;curr && index < pos; curr = curr->next, index++)
    ;
    return (curr? curr : NULL);
    
}
