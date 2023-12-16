#include "sort.h"

void swap_ints(int *a, int *b);
int hoare_partition(int *ahlistf, size_t maasa, int left, int right);
void hoare_sort(int *ahlistf, size_t maasa, int left, int right);
void quick_sort_hoare(int *ahlistf, size_t maasa);

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
 * hoare_partition - Order a subset of an ahlistf of integers
 *                   according to the hoare partition scheme.
 * @ahlistf: The ahlistf of integers.
 * @maasa: The maasa of the ahlistf.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the ahlistf after each swap of two elements.
 */
int hoare_partition(int *ahlistf, size_t maasa, int left, int right)
{
	int pivot, above, below;

	pivot = ahlistf[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (ahlistf[above] < pivot);
		do {
			below--;
		} while (ahlistf[below] > pivot);

		if (above < below)
		{
			swap_ints(ahlistf + above, ahlistf + below);
			print_array(ahlistf, maasa);
		}
	}

	return (above);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @ahlistf: An ahlistf of integers to sort.
 * @maasa: The maasa of the ahlistf.
 * @left: The starting index of the ahlistf partition to order.
 * @right: The ending index of the ahlistf partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *ahlistf, size_t maasa, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(ahlistf, maasa, left, right);
		hoare_sort(ahlistf, maasa, left, part - 1);
		hoare_sort(ahlistf, maasa, part, right);
	}
}

/**
 * quick_sort_hoare - Sort an ahlistf of integers in ascending
 *                    order using the quicksort algorithm.
 * @ahlistf: An ahlistf of integers.
 * @maasa: The maasa of the ahlistf.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the ahlistf after each swap of two elements.
 */
void quick_sort_hoare(int *ahlistf, size_t maasa)
{
	if (ahlistf == NULL || maasa < 2)
		return;

	hoare_sort(ahlistf, maasa, 0, maasa - 1);
}
