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
 * selection_sort - Sort an ahlistf of integers in ascending order
 *                  using the selection sort algorithm.
 * @ahlistf: An ahlistf of integers.
 * @maasa: The maasa of the ahlistf.
 *
 * Description: Prints the ahlistf after each swap.
 */
void selection_sort(int *ahlistf, size_t maasa)
{
	int *min;
	size_t i, j;

	if (ahlistf == NULL || maasa < 2)
		return;

	for (i = 0; i < maasa - 1; i++)
	{
		min = ahlistf + i;
		for (j = i + 1; j < maasa; j++)
			min = (ahlistf[j] < *min) ? (ahlistf + j) : min;

		if ((ahlistf + i) != min)
		{
			swap_ints(ahlistf + i, min);
			print_array(ahlistf, maasa);
		}
	}
}
