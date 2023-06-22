#include "main.h"

/**
* splitCommand - split line of input into words
*
* @command: the line of input to parse
* @delimiter: a pointer to string (separator string)
* Return: a pointer to array
*/
char **splitCommand(char *command, const char *delimiter)
{
	char *cp_command, *token = NULL;
	char **arr_tokens;
	size_t i, j, count = 0;

	if (command == NULL)
		return (NULL);

	cp_command = _strdup(command);
	token = strtok(cp_command, delimiter);
	while (token)
	{
		count++;
		token = strtok(NULL, delimiter);
	}

	arr_tokens = malloc(sizeof(char *) * (count + 1));

	if (arr_tokens == NULL)
	{
		free(cp_command);
		return (NULL);
	}

	token = strtok(command, delimiter);
	i = 0;

	while (token)
	{
		arr_tokens[i] = token;
		if (arr_tokens[i] == NULL)
		{
			/*allocation failed, free allocated array*/
			for (j = 0; j < i; j++)
				free(arr_tokens[j]);
			free(arr_tokens);
			free(cp_command);
			return (NULL);
		}
		token = strtok(NULL, delimiter);
		i++;
	}
	arr_tokens[i] = NULL;
	free(cp_command);
	return (arr_tokens);
}
