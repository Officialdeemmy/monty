#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - global structure to use in the functions
 * @lifo: is stack or queue
 * @cont: current line
 * @arg: second parameter inside the current line
 * @head: doubly linked list
 * @fd: file descriptor
 * @buffer: input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global_s
{
	int lifo;
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

extern global_t vglo;

void *_calloc_(unsigned int n, unsigned int size);
void *_realloc_(void *ptr, unsigned int old_byte, unsigned int new_byte);
stack_t *add_dnode_end(stack_t **head, const int node);
stack_t *add_dnode(stack_t **head, const int node);
void free_dlist(stack_t *head);
void (*get_opcode(char *op))(stack_t **stack, unsigned int line_number);
void _push_(stack_t **head, unsigned int c_line);
void _pall_(stack_t **head, unsigned int c_line);
void _pint_(stack_t **head, unsigned int c_line);
void _pop_(stack_t **head, unsigned int c_line);
void _swap_(stack_t **head, unsigned int c_line);
void _queue_(stack_t **head, unsigned int c_line);
void _stack_(stack_t **head, unsigned int c_line);
void _add_(stack_t **head, unsigned int c_line);
void _nop_(stack_t **head, unsigned int c_line);
void _sub_(stack_t **head, unsigned int c_line);
void _rotl_(stack_t **head, unsigned int c_line);
void _rotr_(stack_t **head, unsigned int c_line);
int _strcmp_(char *str1, char *str2);
int _sch_(char *str, char c);
char *_strtoky_(char *s, char *c);
void free_vglo(void);

#endif /*MONTY_H*/
