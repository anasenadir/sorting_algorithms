#include "sort.h"


/**
 * selection_sort - function that sorts an array of integers in
 * ascending order using the Selection sort algorithm
 * @array: array of unsorted integers
 * @size: the size of the array
 * Return: Nothing.
*/
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, current_minimum = 0;
	int tmp = 0;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		current_minimum = i;
		for (j = i + 1 ; j < size; j++)
		{
			if (array[j] < array[current_minimum])
				current_minimum = j;
		}
		if (current_minimum != i)
		{
			tmp = array[current_minimum];
			array[current_minimum] = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
	}
}
