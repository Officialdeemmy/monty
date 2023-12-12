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
void free_dlist(stack_t *head);

#endif /*MONTY_H*/
