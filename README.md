# monty👾
**C - Stacks, Queues - LIFO, FIFO**

## Description
This ALX School project is a custom ByteCode interpreter, coded in C.


### Table of Contents 🫚

File                                       |             Description
-------------------------------------------|-----------------------------------
operatnCode<A - C>.c                       | Monty operation handlers
sNodeOps<A - B>.c                          | Double linked list nodes operation handler
parser                                     | File text lines parser functions
memory.c                                   | Memory helper functions
errorA.c                                   | All mounty error handlers
find.c                                     | Monty command search handler
monty.c                                    | monty program entry point
macros.h                                   | All predefined constant Macros
strUtilities.c                             | string manipulation helper functions
monty.h                                    | monty header file


## Compilation
`gcc -Wall -Werror -Wextra -pedantic *.c -o monty`
### Usage

`$ ./monty byte_file.m`

The program reads from the file "byte_file.m" that contains one instruction per line. It then calls the right function to modify a stack according to the instruction. It prints custom error messages if the instruction is wrong


### Monty Bytecode File 📄


Commands                                   |             Description and Usage
-------------------------------------------|---------------------------------------------------
\#                                         | Monty comments: anything after the symbol is not processed -> `# this is push`
push                                      | Push a value to the stack -> `push <value> `
pall                                       | Print all element in stack -> `pall`
pint                                       | Print element at the top of the stack -> `pint`
pop                                        | Remove element at the top of the stack -> `pop`
nop                                        | Does Nothing -> `pop`
add                                        | Add the top two elements of the stack -> `add`
sub                                        | Subtract the top element of the stack from the second top element of the stack -> `sub`
div                                        | Divide the second top element of the stack by the top element of the stack -> `div`
mul                                        | Multiply the top two elements of the stack -> `mul`
mod                                        | computes the rest of the division of the second top element of the stack by the top element of the stack -> `mod`
pchar                                      | prints the char at the top of the stack, followed by a new line  -> `pchar`
pstr                                       | prints the string starting at the top of the stack, followed by a new line -> `pstr`
rotl                                       | rotates the stack to the top -> `rotl`
rotr                                       | rotates the stack to the bottom -> `rotr`
stack                                      | sets the format of the data to a stack (LIFO). This is the default behavior of the program -> `stack`
queue                                      | sets the format of the data to a queue (FIFO) -> `stack`


### Authors 🖋
Abiodun Aremu ~ HucksApp@gmail.com :

