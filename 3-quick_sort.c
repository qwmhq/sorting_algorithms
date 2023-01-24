#include "sort.h"

/**
 * swap_ints - swap two integers
 *
 * @n1: integer
 * @n2: integer
 */
void swap_ints(int *n1, int *n2)
{
	int temp;

	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

/**
 * lomuto_partition - partition an array using
 * the Lomuto partition scheme
 *
 * @array: the array to be partitioned
 * @low: the beginning index
 * @high: the end index
 * @size: the size of the array
 *
 * Return: the pivot index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int pivot_index, i;

	pivot_index = low - 1;
	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			pivot_index++;
			if (i != pivot_index)
			{
				swap_ints(&array[i], &array[pivot_index]);
				print_array(array, size);
			}
		}
	}
	pivot_index++;
	if (pivot_index != high)
	{
		swap_ints(&array[pivot_index], &array[high]);
		print_array(array, size);
	}
	return (pivot_index);
}

/**
 * quicksort - sort an array of integers in
 * ascending order using the quicksort algorithm
 *
 * @array: the array to be sorted
 * @low: the beginning index
 * @high: the end index
 * @size: the size of the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low >= high || low < 0)
		return;
	pivot_index = lomuto_partition(array, low, high, size);
	quicksort(array, low, pivot_index - 1, size);
	quicksort(array, pivot_index + 1, high, size);
}

/**
 * quick_sort - sort an array of integers in
 * ascending order using the quick sort algorithm
 *
 * @array: the array to sort
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	quicksort(array, 0, size - 1, size);
}
