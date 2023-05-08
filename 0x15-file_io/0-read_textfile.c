#include "main.h"
#include <stdlib.h>

/*
 * File: 0-read_textfile.c
 * Auth: Marcus
 */

/**
 * read_textfile - text file is read and printed to POSIX stdout
 * @filename: Pointer to name of file
 * @letters: Number of letters function should read and print
 * Return: If function fails or filename is NULL - 0
 *         O/w - actual number of bytes function can read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t o, r, w;

	if (filename == NULL)

		return (0);

	buffer = malloc(sizeof(char) * letters);

	if (buffer == NULL)

		return (0);

	o = open(filename, O_RDONLY);

	r = read(o, buffer, letters);

	w = write(STDOUT_FILENO, buffer, r);

	if (o == -1 || r == -1 || w == -1 || w != r)

	{

		free(buffer);

		return (0);

	}

	free(buffer);

	close(o);

	return (w);
}
