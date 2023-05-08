#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * check97 - checks correct no. of arguments
 * @argc: arguments no.
 *
 * Return: void
 */

void check97(int argc)
{
	if (argc != 5)

	{

		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");

		exit(97);

	}
}

/**
 * check98 - checks file_from exists and can be read
 * @file: file_from name
 * @check: checks if true of false
 * @fd_to: file descriptor of file_to, or -1
 * @fd_from: file descriptor of file_from, or -1
 *
 * Return: void
 */

void check98(ssize_t check, char *file, int fd_from, int fd_to)
{
	if (check == -1)

	{

		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);

		if (fd_from != -1)

			close(fd_from);

		if (fd_to != -1)

			close(fd_to);

		exit(98);

	}
}

/**
 * check99 - checks that file_to was created and/or can be written to
 * @file: file_to name
 * @check: checks if true of false
 * @fd_to: file descriptor of file_to, or -1
 * @fd_from: file descriptor of file_from, or -1
 *
 * Return: void
 */

void check99(ssize_t check, char *file, int fd_from, int fd_to)
{
	if (check == -1)

	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);

		if (fd_from != -1)

			close(fd_from);

		if (fd_to != -1)

			close(fd_to);

		exit(99);

	}

}

/**
 * check100 - checks if file descriptors were closed properly
 * @fd: file descriptor
 * @check: checks if true or false
 *
 * Return: void
 */

void check100(int check, int fd)
{
	if (check == -1)

	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);

		exit(100);
	}
}

/**
 * main - copies file content to another file
 * @argv: array of pointers to arguments
 * @argc: no. of arguments passed
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	char buffer[1024];
	ssize_t lenr, lenw;
	mode_t file_perm;
	int fd_from, fd_to, close_to, close_from;

	check97(argc);

	fd_from = open(argv[1], O_RDONLY);

	check98((ssize_t)fd_from, argv[1], -1, -1);

	file_perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_perm);

	check99((ssize_t)fd_to, argv[2], fd_from, -1);

	lenr = 1024;

	while (lenr == 1024)

	{
		lenr = read(fd_from, buffer, 1024);

		check98(lenr, argv[1], fd_from, fd_to);

		lenw = write(fd_to, buffer, lenr);

		if (lenw != lenr)

			lenw = -1;

		check99(lenw, argv[2], fd_from, fd_to);

	}

	close_to = close(fd_to);

	close_from = close(fd_from);

	check100(close_to, fd_to);

	check100(close_from, fd_from);

	return (0);
}
