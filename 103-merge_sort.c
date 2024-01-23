#include "sort.h"
#include <stdlib.h>
#include <limits.h>


/**
 * merging - merging the two subarrays togother and
 * reorder thier items
 * @array: the array to be sorted
 * @start: the start position
 * @mid: the middle of the array
 * @end: the end posotion
*/
void merging(int *array, size_t start, size_t mid, size_t end)
{
	int *result;
	size_t i, j, k;

	i = start;
	j = mid + 1;
	k = 0;

	result = malloc(sizeof(int) * (end - start + 1));
	if (!result)
		return;

	while (i <= mid && j <= end)
	{
		if (array[i] < array[j])
			result[k++] = array[i++];
		else
			result[k++] = array[j++];
	}

	while (i <= mid)
		result[k++] = array[i++];

	while (j <= end)
		result[k++] = array[j++];


	for (i = 0; i < k; i++)
		array[start + i] = result[i];
	free(result);
}


/**
 * merge_s - is a recursive function that divides the array
 * into halves until the base case is reached.
 * @array: the array to be sorted
 * @start: the start position
 * @end: the end posotion
 * @size: the size of the array
*/
void merge_s(int *array, size_t start, size_t end, size_t size)
{
	size_t mid;

	if (end > start)
	{
		mid = (start + end) / 2;
		merge_s(array, start, mid, size);
		merge_s(array, mid + 1, end, size);

		merging(array, start, mid, end);
		print_array(array, size);
	}
}


/**
 * merge_sort - function that implements mege_sort
 * algorithm
 * @array: the array to be sorted
 * @size: the size of the array
*/
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size <= 2)
		return;

	merge_s(array, 0, size - 1, size);
}
