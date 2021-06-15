#include "sort.h"
/**
* heap_sort - sorts an array using heap algo
* @array: the array
* @size: size of the array
* Return: void
*/
void heap_sort(int *array, size_t size)
{
	size_t end = size - 1, start;

	if (size < 2)
		return;
	for (start = (size - 2) / 2; (int) start >= 0; start--)
		heap_sift(array, size, start, size - 1);
	while (end > 0)
	{
		swap_nodes(&array, end, 0);
		print_array(array, size);
		end--;
		heap_sift(array, size, 0, end);
	}
}
/**
* heap_sift - sifts the array
* @array: the array
* @size: size of array
* @start: start index
* @end: end index
* Return: void
*/
void heap_sift(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start, child, swap;

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap == root)
		{
			return;
		}
		else
		{
			swap_nodes(&array, root, swap);
			print_array(array, size);
			root = swap;
		}
	}
}
/**
* swap_nodes - swaps 2 values in an array
* @array: the array
* @index1: first index
* @index2: second index
* Return: swapped array
*/
void swap_nodes(int **array, ssize_t index1, ssize_t index2)
{
	int temp;

	temp = (*array)[index1];
	(*array)[index1] = (*array)[index2];
	(*array)[index2] = temp;
}
