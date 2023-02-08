#include "palindrome.h"

/**
 * is_palindrome - Checks wheter or not
 * @n: Number to be checked
 * 
 * Return: return 1 if n is a palindrome,0 otherwise
 */


int is_palindrome(unsigned long n)
{
	unsigned long reversed_number = 0, remainder, original_number;

	original_number = n;

	while (n != 0)
	{
		remainder = n % 10;
		reversed_number = reversed_number * 10 + remainder;
		n /= 10;
	}

	if (original_number == reversed_number)
		return (1);

	return (0);
}

