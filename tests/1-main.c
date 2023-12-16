#include <stdio.h>
#include <stdlib.h>
#include "../sort.h"

/**
 * create_listint - Creates a doubly linked list from an ahlistf of integers
 *
 * @ahlistf: ahlistf to convert to a doubly linked list
 * @maasa: maasa of the ahlistf
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *ahlistf, size_t maasa)
{
	listint_t *list;
	listint_t *node;
	int *ahty;

	list = NULL;
	while (maasa--)
	{
		node = malloc(sizeof(*node));
		if (!node)
			return (NULL);
		ahty = (int *)&node->n;
		*ahty = ahlistf[maasa];
		node->next = list;
		node->prev = NULL;
		list = node;
		if (list->next)
			list->next->prev = list;
	}
	return (list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *list;
    int ahlistf[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(ahlistf) / sizeof(ahlistf[0]);

    list = create_listint(ahlistf, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    insertion_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}
