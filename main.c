#include "main.h"

/**
 * main - Entry point
 * Description: run a simple shell
 * Return: 0 (Success)
 */

int main(void)
{
	char *command = NULL;

	while (1)
	{
		write(1, "$ ", 2);

		command = readCommand();
		if (command == NULL)
			break;

		if (execCommand(command) != 0)
			perror("Error");

		free(command);
	}

	return (0);
}
