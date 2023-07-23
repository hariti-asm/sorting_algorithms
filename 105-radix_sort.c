#include "sort.h"

/**
 * max_val -> Find the max value from array
 * @array: Array Integers
 * @size: Array's size
 * Return: Max Value
 */

int max_val(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	} return (max);
}

/**
 * radix_sort -> Sorts an array of integers in ascending order
 * @array: Array Integers
 * @size: Array's size
 */

void radix_sort(int *array, size_t size)
{
	int *new;
	int i, max, j = 1;
	int m = size;

	if (!array || size < 2)
		return;
	max = max_val(array, size);
	new = malloc(sizeof(int) * size);
	while (max / j > 0)
	{
		int brews[20] = {0};

		i = 0;
		while (i < m)
		{
			brews[(array[i] / j) % 10]++;
			i++;
		}
		if (brews != NULL)
		{
			for (i = 1; i < 10; i++)
				brews[i] += brews[i - 1];

			for (i = m - 1; i >= 0; i--)
			{
				new[brews[(array[i] / j) % 10] - 1] = array[i];
				brews[(array[i] / j) % 10]--;
			}
			for (i = 0; i < m; i++)
				array[i] = new[i];
		} j *= 10;
		print_array(array, size);
	} free(new);
}
