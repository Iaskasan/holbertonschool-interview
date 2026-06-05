#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int _putchar(char c);

/**
 * print_error_and_exit - print "Error\n" using _putchar and exit 98
 */
void print_error_and_exit(void)
{
	char *s = "Error\n";

	while (*s)
		_putchar(*s++);
	exit(98);
}

/**
 * multiply_strings - multiplies two number strings
 * @num1: first number as string
 * @num2: second number as string
 * Return: result as allocated string
 */
char *multiply_strings(char *num1, char *num2)
{
	int len1 = strlen(num1);
	int len2 = strlen(num2);
	int result_len = len1 + len2;
	int *result = malloc(result_len * sizeof(int));
	int i, j, mul, p, carry;
	char *str;

	if (!result)
		return (NULL);

	/* Initialize result array */
	for (i = 0; i < result_len; i++)
		result[i] = 0;

	/* Multiply each digit */
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		mul = num1[i] - '0';
		p = i + len2;

		for (j = len2 - 1; j >= 0; j--)
		{
			int product = mul * (num2[j] - '0') + result[p] + carry;

			result[p] = product % 10;
			carry = product / 10;
			p--;
		}

		if (carry > 0)
			result[p] += carry;
	}

	/* Find start of result (skip leading zeros) */
	i = 0;
	while (i < result_len - 1 && result[i] == 0)
		i++;

	/* Allocate and build result string */
	str = malloc((result_len - i + 1) * sizeof(char));
	if (!str)
	{
		free(result);
		return (NULL);
	}

	for (j = 0; i < result_len; i++, j++)
		str[j] = result[i] + '0';
	str[j] = '\0';

	free(result);
	return (str);
}

/**
 * print_string - print a string using _putchar
 * @s: string to print
 */
void print_string(char *s)
{
	while (*s)
		_putchar(*s++);
}

/**
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	char *p;
	char *result;

	if (argc != 3)
	{
		print_error_and_exit();
	}

	for (p = argv[1]; *p; p++)
	{
		if (*p < '0' || *p > '9')
		{
			print_error_and_exit();
		}
	}

	for (p = argv[2]; *p; p++)
	{
		if (*p < '0' || *p > '9')
		{
			print_error_and_exit();
		}
	}

	/* Multiply the strings */
	result = multiply_strings(argv[1], argv[2]);

	if (!result)
		print_error_and_exit();

	/* Print the result */
	print_string(result);
	_putchar('\n');

	free(result);
	return (0);
}
