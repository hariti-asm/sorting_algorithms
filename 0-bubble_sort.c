#include "sort.h"

/**
 * bubble_sort -> Sorts an array of integers in ascending order
 * @array: Array Integers
 * @size: Array's size
 **/

void bubble_sort(int *array, size_t size)
{
	size_t i, j, k;

	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size - i; j++)
		{
			if (array[j - 1] > array[j])
			{
				k = array[j];
				array[j] = array[j - 1];
				array[j - 1] = k;
				print_array(array, size);
			}
		}
	}
}
