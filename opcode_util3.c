#include "monty.h"

/**
 * _div_ - divides the second element by the top element of the stack
 * @head: head of the linked list
 * @c_line: line number
 */
void _div_(stack_t **head, unsigned int c_line)
{
	int n = 0;
	stack_t *aux = NULL;

	aux = *head;

	for (; aux != NULL; aux = aux->next, n++)
		;

	if (n < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", c_line);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", c_line);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*head)->next;
	aux->n /= (*head)->n;
	_pop_(head, c_line);
}

/**
 * _mul_ - multiplies the top element to the second top element of the stack
 * @head: head of the linked list
 * @c_line: line number
 */
void _mul_(stack_t **head, unsigned int c_line)
{
	int n = 0;
	stack_t *aux = NULL;

	aux = *head;

	for (; aux != NULL; aux = aux->next, n++)
		;

	if (n < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", c_line);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*head)->next;
	aux->n *= (*head)->n;
	_pop_(head, c_line);
}

/**
 * _mod_ - computes the rest of the division of second element by top element of the stack
 * @head: the head of the linked list
 * @c_line: the line number
 */
void _mod_(stack_t **head, unsigned int c_line)
{
	int n = 0;
	stack_t *aux = NULL;

	aux = *head;

	for (; aux != NULL; aux = aux->next, n++)
		;

	if (n < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", c_line);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	if ((*head)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", c_line);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = (*head)->next;
	aux->n %= (*head)->n;
	_pop_(head, c_line);
}
/**
 * _pchar_ - print the char value of the first element
 * @head: head of the linked list
 * @c_line: line number
 */
void _pchar_(stack_t **head, unsigned int c_line)
{
	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", c_line);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", c_line);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}

/**
 * _pstr_ - prints the string of the stack
 * @head: head of the linked list
 * @c_line: line number
 */
void _pstr_(stack_t **head, unsigned int c_line)
{
	stack_t *aux;
	(void)c_line;

	aux = *head;

	while (aux && aux->n > 0 && aux->n < 128)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}

	printf("\n");
}
