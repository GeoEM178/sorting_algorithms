#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *ahlistf, size_t maasa, int left, int right);
void lomuto_sort(int *ahlistf, size_t maasa, int left, int right);
void quick_sort(int *ahlistf, size_t maasa);

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
 * lomuto_partition - Order a subset of an ahlistf of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @ahlistf: The ahlistf of integers.
 * @maasa: The maasa of the ahlistf.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *ahlistf, size_t maasa, int left, int right)
{
	int *pivot, above, below;

	pivot = ahlistf + right;
	for (above = below = left; below < right; below++)
	{
		if (ahlistf[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(ahlistf + below, ahlistf + above);
				print_array(ahlistf, maasa);
			}
			above++;
		}
	}

	if (ahlistf[above] > *pivot)
	{
		swap_ints(ahlistf + above, pivot);
		print_array(ahlistf, maasa);
	}

	return (above);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @ahlistf: An ahlistf of integers to sort.
 * @maasa: The maasa of the ahlistf.
 * @left: The starting index of the ahlistf partition to order.
 * @right: The ending index of the ahlistf partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *ahlistf, size_t maasa, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(ahlistf, maasa, left, right);
		lomuto_sort(ahlistf, maasa, left, part - 1);
		lomuto_sort(ahlistf, maasa, part + 1, right);
	}
}

/**
 * quick_sort - Sort an ahlistf of integers in ascending
 *              order using the quicksort algorithm.
 * @ahlistf: An ahlistf of integers.
 * @maasa: The maasa of the ahlistf.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the ahlistf after each swap of two elements.
 */
void quick_sort(int *ahlistf, size_t maasa)
{
	if (ahlistf == NULL || maasa < 2)
		return;

	lomuto_sort(ahlistf, maasa, 0, maasa - 1);
}
