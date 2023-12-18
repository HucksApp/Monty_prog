#include "monty.h"

/**
 * _push - adds a node to the beginning of a list
 * @stack: head node of our list
 * @line_number: the current line number
 */
void _push(stackk_t **stack, UNUSED unsigned int line_num)
{

	stackk_t *new = NULL;
    int num = 0;

    if(!obj._tokens[1])
        instruction_err(PUSH_FAIL);

   
    num = atoi(obj._tokens[1]);

    if(obj.stk_or_que == stack_flg)
        new = _prependSNode(stack, num);
    else if (obj.stk_or_que == queue_flg)
        new = _appendSNode(stack, num);

    if (!new)
        memory_err();
}


/**
 * _pall - print all the stack
 * @stack: head node of  stack
 * @line_number: the current line number
 */


void _pall(stackk_t **stack, UNUSED unsigned int line_num)
{
    if(*stack)
        _printStack(*stack);
}

/**
 * _pint - print the int data member of the stack
 * @stack: head node of stack
 * @line_number: the current line number
 */

void _pint(stackk_t **stack, UNUSED unsigned int line_num)
{
    stackk_t *head = *stack;
    if(!head)
        instruction_err(PINT_FAIL);
    printf("%d\n", head->n);
}

/**
 * _pop - remove a node from the start
 * @stack: head node of stack
 * @line_number: the current line number
 */

void _pop(stackk_t **stack, UNUSED unsigned int line_num)
{
    stackk_t *head = *stack;
    if(!head)
        instruction_err(POP_FAIL);
   _deleteSNodeAt(stack, 0);
}

/**
 * _swap - swap  node
 * @stack: head node of stack
 * @line_number: the current line number
 */
void _swap(stackk_t **stack, UNUSED unsigned int line_num)
{
    int num;
    stackk_t *tmp = *stack, *node = NULL;

    if(sNodesLen(*stack) < 2)
        instruction_err(SWAP_FAIL);

    tmp = _getSNodeAt(*stack, 0);
    num = tmp->n;
    _deleteSNodeAt(stack, 0);
    node = _insertSNodeAt(stack, 1, num);
    if (!node)
        memory_err();
}

