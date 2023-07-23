#include "sort.h"

/**
 * swap -> Swap two elements
 * @arr: Array
 * @item1: First Item
 * @item2: Second Item
 * @order: 1: Ascending Order, 0 Descending Order
 */

void swap(int arr[], int item1, int item2, int order)
{
	int i;

	if (order == (arr[item1] > arr[item2]))
	{
		i = arr[item1];
		arr[item1] = arr[item2];
		arr[item2] = i;
	}
}

/**
 * merge -> Sorts an array of integers in ascending order
 * @arr: Array
 * @low: First Element
 * @nelemnt: Number Elements
 * @order: 1: Ascending Order, 0 Descending Order
 */

void merge(int arr[], int low, int nelemnt, int order)
{
	int m, i;

	if (nelemnt > 1)
	{
		m = nelemnt / 2;
		for (i = low; i < low + m; i++)
			swap(arr, i, i + m, order);
		merge(arr, low, m, order);
		merge(arr, low + m, m, order);
	}
}

/**
 * bitonicsort -> Sorts an array of integers in ascending order
 * @arr: Array
 * @low: First Element
 * @nelemnt: Elements Number
 * @order: 1: Ascending Order, 0 Descending Order
 * @size: List's size
 */

void bitonicsort(int arr[], int low, int nelemnt, int order, int size)
{
	int m;

	if (nelemnt > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		} m = nelemnt / 2;
		bitonicsort(arr, low, m, 1, size);
		bitonicsort(arr, low + m, m, 0, size);
		merge(arr, low, nelemnt, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
	}
}

/**
 * bitonic_sort -> Sorts integers array in ascending order
 * @array: Array
 * @size: List's size
 */

void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	bitonicsort(array, 0, size, order, size);
}
