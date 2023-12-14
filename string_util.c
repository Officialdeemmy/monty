#include "monty.h"

/**
 * _strcmp_ - Function that compares two strings.
 * @str1: type str compared
 * @str2: type str compared
 * Return: 0 if s1 and s2 are equals
 */
int _strcmp_(char *str1, char *str2)
{
	int n;

	for (n = 0; str1[n] == str2[n] && str1[n]; n++)
		;
	if (str1[n] > str2[n])
		return (1);
	if (str1[n] < str2[n])
		return (-1);
	return (0);
}

/**
 * _sch_ - search if a char is inside a string
 * @str: string to review
 * @c: char to find
 * Return: 1 if success 0 if not
 */
int _sch_(char *str, char c)
{
	int count = 0;

	while (str[count] != '\0')
	{
		if (str[count] == c)
		{
			break;
		}
		count++;
	}
	if (str[count] == c)
		return (1);
	else
		return (0);
}

/**
 * _strtoky_ - function that cut a string into tokens depending of the delimit
 * @s: string to cut in parts
 * @c: delimiters
 * Return: first partition
 */
char *_strtoky_(char *s, char *c)
{
	static char *ult;
	int i = 0, j = 0;

	if (!s)
		s = ult;
	while (s[i] != '\0')
	{
		if (_sch_(c, s[i]) == 0 && s[i + 1] == '\0')
		{
			ult = s + i + 1;
			*ult = '\0';
			s = s + j;
			return (s);
		}
		else if (_sch_(c, s[i]) == 0 && _sch_(c, s[i + 1]) == 0)
			i++;
		else if (_sch_(c, s[i]) == 0 && _sch_(c, s[i + 1]) == 1)
		{
			ult = s + i + 1;
			*ult = '\0';
			ult++;
			s = s + j;
			return (s);
		}
		else if (_sch_(c, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
