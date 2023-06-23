#include "main.h"

/**
 * get_path - get the executable command from $PATH
 *
 * @command: string to input
 * Return: pointer to the full_command
 */

char *get_path(char *command)
{
	char *path, *cp_path, *token;
	char *path_command;
	struct stat buff;

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);
	cp_path = _strdup(path);
	if (cp_path == NULL)
		return (NULL);
	token = strtok(cp_path, ":");

	while (token)
	{
		path_command = creat_path(token, command);
		if (path_command == NULL)
		{
			free(cp_path);
			return (NULL);
		}

		if (stat(path_command, &buff) == 0)
		{
			free(cp_path);
			return (path_command);
		}
		free(path_command);
		token = strtok(NULL, ":");
	}

	free(cp_path);

	if (stat(command, &buff) == 0)
	{
		return (command);
	}
	return (NULL);
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

	full_cmd = malloc(_strlen(dir) + _strlen(command) + 2);
	if (full_cmd == NULL)
		return (NULL);

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
		if (strncmp(name, env[i], n_len) == 0)
		{
			delim = strchr(env[i], '=');
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
