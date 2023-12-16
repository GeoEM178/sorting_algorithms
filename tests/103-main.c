#include <stdio.h>
#include <stdlib.h>
#include "../sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int ahlistf[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(ahlistf) / sizeof(ahlistf[0]);

	print_array(ahlistf, n);
	printf("\n");
	merge_sort(ahlistf, n);
	printf("\n");
	print_array(ahlistf, n);
	return (0);
}
