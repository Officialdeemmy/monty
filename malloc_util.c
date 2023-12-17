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
 * @old_byte: old number of bytes
 * @new_byte: new number of Bytes
 */
void *_realloc(void *ptr, unsigned int old_byte, unsigned int new_byte)
{
	char *a = NULL;
	unsigned int i;

	if (new_byte == old_byte)
		return (ptr);
	if (ptr == NULL)
	{
		a = malloc(new_byte);
		if (!a)
			return (NULL);
		return (a);
	}
	if (new_byte == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_byte > old_byte)
	{
		a = malloc(new_byte);
		if (!a)
			return (NULL);
		for (i = 0; i < old_byte; i++)
			a[i] = *((char *)ptr + i);
		free(ptr);
	}
	else
	{
		a = malloc(new_byte);
		if (!a)
			return (NULL);
		for (i = 0; i < new_byte; i++)
			a[i] = *((char *)ptr + i);
		free(ptr);
	}
	return (a);
}
