#include "sandpiles.h"
/**
 * print_grid_unstable - print grid
 * @grid: grid to print
 * Return: Nothing
 */
void print_grid_unstable(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
/**
 * sandpiles_check - check if sandpiles is stable or not
 * @grid1: sandpile to check
 * @grid: grid contains sand will be take off
 * Return: 0 if sandpiles is stable otherwise -1
 */
int sandpiles_check(int grid1[3][3], int grid[3][3])
{