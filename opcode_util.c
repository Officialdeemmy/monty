#include "monty.h"

/**
 * _push_ - push an element to the stack
 * @head: the head of the linked list
 * @c_line: the line number
 */
void _push_(stack_t **head, unsigned int c_line)
{
	int n, i;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: ", c_line);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (i = 0; vglo.arg[i] != '\0'; i++)
	{
		if (!isdigit(vglo.arg[i]) && vglo.arg[i] != '-')
		{
			dprintf(2, "L%u: ", c_line);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnode(head, n);
	else
		add_dnode_end(head, n);
}

/**
 * _pall_ - prints all the values on the stack
 * @head: the head of the linked list
 * @c_line: the line numbers
 */
void _pall_(stack_t **head, unsigned int c_line)
{
	stack_t *aux;
	(void)c_line;

	aux = *head;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * _pint_ - prints the value at the top of the stack
 * @head: the head of the linked list
 * @c_line: the line number
 */
void _pint_(stack_t **head, unsigned int c_line)
{
	(void)c_line;

	if (*head == NULL)
	{
		dprintf(2, "L%u: ", c_line);
		dprintf(2, "can't pint, stack empty\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

/**
 * _pop_ - removes the top element of the stack
 * @head: the head of the linked list
 * @c_line: the line number
 */
void _pop_(stack_t **head, unsigned int c_line)
{
	stack_t *aux;

	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", c_line);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = *head;
	*head = (*head)->next;
	free(aux);
}

/**
 * _swap_ - swaps the top two elements of the stack
 * @head: the head of the linked list
 * @c_line: the line number
 */
void _swap_(stack_t **head, unsigned int c_line)
{
	int n = 0;
	stack_t *aux = NULL;

	aux = *head;

	for (; aux != NULL; aux = aux->next, n++)
		;

	if (n < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", c_line);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = *head;
	*head = (*head)->next;
	aux->next = (*head)->next;
	aux->prev = *head;
	(*head)->next = aux;
	(*head)->prev = NULL;
}
