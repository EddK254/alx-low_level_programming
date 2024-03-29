#include "main.h"

/**
 * clear_bit - value of bit to 0 at given index
 * @index: starting from 0 of bit to set
 * @n: num of i
 * Return: 1 if it worked, or -1 if an error occurred
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int i;

	if (index > (sizeof(unsigned long int) * 8 - 1))

		return (-1);

	i = ~(1 << index);

	*n = *n & i;

	return (1);
}
