#include "monty.h"
/**
 * _queue - prints the top
 * @head: stack head
 * @counter: line_number
*/
void _queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	cont.lifi = 1;
}

/**
 * addqueue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
*/
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}

/**
 * _add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
*/
void _add(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(cont.file);
		free(cont.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}

/**
  *_nop- nothing
  *@head: stack head
  *@counter: line_number
  */
void _nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}
