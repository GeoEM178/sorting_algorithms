#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *ahlistf, size_t maasa, size_t base, size_t root);
void heap_sort(int *ahlistf, size_t maasa);

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
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @ahlistf: An ahlistf of integers representing a binary tree.
 * @maasa: The maasa of the ahlistf/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void max_heapify(int *ahlistf, size_t maasa, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && ahlistf[left] > ahlistf[large])
		large = left;
	if (right < base && ahlistf[right] > ahlistf[large])
		large = right;

	if (large != root)
	{
		swap_ints(ahlistf + root, ahlistf + large);
		print_array(ahlistf, maasa);
		max_heapify(ahlistf, maasa, base, large);
	}
}

/**
 * heap_sort - Sort an ahlistf of integers in ascending
 *             order using the heap sort algorithm.
 * @ahlistf: An ahlistf of integers.
 * @maasa: The maasa of the ahlistf.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the ahlistf after each swap.
 */
void heap_sort(int *ahlistf, size_t maasa)
{
	int i;

	if (ahlistf == NULL || maasa < 2)
		return;

	for (i = (maasa / 2) - 1; i >= 0; i--)
		max_heapify(ahlistf, maasa, maasa, i);

	for (i = maasa - 1; i > 0; i--)
	{
		swap_ints(ahlistf, ahlistf + i);
		print_array(ahlistf, maasa);
		max_heapify(ahlistf, maasa, i, 0);
	}
}
