#include "main.h"

/**
 * main - Entry point
 * Description: run a simple shell
 * @ac: number of arguments
 * @av: a pointer to array
 * Return: 0 (Success)
 */
int main(__attribute((unused)) int ac, char *av[])
{
	char *command = NULL, **argv;

	signal(SIGINT, signal_handler);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDIN_FILENO, "$ ", 2);
		command = readCommand();
		if (command == NULL)
			break;

		if (command[0] == '\0')
			continue;
		argv = splitCommand(command, " \n");
		if (argv == NULL)
		{
			perror("Error splitting command");
			free(command);
			free(argv);
			continue;
		}
		if (_strcmp(argv[0], "exit") == 0)
		{
			free(argv);
			free(command);
			break;
		}
		if (execCommand(argv, command, av) != 0)
			perror(av[0]);

		free(argv);
		free(command);

	}
	return (0);
}
