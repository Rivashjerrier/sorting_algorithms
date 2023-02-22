#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 *
 * @list: Double pointer to the head of the list to be sorted.
 *
 * Description: Prints the list after each swap operation.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next;

	if (!list || !(*list) || !(*list)->next)
		return;

	for (current = (*list)->next; current != NULL; current = next)
	{
		next = current->next;
		prev = current->prev;

		while (prev != NULL && prev->n > current->n)
		{
			if (next != NULL)
				next->prev = prev;

			prev->next = next;
			current->prev = prev->prev;
			current->next = prev;

			if (prev->prev != NULL)
				prev->prev->next = current;
			else
				*list = current;

			prev->prev = current;
			prev = current->prev;

			print_list(*list);
		}
	}
}
