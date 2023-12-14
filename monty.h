#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

void *_calloc_(unsigned int n, unsigned int size);
void *_realloc_(void *ptr, unsigned int old_byte, unsigned int new_byte);
stack_t *add_dnode_end(stack_t **head, const int node);
stack_t *add_dnode(stack_t **head, const int node);
void free_dlist(stack_t *head);void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);
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
void _rotl_(stack_t **doubly, unsigned int c_line);
void _rotr_(stack_t **doubly, unsigned int c_line);
int _strcmp_(char *str1, char *str2);
int _sch_(char *str, char c);
char *_strtoky_(char *s, char *c);

#endif /*MONTY_H*/
