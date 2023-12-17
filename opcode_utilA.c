#include "monty.h"

/**
 * _push - add node to the stack
 * @head: stack head
 * @counter: line_number
 */
void _push(stack_t **head, unsigned int counter)
{
	int n, j = 0, flag = 0;

	if (cont.arg)
	{
		if (cont.arg[0] == '-')
			j++;
		for (; cont.arg[j] != '\0'; j++)
		{
			if (cont.arg[j] > 57 || cont.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(cont.file);
			free(cont.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(cont.file);
		free(cont.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(cont.arg);
	if (cont.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
