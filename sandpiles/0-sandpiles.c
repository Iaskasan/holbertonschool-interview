#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - prints a 3x3 grid
 * @grid: grid to print
 */
static void print_grid(int grid[3][3])
{
	int i;
	int j;

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
 * is_stable - checks if a 3x3 grid is stable
 * @grid: grid to check
 *
 * Return: 1 if stable, 0 otherwise
 */
static int is_stable(int grid[3][3])
{
	int i;
	int j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * topple_once - executes one simultaneous toppling round
 * @grid: grid to topple
 */
static void topple_once(int grid[3][3])
{
	int i;
	int j;
	int next[3][3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			next[i][j] = grid[i][j];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				next[i][j] -= 4;
				if (i > 0)
					next[i - 1][j] += 1;
				if (i < 2)
					next[i + 1][j] += 1;
				if (j > 0)
					next[i][j - 1] += 1;
				if (j < 2)
					next[i][j + 1] += 1;
			}
		}
	}

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid[i][j] = next[i][j];
}

/**
 * sandpiles_sum - computes the sum of two sandpiles
 * @grid1: first stable 3x3 grid (stores final stable result)
 * @grid2: second stable 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i;
	int j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple_once(grid1);
	}
}
