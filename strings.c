#include "main.h"

/**
*_strlen - returns the length of a string
*
*@s: string input
*Return: the length of string
*/

int _strlen(const char *s)
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

char *_strdup(const char *s)
{
	char *str;
	int i = 0, length;

	length = _strlen(s);

	if (s == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);

	while (i <= length)
	{
		str[i] = s[i];
		i++;
	}

	return (str);
}

/**
 * _strcpy - copy the string from src to dest
 *
 * @dest: a pointer to string
 * @src: a pointer to the string src from where we copy
 * Return: a pointer to dest
 */

char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcat - concatenates two strings
 *
 * @dest: a pointer to string
 * @src: a pointer to string
 * Return: a pointer to the resulting string dest
 */

char *_strcat(char *dest, const char *src)
{
	char *str = dest;

	while (*str != '\0')
		str++;
	while (*src != '\0')
	{
		*str = *src;
		str++;
		src++;
	}
	*str = '\0';

	return (dest);
}
