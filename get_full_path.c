#include "main.h"

/**
 * get_path - get the executable command from $PATH
 *
 * @argv: double pointer (tokenized command)
 * Return: pointer to the full_command
 */

int get_path(char **argv)
{
	char *path, *token;
	char *path_command;
	struct stat buff;

	path = _getenv("PATH");
	if (path == NULL)
		return (1);
	token = strtok(path, ":");
	while (token)
	{
		path_command = creat_path(token, *argv);
		if (path_command == NULL)
			return (1);

		if (stat(path_command, &buff) == 0)
		{
			*argv = _strdup(path_command);
			free(path_command);
			free(path);
			return (0);
		}
		free(path_command);
		token = strtok(NULL, ":");
	}

	free(path);

	return (1);
}

/**
 * creat_path - build the full path command
 *
 * @dir: a pointer to the directory containing the command
 * @command: a pointer to the executable command
 * Return: a pointer to the resulting full path command
 */

char *creat_path(char *dir, char *command)
{
	char *full_cmd;
	size_t len1 = _strlen(dir);
	size_t len2 = _strlen(command);

	full_cmd = malloc(len1 + len2 + 2);
	if (full_cmd == NULL)
	{
		return (NULL);
	}

	_strcpy(full_cmd, dir);
	_strcat(full_cmd, "/");
	_strcat(full_cmd, command);

	return (full_cmd);
}


/**
 * _getenv - get the environnement variable
 *
 * @name: a pointer to the name of variable
 * Return: a pointer to string that contains the value of variable
 */
char *_getenv(const char *name)
{
	char *value, *delim;
	char **env = environ;
	int i, n_len = 0, v_len = 0;

	if (name == NULL)
		return (NULL);

	n_len = _strlen(name);
	for (i = 0; env[i] != NULL; i++)
	{
		if (_strncmp(name, env[i], n_len) == 0)
		{
			delim = _strchr(env[i], '=');
			if (delim)
			{
				v_len = _strlen(delim + 1);
				value = malloc(sizeof(char) * (v_len + 1));
				if (value == NULL)
				{
					return (NULL);
				}
				_strcpy(value, delim + 1);
				return (value);
			}
		}
	}
	return (NULL);
}
