#include "sort.h"

/**
 * insertion_sort_list - sort a doubly linked list of integers
 * in ascending order using the insertion sort algorithm
 *
 * @list: the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *prev;

	ptr = *list;
	while (ptr != NULL)
	{
		prev = ptr->prev;
		while (prev != NULL && ptr->n < prev->n)
		{
			ptr->prev = prev->prev;
			prev->next = ptr->next;
			prev->prev = ptr;
			ptr->next = prev;
			if (prev->next != NULL)
				prev->next->prev = prev;
			if (ptr->prev != NULL)
				ptr->prev->next = ptr;
			else
				*list = ptr;
			print_list(*list);
			prev = ptr->prev;
		}
		ptr = ptr->next;
	}
}
