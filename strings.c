#include "main.h"

/**
*_strlen - returns the length of a string
*
*@s: string input
*Return: the length of tring
*/

int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}

	return (count);
}

/**
*_strdup - duplicate the string given as parameter
*
*@s: a pointer to string
*Return: returns a pointer to the new string
*/

char *_strdup(char *s)
{
	char *str;
	int i = 0;

	if (s == 0)
		return (NULL);
	str = malloc(sizeof(char) * (_strlen(s) + 1));
	if (str == 0)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}
