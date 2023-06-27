#include "main.h"

/**
 * execCommand - loads up the calling program (command)
 *
 *@command: string input
 *@av: a pointer array of strings
 * @argv: a pointer to string
 * Return: 0 (Success)
 */

int execCommand(char **argv, char *command, char **av)
{
	pid_t pid;
	int status;
	char **env = environ;

	if (argv == NULL)
		return (-1);

	pid = fork();

	if (pid == -1)
	{
		perror("Error forking");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*argv, "./", 2) != 0 && _strncmp(*argv, "/", 1) != 0)
	{
		path_cmd(argv);
	}

		if (execve(*argv, argv, env) == -1)
		{
			perror(av[0]);
			free(command);
			free(argv);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);

	return (0);
}
/**
*signal_handler - handle ctrl + c like in sh shell
*@signum: input integer
*/
void signal_handler(int signum)
{
	if (signum == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}
