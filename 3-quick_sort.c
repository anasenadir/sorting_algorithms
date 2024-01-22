#include "sort.h"
#include <stdio.h>

/**
 * swap - swap two items in the array
 * @array: the array
 * @f_ind: the index of the first item
 * @s_ind: the index of the second item
 *
*/
void swap(int *array, int f_ind, int s_ind)
{
	int tmp;

	tmp = array[f_ind];
	array[f_ind] = array[s_ind];
	array[s_ind] = tmp;
}

/**
 * partition - func
 * @array: the array
 * @start: the place where we start
 * @end: the place where we end
 * @size: the size of the array
 * Return: the pivot index otherwise, -1
*/
int partition(int *array, int start, int end, int size)
{
	int pivot, tmp, i, j;

	pivot = array[start];
	i = start;
	j = end;

	if (j == i + 1)
	{
		if (array[i] > array[j])
			swap(array, i, j);
		return (-1);
	}
	while (j > i)
	{
		do {
			i += 1;
		} while (array[i] < pivot);

		do {
			j -= 1;
		} while (array[j] > pivot);

		if (j > i)
		{
			swap(array, i, j);
			print_array(array, size);
		}
	}

	swap(array, j, start);
	print_array(array, size);

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

	pivot_index = partition(array, start, end, size);

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
	quick_s(array, 0, size, size);
}
