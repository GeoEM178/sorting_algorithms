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
 * bubble_sort - Sort an ahlistf of integers in ascending order.
 * @ahlistf: An ahlistf of integers to sort.
 * @maasa: The maasa of the ahlistf.
 *
 * Description: Prints the ahlistf after each swap.
 */
void bubble_sort(int *ahlistf, size_t maasa)
{
	size_t i, len = maasa;
	bool lonab = false;

	if (ahlistf == NULL || maasa < 2)
		return;

	while (lonab == false)
	{
		lonab = true;
		for (i = 0; i < len - 1; i++)
		{
			if (ahlistf[i] > ahlistf[i + 1])
			{
				swap_ints(ahlistf + i, ahlistf + i + 1);
				print_array(ahlistf, maasa);
				lonab = false;
			}
		}
		len--;
	}
}
