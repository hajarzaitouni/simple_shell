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
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("Error forking");
		return (-1);
	}

	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("./hsh");
			exit(1);
		}
	}
	else
	{
		if (wait(&status) == -1)
			perror("Error waiting");
	}

	return (0);
}
