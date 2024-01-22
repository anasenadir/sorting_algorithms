#include "sort.h"

/**
 * swap - swap two items in the array
 * @ptr1: the first integer to swap.
 * @ptr2: the second integer to swap.
*/
void swap(int *ptr1, int *ptr2)
{
	int tmp;

	tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}

/**
 * partition - func
 * @array: the array
 * @start: the place where we start
 * @end: the place where we end
 * @size: the size of the array
 * Return: the pivot index otherwise, -1
*/
int partition(int *array, size_t size, int start, int end)
{
	int *pivot, j, i;

	pivot = array + end;
	j = i = start;
	for (; i < end; i++)
	{
		if (array[i] < *pivot)
		{
			if (j < i)
			{
				swap(array + i, array + j);
				print_array(array, size);
			}
			j++;
		}
	}

	if (array[j] > *pivot)
	{
		swap(array + j, pivot);
		print_array(array, size);
	}

	return (j);
}

/**
 * quick_s - the base function for recursion
 * operations
 * @array: the array to be sorted
 * @start: the place where we start
 * @end: the place where we end
 * @size: the size of the array
*/
void quick_s(int *array, int start, int end, int size)
{
	int pivot_index;

	if (start >= end)
		return;

	pivot_index = partition(array, size, start, end);

	if (pivot_index == -1)
		return;
	quick_s(array, start, pivot_index - 1, size);
	quick_s(array, pivot_index + 1, end, size);
}

/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: array to e sorted
 * @size: the size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_s(array, 0, size - 1, size);
}
