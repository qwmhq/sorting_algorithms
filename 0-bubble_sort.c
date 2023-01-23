#include "sort.h"

/**
 * bubble_sort - sort an array of integers in ascending
 * order using the bubble sort algorithm
 *
 * @array: the array to be sorted
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int sorted = 0, swapped, temp;
	size_t i;

	while (sorted == 0)
	{
		swapped = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i] < array[i - 1])
			{
				temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (swapped == 0)
			sorted = 1;
	}
}
