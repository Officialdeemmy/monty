#include "monty.h"

/**
 * _calloc - concatenate two strings
 * @n: number of elements
 * @size: type of elements
 */
void *_calloc(unsigned int n, unsigned int size)
{
	void *a = NULL;
	unsigned int i;

	if (n == 0 || size == 0)
	{
		return (NULL);
	}
	a = malloc(n * size);
	if (a == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < (n * size); i++)
	{
		*((char *)(a) + i) = 0;
	}
	return (a);
}

/**
 * _realloc - change the size and copy the content
 * @ptr: malloc pointer to reallocate
 * @old_size: old number of bytes
 * @new_size: new number of Bytes
 * Return: realloc
 */
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size)
{
	char *a = NULL;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		a = malloc(new_size);
		if (!a)
			return (NULL);
		return (a);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		a = malloc(new_size);
		if (!a)
			return (NULL);
		for (i = 0; i < old_size; i++)
			a[i] = *((char *)ptr + i);
		free(ptr);
	}
	else
	{
		a = malloc(new_size);
		if (!a)
			return (NULL);
		for (i = 0; i < new_size; i++)
			a[i] = *((char *)ptr + i);
		free(ptr);
	}
	return (a);
}
