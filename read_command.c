#include "main.h"

/**
 * readCommand - read line from the standard input (command)
 *	(without using getline)
 * Return: a pointer to string
 */

char *readCommand()
{
	char *buff;
	char c;
	size_t length = 0;
	ssize_t read_chars;

	buff = malloc(BUFF_SIZE);
	if (buff == NULL)
		return (NULL);
	while (1)
	{
		read_chars = read(STDIN_FILENO, &c, 1);
		if (read_chars == 0 || read_chars == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[length] = c;

		if (length == BUFF_SIZE - 1 || c == '\n')
		{
			buff[length] = '\0';
			return (buff);
		}

		if (length + 1 >= BUFF_SIZE)
		{
			buff = expand_buff(buff, BUFF_SIZE + length);
			if (buff == NULL)
				return (NULL);
		}
		length++;
	}
	buff[length] = '\0';

	return (buff);
}

/**
 * expand_buff - expand the buffer when it needs to
 *
 * @buffer: a pointer to the buffer we want to realloc
 * @length: the new buffer_size
 * Return: a pointer to newly buffer
 */

char *expand_buff(char *buffer, size_t length)
{
	char *newBuff;

	newBuff = realloc(buffer, BUFF_SIZE + length);
	if (newBuff == NULL)
	{
		free(buffer);
		return (NULL);
	}

	return (newBuff);
}
