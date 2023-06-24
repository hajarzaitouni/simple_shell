#include "main.h"

/**
*print_env - print the current environement
*/
void print_env(void)
{
	char **env = environ;
	int i = 0;
	size_t length;

	while (env[i] != NULL)
	{
		length = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], length);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

