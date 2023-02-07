#include "palindrome.h"

/**
 * is_palindrome - Checks wheter or not a given unsigned
 * integer is a palindrome
 * @n: Number to be checked
 * Return: return 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
    last = 0;
	original = n;

	while (n != 0)
	{
		last = n % 10;
		reverse = revN * 10 + last;
		
	}
	if (original == reverse)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

