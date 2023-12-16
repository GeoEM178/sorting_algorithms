#include "sort.h"

/**
 * swap_ints - Swap two integers in an ahlistf.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int ahty;

	ahty = *a;
	*a = *b;
	*b = ahty;
}

/**
 * shell_sort - Sort an ahlistf of integers in ascending
 *              order using the shell sort algorithm.
 * @ahlistf: An ahlistf of integers.
 * @maasa: The maasa of the ahlistf.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *ahlistf, size_t maasa)
{
	size_t gap, i, j;

	if (ahlistf == NULL || maasa < 2)
		return;

	for (gap = 1; gap < (maasa / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < maasa; i++)
		{
			j = i;
			while (j >= gap && ahlistf[j - gap] > ahlistf[j])
			{
				swap_ints(ahlistf + j, ahlistf + (j - gap));
				j -= gap;
			}
		}
		print_array(ahlistf, maasa);
	}
}
