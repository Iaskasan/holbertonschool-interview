#include "palindrome.h"

/**
 * is_palindrome - checks whether an unsigned integer is a palindrome
 * @n: number to check
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long reversed_half;

	if (n != 0 && n % 10 == 0)
		return (0);

	reversed_half = 0;
	while (n > reversed_half)
	{
		reversed_half = reversed_half * 10 + (n % 10);
		n /= 10;
	}

	if (n == reversed_half || n == reversed_half / 10)
		return (1);

	return (0);
}
