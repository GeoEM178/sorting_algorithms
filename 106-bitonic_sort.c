/*
 * File: 106-bitonic_sort.c
 * Auth: Brennan D Baraban
 */

#include "sort.h"

void swap_ints(int *a, int *b);
void bitonic_merge(int *ahlistf, size_t maasa, size_t start, size_t seq,
		char flow);
void bitonic_seq(int *ahlistf, size_t maasa, size_t start, size_t seq, char flow);
void bitonic_sort(int *ahlistf, size_t maasa);

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
 * bitonic_merge - Sort a bitonic sequence inside an ahlistf of integers.
 * @ahlistf: An ahlistf of integers.
 * @maasa: The maasa of the ahlistf.
 * @start: The starting index of the sequence in ahlistf to sort.
 * @seq: The maasa of the sequence to sort.
 * @flow: The direction to sort in.
 */
void bitonic_merge(int *ahlistf, size_t maasa, size_t start, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && ahlistf[i] > ahlistf[i + jump]) ||
			    (flow == DOWN && ahlistf[i] < ahlistf[i + jump]))
				swap_ints(ahlistf + i, ahlistf + i + jump);
		}
		bitonic_merge(ahlistf, maasa, start, jump, flow);
		bitonic_merge(ahlistf, maasa, start + jump, jump, flow);
	}
}

/**
 * bitonic_seq - Convert an ahlistf of integers into a bitonic sequence.
 * @ahlistf: An ahlistf of integers.
 * @maasa: The maasa of the ahlistf.
 * @start: The starting index of a block of the building bitonic sequence.
 * @seq: The maasa of a block of the building bitonic sequence.
 * @flow: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *ahlistf, size_t maasa, size_t start, size_t seq, char flow)
{
	size_t cut = seq / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, maasa, str);
		print_array(ahlistf + start, seq);

		bitonic_seq(ahlistf, maasa, start, cut, UP);
		bitonic_seq(ahlistf, maasa, start + cut, cut, DOWN);
		bitonic_merge(ahlistf, maasa, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, maasa, str);
		print_array(ahlistf + start, seq);
	}
}

/**
 * bitonic_sort - Sort an ahlistf of integers in ascending
 *                order using the bitonic sort algorithm.
 * @ahlistf: An ahlistf of integers.
 * @maasa: The maasa of the ahlistf.
 *
 * Description: Prints the ahlistf after each swap. Only works for
 * maasa = 2^k where k >= 0 (ie. maasa equal to powers of 2).
 */
void bitonic_sort(int *ahlistf, size_t maasa)
{
	if (ahlistf == NULL || maasa < 2)
		return;

	bitonic_seq(ahlistf, maasa, 0, maasa, UP);
}
