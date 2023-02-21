#include "main.h"

/**
 * print_alphabet - function that prints alphabet in lower case
 *
 * Return: Alaways 0;
 */

void print_alphabet(void)
{
	char letter;

	for (letter = 'a' ; letter <= 'z' ; letter++)
		_putchar(letter);

	_putchar('\n');
}
