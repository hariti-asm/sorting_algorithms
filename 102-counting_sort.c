#include "sort.h"

/**
 * counting_sort -> Sorts integers array in ascending order
 * @array: Array Integers
 * @size: Array's size
 **/

void counting_sort(int *array, size_t size)
{
	int n, j, *a, *count;
	size_t i;

	if (!array || size < 2)
		return;
	n = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > n)
			n = array[i];
	} count = calloc((n + 1), sizeof(int));
	for (i = 0; i < size; i++)
	{
		count[array[i]]++;
	}
	for (j = 1; j < n; j++)
	{
		count[j + 1] += count[j];
	} print_array(count, n + 1);
	a = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
	{
		count[array[i]]--;
		a[count[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
	{
		array[i] = a[i];
	} free(a);
	free(count);
}
