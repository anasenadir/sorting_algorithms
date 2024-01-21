#include "sort.h"


/**
 * bubble_sort - function that sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, swaped;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		swaped = 0;
		for (j = 0; j + i < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swaped = 1;
				print_array(array, size);
			}
		}

		if (swaped == 0)
			break;
	}
}
