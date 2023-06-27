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
*_realloc - reallocates a memory
*@ptr: a pointer to the memory previously allocated
*@old_size: size of the previous ptr
*@new_size: new size of the new memory block
*Return:a pointer to the newly allocated memory
*/

void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	char *new;
	size_t i;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(new_size));

	new = malloc(new_size);
	if (new == NULL)
		return (NULL);
	if (new_size < old_size)
	{
		for (i = 0; i < new_size; i++)
			*(new + i) = *((char *)ptr + i);
	}

	if (new_size > old_size)
	{
		for (i = 0; i < old_size; i++)
			*(new + i) = *((char *)ptr + i);
	}
	free(ptr);

	return (new);
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
