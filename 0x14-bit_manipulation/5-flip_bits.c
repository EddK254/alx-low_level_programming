#include "main.h"

/**
 * flip_bits - flip from one number to another.
 * @m: second number
 * @n: first number
 * Return: the number of bits you would need to flip
*/

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int j, i;
	unsigned long int differnce, result;

	result = 1;

	j = 0;

	differnce = n ^ m;

	for (i = 0; i < (sizeof(unsigned long int) * 8); i++)

	{

		if (result == (differnce & result))

			j++;

		result <<= 1;

	}

	return (j);
}
