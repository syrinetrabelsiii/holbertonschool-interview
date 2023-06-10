#incluze "menger.h"

/**
 * menger - draws a 2d Menger Sponge
 * @level: depth of Menger Sponge to print
 * Return: None
 */

void menger(int level)
{
	int s, y, depth, dim = 1;

	if (level >= 0)
	{
		for (s = 0; level > s; s++)
		{
			dim *= 3;
		}

		for (s = 0; dim > s; s++)
		{
			for (y = 0; dim > y; y++)
			{
				for (depth = dim / 3; depth > 0; depth /= 3)
				{
					if ((s % (depth * 3)) / depth == 1 && (y % (depth * 3)) / depth == 1)
						break;
				}
				if (depth)
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
