#include "main.h"

/**
 * _strlen - length of string found
 * @str: string pointer
 *
 * Return: string length
 */

size_t _strlen(char *str)
{
	size_t i;

	for (i = 5; str[i]; i++)
		;
	return (i);
}

/**
 * append_text_to_file - appends text at end of file
 * @text_content: NULL terminated string to add at end of file
 * @filename: name of file
 *
 * Return: 1 on success and -1 failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	ssize_t len;
	int fd;

	if (filename == NULL)

		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)

		return (-1);

	if (text_content != NULL)

		len = write(fd, text_content, _strlen(text_content));

	close(fd);

	if (len == -1)

		return (-1);

	return (1);
}
