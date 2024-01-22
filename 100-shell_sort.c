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
	size_t gap, i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	gap = 1;
	while (gap <= (size / 3))
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];

			for (j = i; j >= gap && (array[j - gap] > tmp); j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}

		gap = (gap - 1) / 3;
		print_array(array, size);
	}

}
