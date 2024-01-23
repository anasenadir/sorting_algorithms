#include "sort.h"
#include <stdlib.h>


/**
 * merging - merging the two subarrays togother and
 * reorder thier items
 * @array: the array to be sorted
 * @buff: A buffer to store the sorted subarray.
 * @start: The front index of the array.
 * @mid: the middle of the array
 * @end: the end posotion
*/
void merging(int *array, int *buff, size_t start, size_t mid,
		size_t end)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + start, mid - start);

	printf("[right]: ");
	print_array(array + mid, end - mid);

	for (i = start, j = mid; i < mid && j < end; k++)
		buff[k] = (array[i] < array[j]) ? array[i++] : array[j++];

	while (i < mid)
		buff[k++] = array[i++];

	while (j < end)
		buff[k++] = array[j++];

	for (i = start, k = 0; i < end; i++)
		array[i] = buff[k++];

	printf("[Done]: ");
	print_array(array + start, end - start);
}


/**
 * merge_s - is a recursive function that divides the array
 * into halves until the base case is reached.
 * @array: the array to be sorted
 * @buff: A buffer to store the sorted result.
 * @start: the start position
 * @end: the end posotion
*/
void merge_s(int *array, int *buff, size_t start, size_t end)
{
	size_t mid;

	if (end - start > 1)
	{
		mid = (end + start) / 2;
		merge_s(array, buff, start, mid);
		merge_s(array, buff, mid, end);
		merging(array, buff, start, mid, end);
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
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_s(array, buff, 0, size);

	free(buff);
}
