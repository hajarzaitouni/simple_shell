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
	char *token = NULL;
	char **arr_tokens;
	size_t i, j, count = 0;

	if (command == NULL)
		return (NULL);

	count = count_tokens(command, delimiter);

	arr_tokens = malloc(sizeof(char *) * (count + 1));

	if (arr_tokens == NULL)
	{
		free(command);
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
			free(command);
			return (NULL);
		}
		token = strtok(NULL, delimiter);
		i++;
	}
	arr_tokens[i] = NULL;
	return (arr_tokens);
}

/**
 * count_tokens - count the tokens in the input command
 *
 * @command: the input to parse
 * @delimiter: separator string
 * Return: the number of tokens
 */

size_t count_tokens(char *command, const char *delimiter)
{
	char *cp_command;
	char *token;
	size_t count = 0;

	if (command == NULL)
		return (0);
	cp_command = _strdup(command);
	if (cp_command == NULL)
		return (0);
	token = strtok(cp_command, delimiter);
	while (token)
	{
		count++;
		token = strtok(NULL, delimiter);
	}

	free(cp_command);
	return (count);
}
