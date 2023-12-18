#include "monty.h"


/**
 * args_err - arguments error.
 * @argc: argument count from main
 * Return: _TRUE (1) or _FALSE (0)
 */
int args_err(int argc)
{
   return((argc != 2)? _TRUE: _FALSE);
}




/**
 * file_err - file error
 * @file_ptr: file pointer
 * @arg: argument
 * Return: _TRUE (1) or _FALSE (0)
 */
int file_err(FILE *file_ptr, char *arg)
{
    if(!file_ptr)
    {
        dprintf(STDERR_FILENO, FILE_ERROR, arg);
        return(_TRUE);
    }
    return (_FALSE);
}




/**
 * operation_err - operation error
 * Return: Void
 */
void operatn_err(void)
{
    dprintf(STDERR_FILENO, UNKNOWN, obj.line_num, obj._tokens[0]);
    garbageCollector(_TRUE);
    exit(EXIT_FAILURE);
}


/**
 * instruction_err - instruction error
 * @msg: error message
 */

void instruction_err(char * msg)
{
    dprintf(STDERR_FILENO, msg, obj.line_num);
	garbageCollector(_TRUE);
	exit(EXIT_FAILURE);
}


/**
 * memory_err - memory allocation error
 * Return: Void
 */
void memory_err(void)
{
    dprintf(STDERR_FILENO, MALLOC_FAIL );
	garbageCollector(_TRUE);
	exit(EXIT_FAILURE);
}
