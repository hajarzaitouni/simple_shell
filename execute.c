#include "main.h"

/**
 * execCommand - loads up the calling program (command)
 *
  *@command: string input
 * @av: a pointer to array of strings
 * @argv: a pointer to array of strings
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
		if ((_strncmp(*argv, "./", 2)) && (_strncmp(*argv, "/", 1)))
			get_path(argv);

		if (execve(*argv, argv, env) == -1)
		{
			perror(av[0]);
			free(command);
			free(argv);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
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
