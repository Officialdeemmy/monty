#include "monty.h"

/**
 * _queue_ - sets the format of the data to a queue (FIFO)
 * @head: head of the linked list
 * @c_line: line number
 */
void _queue_(stack_t **head, unsigned int c_line)
{
	(void)head;
	(void)c_line;

	vglo.lifo = 0;
}

/**
 * _stack_ - sets the format fo the data to a stack (LIFO)
 * @head: head of the linked list
 * @c_line: line number
 */
void _stack_(stack_t **head, unsigned int c_line)
{
	(void)head;
	(void)c_line;

	vglo.lifo = 1;
}

/**
 * _add_ - adds the top two elements of the stack
 * @head: head of the linked list
 * @c_line: line number
 */
void _add_(stack_t **head, unsigned int c_line)
{
	int n = 0;
	stack_t *aux = NULL;

	aux = *head;

	for (; aux != NULL; aux = aux->next, n++)
		;

	if (n < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", c_line);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*head)->next;
	aux->n += (*head)->n;
	_pop_(head, c_line);
}

/**
 * _nop_ - it doesn't do anythinhg
 * @head: head of the linked list
 * @c_line: line number
 */
void _nop_(stack_t **head, unsigned int c_line)
{
	(void)head;
	(void)c_line;
}

/**
 * _sub_ - subtracts the top element to the second top element of the stack
 * @head: head of the linked list
 * @c_line: line number
 */
void _sub_(stack_t **head, unsigned int c_line)
{
	int n = 0;
	stack_t *aux = NULL;

	aux = *head;

	for (; aux != NULL; aux = aux->next, n++)
		;

	if (n < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", c_line);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*head)->next;
	aux->n -= (*head)->n;
	_pop_(head, c_line);
}
