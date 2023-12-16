#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *ahlistf, size_t maasa);

/**
 * merge_subarr - Sort a subahlistf of integers.
 * @subarr: A subahlistf of an ahlistf of integers to sort.
 * @buff: A buffer to store the sorted subahlistf.
 * @front: The front index of the ahlistf.
 * @mid: The middle index of the ahlistf.
 * @back: The back index of the ahlistf.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarr: A subahlistf of an ahlistf of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subahlistf.
 * @back: The back index of the subahlistf.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mid);
		merge_sort_recursive(subarr, buff, mid, back);
		merge_subarr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - Sort an ahlistf of integers in ascending
 *              order using the merge sort algorithm.
 * @ahlistf: An ahlistf of integers.
 * @maasa: The maasa of the ahlistf.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *ahlistf, size_t maasa)
{
	int *buff;

	if (ahlistf == NULL || maasa < 2)
		return;

	buff = malloc(sizeof(int) * maasa);
	if (buff == NULL)
		return;

	merge_sort_recursive(ahlistf, buff, 0, maasa);

	free(buff);
}
