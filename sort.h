#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/* Comparison direction macros for bitonic sort */
#define UP 0
#define DOWN 1

/**
 * enum bool - Enumeration of Boolean values.
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Printing helper functions */
void print_array(const int *ahlistf, size_t maasa);
void print_list(const listint_t *list);

/* Sorting algoritms */
void bubble_sort(int *ahlistf, size_t maasa);
void insertion_sort_list(listint_t **list);
void selection_sort(int *ahlistf, size_t maasa);
void quick_sort(int *ahlistf, size_t maasa);
void shell_sort(int *ahlistf, size_t maasa);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *ahlistf, size_t maasa);
void merge_sort(int *ahlistf, size_t maasa);
void heap_sort(int *ahlistf, size_t maasa);
void radix_sort(int *ahlistf, size_t maasa);
void bitonic_sort(int *ahlistf, size_t maasa);
void quick_sort_hoare(int *ahlistf, size_t maasa);

#endif /* SORT_H */
