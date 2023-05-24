#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * error_exit - Prints "Error" and exits with status 98.
 */
void error_exit(void)
{
	print_string("Error\n");
	exit(98);
}

/**
 * is_digit - Checks if a character is a digit.
 * @c: The character to check.
 * Return: 1 if c is a digit, 0 otherwise.
 */
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * multiply_numbers - Multiplies two positive numbers.
 * @num1: The first number as a string.
 * @num2: The second number as a string.
 * Return: The result of the multiplication as a string.
 */
char *multiply_numbers(char *num1, char *num2)
{
	int len1, len2, i, j, k, carry, n1, n2, sum;
	int *result;
	char *mul;

	len1 = string_length(num1);
	len2 = string_length(num2);

	result = malloc(sizeof(int) * (len1 + len2));
	if (result == NULL)
		error_exit();

	for (i = 0; i < len1 + len2; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		n1 = num1[i] - '0';

		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			sum = (n1 * n2) + result[i + j + 1] + carry;

			carry = sum / 10;
			result[i + j + 1] = sum % 10;
		}

		if (carry > 0)
			result[i + j + 1] += carry;
	}

	k = 0;
	while (result[k] == 0 && k < len1 + len2 - 1)
		k++;

	mul = malloc(sizeof(char) * (len1 + len2 - k + 1));
	if (mul == NULL)
		error_exit();

	for (i = 0; i < len1 + len2 - k; i++)
		mul[i] = result[k + i] + '0';

	mul[i] = '\0';

	free(result);

	return mul;
}

/**
 * main - Entry point.
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
	char *num1, *num2, *result;

	if (argc != 3)
		error_exit();

	num1 = argv[1];
	num2 = argv[2];

	while (*num1)
	{
		if (!is_digit(*num1))
			error_exit();
		num1++;
	}

	while (*num2)
	{
		if (!is_digit(*num2))
			error_exit();
		num2++;
	}

	result = multiply_numbers(argv[1], argv[2]);
	print_string(result);
	print_character('\n');
	free(result);

	return 0;
}

