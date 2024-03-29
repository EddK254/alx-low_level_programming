#include "main.h"

/**
 * _power - calculates base and power
 * @base: exponet base
 * @pow: exponet power
 * Return: base and power value
 */

unsigned long int _power(unsigned int base, unsigned int pow)
{
	unsigned int i;
	unsigned long int num;

	num = 1;

	for (i = 1; i <= pow; i++)

		num *= base;

	return (num);

}

/**
 * print_binary - prints the binary representation of a number
 * @n: number printed
 * Return: void
 */

void print_binary(unsigned long int n)
{
	char flag;
	unsigned long int dev, result;

	flag = 0;

	dev = _power(2, sizeof(unsigned long int) * 8 - 1);

	while (dev != 0)

	{
		result = n & dev;

		if (result == dev)

		{

			flag = 1;

			_putchar('1');

		}

		else if (flag == 1 || dev == 1)

		{

			_putchar('0');

		}

		dev >>= 1;
	}
}
