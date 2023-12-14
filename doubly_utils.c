#include "monty.h"

/**
 *add_dnode_end - add note at the end of doubly linked list
 *@head: first position of linked list
 *@node: data to store
 *Return: doubly linked list
 */
stack_t *add_dnode_end(stack_t **head, const int node)
{
	stack_t *tmp, *aux;

	if (head == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	tmp->n = node;

	if (*head == NULL)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}
	aux = *head;
	while (aux->next)
		aux = aux->next;
	tmp->next = aux->next;
	tmp->prev = aux;
	aux->next = tmp;
	return (aux->next);
}

/**
 *add_dnode - add note at the begining of doubly linked list
 *@head: first position of linked list
 *@node: data to store
 *Return: doubly linked list
 */
stack_t *add_dnode(stack_t **head, const int node)
{
	stack_t *tmp;

	if (head == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	tmp->n = node;

	if (*head == NULL)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}
	(*head)->prev = tmp;
	tmp->next = (*head);
	tmp->prev = NULL;
	*head = tmp;
	return (*head);
}

/**
 * free_dlist - frees the doubly linked list
 * @head: head of the list
 */
void free_dlist(stack_t *head)
{
	stack_t *temp;

	while ((temp = head) != NULL)
	{
		head = head->next;
		free(temp);
	}
}
