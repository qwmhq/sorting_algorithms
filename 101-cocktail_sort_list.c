#include "sort.h"

/**
 * swap_nodes - swap two adjacent nodes in a
 * doubly linked list
 *
 * @list: the head of the list
 * @ptr: node in the list
 * @next: node after ptr
 */
void swap_nodes(listint_t **list, listint_t *ptr, listint_t *next)
{
	next->prev = ptr->prev;
	ptr->next = next->next;
	ptr->prev = next;
	next->next = ptr;
	if (ptr->next != NULL)
		ptr->next->prev = ptr;
	if (next->prev != NULL)
		next->prev->next = next;
	else
		*list = next;
}

/**
 * cocktail_sort_list - sort a doubly linked list of
 * integers in ascending order using the cocktail shaker
 * sort algorithm
 *
 * @list: the list to sort
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *ptr;
	int swapped;

	if (list == NULL || *list == NULL)
		return;
	do {
		swapped = 0;
		ptr = *list;
		while (ptr->next != NULL)
		{
			if (ptr->n > ptr->next->n)
			{
				swap_nodes(list, ptr, ptr->next);
				swapped = 1;
				print_list(*list);
			}
			else
				ptr = ptr->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (ptr->prev != NULL)
		{
			if (ptr->n < ptr->prev->n)
			{
				swap_nodes(list, ptr->prev, ptr);
				swapped = 1;
				print_list(*list);
			}
			else
				ptr = ptr->prev;
		}
	} while (swapped == 1);

}
