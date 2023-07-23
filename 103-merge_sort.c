#include "sort.h"

/**
 * merge -> Merges two subarrays of array
 * @array: Array Integers
 * @size: Array's size
 * @l: Array's left side
 * @r: Array's right side
 **/

void merge(int *array, int *l, int *r, size_t size)
{
	int i = 0, j = 0, k = 0;
	int L, R;

	L = size / 2;
	R = size - L;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(l, L);
	printf("[right]: ");
	print_array(r, R);

	while (i < L && j < R)
	{
		if (l[i] < r[j])
			array[k++] = l[i++];
		else
			array[k++] = r[j++];
	}
	while (i < L)
		array[k++] = l[i++];

	while (j < R)
		array[k++] = r[j++];
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort -> Sorts an array of integers in ascending order
 * @array: Array Integers
 * @size: Array's size
 **/

void merge_sort(int *array, size_t size)
{
	size_t m = 0, i;
	int left[1000];
	int right[1000];

	if (!array)
		return;
	if (size < 2)
		return;
	m = size / 2;
	for (i = 0; i < m; i++)
		left[i] = array[i];
	for (i = m; i < size; i++)
		right[i - m] = array[i];
	merge_sort(left, m);
	merge_sort(right, size - m);
	merge(array, left, right, size);
}
