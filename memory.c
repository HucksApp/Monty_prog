#include "monty.h"

 



/**
 * garbageCollector - release memory out of use.
 * @total: total memory release, _TRUE or _FALSE
 */
void garbageCollector(int total)
{
    if(obj._line)
    {
        free(obj._line);
        obj._line = NULL;
    }
   
    if (obj._tokens)
    {
        free_arr_strs(obj._tokens);
        obj._tokens = NULL;
    }
    if (total)
    {
        
        if(obj._stack)
        {
            freeSNode(obj._stack);
            obj._stack = NULL;

        }
        
        if (obj._file)
        {
            fclose(obj._file);
            obj._file = NULL;
        }
    }

}


/**
 * free_arr_strs - free array of strings
 * @arr: strings array (array of arrays)
 */
void free_arr_strs(char **arr)
{
    int index;

    if(!arr)
        return;

    for (index = 0; arr[index]; index++)
    {
        if(arr[index])
            free(arr[index]);
    }
    free(arr);
}



/**
 * freeSNode - free the stack_t (monty) node
 * @head: head of stack_t
 */
void freeSNode(stackk_t *head)
{
    stackk_t * curr = NULL;


    while(head)
    {
        curr = head->next;
        free(head);
        head = curr;
    }
}
