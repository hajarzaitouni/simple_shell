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
		if (command[0] == '\0')
			continue;
		argv = splitCommand(command, " \n");

		if (argv == NULL)
		{
			perror("Error splitting command");
			free(command);
			continue;
		}
		if (_strcmp(argv[0], "exit") == 0)
		{
			free(argv);
			free(command);
			break;
		}
		else if (_strcmp(argv[0], "env") == 0)
		{
			print_env();
		}
		if (execCommand(argv) != 0)
		{
			perror("Error");
		}

		free(argv);
		free(command);
	}
		return (0);
}
