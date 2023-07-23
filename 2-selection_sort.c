#include "sort.h"

/**
 * selection_sort -> Sorts an array of integers in ascending order
 * @array: Array Integers
 * @size: Array's size
 **/

void selection_sort(int *array, size_t size)
{
	size_t i, j, k, n;
	int a, b;

	if (array)
	{
		for (i = 0; i < size; i++)
		{
			a = array[i];
			b = 0;
			for (j = i; j < size ; j++)
			{
				if (array[j] < a)
				{
					n = j;
					a = array[j];
					b = 1;
				}
			}
			if (b == 1)
			{
				k = array[i];
				array[i] = array[n];
				array[n] = k;
				print_array(array, size);
			}
		}
	}
}
