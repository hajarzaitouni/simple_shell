#include "main.h"

/**
*_strcmp - compares two strings
*
*@s1: a pointer to the first string
*@s2: a pointer to the second string
*Return: 0 if there is match, otherwise != 0
*/
int _strcmp(const char *s1, const char *s2)
{
	int i = 0, comp = 0;

	while (s1[i] == s2[i])
	{

		if (s1[i] == '\0' && s2[i] == '\0')
			break;
		i++;
	}
	comp = s1[i] - s2[i];

	return (comp);
}

/**
*_strncmp - compares the first n bytes of both strings
*
*@s1: a pointer to the first string
*@s2: a pointer to the second string
*@n: number of bytes to compare
*Return: 0 if there is match, otherwise != 0
*/

int _strncmp(const char  *s1, const char *s2, size_t n)
{
	size_t i = 0;
	int comp = 0;

	while (i < n && s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			break;
		i++;
	}
	if (i == n)
		return (0);

	{
		comp = s1[i] - s2[i];
		return (comp);
	}
}
