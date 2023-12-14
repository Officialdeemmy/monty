#include "monty.h"

/**
 * _rotl_ - rotates first element to the bottom and the second to the top
 * @head: head of the linked list
 * @c_line: line number
 */
void _rotl_(stack_t **head, unsigned int c_line)
{
	stack_t *aux1 = NULL;
	stack_t *aux2 = NULL;
	(void)c_line;

	if (*head == NULL)
		return;

	if ((*head)->next == NULL)
		return;

	aux1 = (*head)->next;
	aux2 = *head;

	for (; aux2->next != NULL; aux2 = aux2->next)
		;

	aux1->prev = NULL;
	aux2->next = *head;
	(*head)->next = NULL;
	(*head)->prev = aux2;
	*head = aux1;
}

/**
 * _rotr_ - reverse the stack
 * @head: head of the linked list
 * @c_line: line number
 */
void _rotr_(stack_t **head, unsigned int c_line)
{
	stack_t *aux = NULL;
	(void)c_line;

	if (*head == NULL)
		return;

	if ((*head)->next == NULL)
		return;

	aux = *head;

	for (; aux->next != NULL; aux = aux->next)
		;

	aux->prev->next = NULL;
	aux->next = *head;
	aux->prev = NULL;
	(*head)->prev = aux;
	*head = aux;
}
