#include "menger.h"

/**
 * menger - Draws a 2D Menger Sponge
 * @level: Depth of Menger Sponge to print
 * Return: None
 */

void menger(int level)
{
	int X, Y, d, dim = 1;

	if (level >= 0)
	{
		for (X = 0; level > X; X++)
		{
			dim *= 3;
		}

		for (X = 0; dim > X; X++)
		{
			for (Y = 0; dim > Y; Y++)
			{
				for (d = dim / 3; d > 0; d /= 3)
				{
					if ((X % (d * 3)) / d == 1 && (Y % (d * 3)) / d == 1)
						break;
				}
				if (d)
				{
					printf(" ");
				}
				else
				{
					printf("#");
				}
			}
			printf("\n");
		}
	}
}


