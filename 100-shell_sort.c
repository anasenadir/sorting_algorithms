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
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @array: the array to be sorted
 * @size: the array size
*/
void shell_sort(int *array, size_t size)
{
	size_t gap, i, swaped;

	if (array == NULL || size < 2)
		return;
	gap = size / 2 - 1;

	swaped = 1;
	while (swaped && gap >= 1)
	{
		swaped = 0;
		for (i = 0; i < size - gap; i++)
		{
			if (array[i] > array[i + gap])
			{
				swaped = 1;
				swap(array + i, array + i + gap);
			}
		}
		print_array(array, size);
		if (gap > 1)
			gap = gap / 2;

		if (swaped == 0)
			break;
	}

}
