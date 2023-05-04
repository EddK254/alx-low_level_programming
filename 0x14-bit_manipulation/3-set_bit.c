#include "main.h"

/**
 * set_bit - value of bit to 1 at given index.
 * @n: i pointer number
 * @index: starting from 0 of bit to set
 * Return: 1 if it worked, or -1 if an error occurred
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int i;

	if (index > (sizeof(unsigned long int) * 8 - 1))

		return (-1);

	i = 1 << index;

	*n = *n | i;

	return (1);
}
