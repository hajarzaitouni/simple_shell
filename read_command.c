#include "main.h"

/**
 * readCommand - read line from the standard input (command)
 * Return: a pointer to string
 */

char *readCommand()
{
	char *command = NULL;
	size_t length = 0;
	ssize_t read_chars;

	read_chars = getline(&command, &length, stdin);

	if (read_chars == -1)
	{
		free(command);
		return (NULL);
	}

	if (command[read_chars - 1] == '\n')
		command[read_chars -1] = '\0';

	return (command);
}
