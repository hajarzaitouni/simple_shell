#include "main.h"

/**
 * execCommand - loads up the calling program (command)
 *
 * @command: a pointer to string
 * Return: 0 (Success)
 */

int execCommand(char *command)
{
	char *argv[] = {NULL, NULL};
	pid_t pid;
	int status;

	argv[0] = command;

	pid = fork();

	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (execve(command, argv, NULL) == -1)
		{
			perror("./hsh");
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}

	return (0);
}
