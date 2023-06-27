#include "main.h"

/**
 * execCommand - loads up the calling program (command)
 *
 * @argv: a pointer to string
 * Return: 0 (Success)
 */

int execCommand(char **argv)
{
	pid_t pid;
	char *command = NULL, *full_cmd = NULL;
	int status;

	if (argv == NULL)
		return (-1);

	command = argv[0];
	full_cmd = get_path(command);
	if (full_cmd == NULL)
		return (-1);

	pid = fork();

	if (pid == -1)
	{
		perror("Error forking");
		free(full_cmd);
		return (-1);
	}

	if (pid == 0)
	{
		if (execve(full_cmd, argv, NULL) == -1)
		{
			perror("Error execution");
			free(full_cmd);
			free(command);
			exit(1);
		}
	}
	else
		wait(&status);

	return (0);
}

/**
 * signal_handler - handle ctrl + C like in sh shell
 * @signum: input integer
 */

void signal_handler(int signum)
{
	if (signum == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}
