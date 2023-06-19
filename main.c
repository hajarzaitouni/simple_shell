#include "main.h"

/**
 * main - Entry point
 * Description: run a simple shell
 * Return: 0 (Success)
 */

int main(void)
{
	char *command = NULL;
	char **argv;

	while (1)
	{
		write(STDIN_FILENO, "$ ", 2);
		command = readCommand();
		if (command == NULL)
	{
			break;
	}
		argv = splitCommand(command, "\n");

		if (argv == NULL)
		{
			perror("Error splitting command");
			free(command);
		}
		if (execCommand(argv != 0)
		{
		perror("Error");
		}

		free(argv);
		free(command);
	}
	return (0);
}
