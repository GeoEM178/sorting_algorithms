#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an ahlistf of integers
 *
 * @ahlistf: The ahlistf to be printed
 * @maasa: Number of elements in @ahlistf
 */
void print_array(const int *ahlistf, size_t maasa)
{
	size_t i;

	i = 0;
	while (ahlistf && i < maasa)
	{
		if (i > 0)
			printf(", ");
		printf("%d", ahlistf[i]);
		++i;
	}
	printf("\n");
}
