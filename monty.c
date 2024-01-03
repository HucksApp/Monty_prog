#include "monty.h"

/* Global variable obj of monty_t type */
 monty_t obj = INIT_OBJ;




/**
 * monty - read and execute monty code
 * @argv: argument vector from main
 */

void monty(char** argv)
{
    size_t len = 0;
    int read_bytes = 0;
    char ** tokens = NULL ;

    void (*operatn_instructn)(stackk_t **, unsigned int);
    
    (void) read_bytes;


    obj._file = fopen(argv[1], "r");
    if(file_err(obj._file, argv[1]))
        exit(EXIT_FAILURE);
    
    while(!feof(obj._file))
    {
        obj.line_num +=1;
        read_bytes = getline(&(obj._line), &len, obj._file);
            tokens = _parser(obj._line);
            if(tokens)
            {
                obj._tokens = tokens;
                operatn_instructn = find_opcode(obj._tokens);
               
                if(!operatn_instructn)
                    operatn_err();
                
                operatn_instructn(&(obj._stack), obj.line_num);
                garbageCollector(_FALSE); 
            }
    }
    garbageCollector(_TRUE);
}



/**
 * main - main function or start of execution
 * related to given token.
 * @argv: arguments vector
 * @argc: arguments count
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int main(int argc, char **argv)
{

    if (args_err(argc))
    {
        dprintf(STDERR_FILENO, USAGE);
	exit(EXIT_FAILURE);
    }
    monty(argv);
    return (EXIT_SUCCESS);
}



