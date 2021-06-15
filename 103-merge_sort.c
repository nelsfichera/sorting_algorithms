#include "sort.h"
/**
* merge_sort - sorts an array using merge sort algorithm
* @array: the array to sort
* @size: the size of the array
* Return: void
*/
void merge_sort(int *array, size_t size)
{
	int *copy;
	unsigned int x;

	copy = malloc(sizeof(int) * size);
	if (!copy)
		return;
	for (x = 0; x < size; x++)
		copy[x] = array[x];

	merge_split(copy, 0, size, array);
	free(copy);
}
/**
* merge_split - top down merge
* @copy: copy of the array
* @first: first value
* @last: last value
* @array: the array
* Return: void
*/
void merge_split(int *copy, int first, int last, int *array)
{
	int mid;

	if (last - first < 2)
		return;
	mid = (last + first) / 2;

	merge_split(array, first, mid, copy);
	merge_split(array, mid, last, copy);
	merge_execute(copy, first, mid, last, array);
}
/**
* merge_execute - executes the merge with printing
* @array: the array
* @first: the first value
* @mid: the middle value
* @last: last value
* @copy: copy of the array
* Return: void
*/
void merge_execute(int array[], int first, int mid, int last, int copy[])
{
	int x, n, a;

	x = first;
	n = mid;

	if (array)
	{
		printf("Merging...\n");
		printf("[left]: ");
		print_array(array + first, mid - first);
		printf("[right]: ");
		print_array(array + mid, last - mid);
	}
	for (a = first; a < last; a++)
	{
		if (x < mid && (n >= last || array[x] <= array[n]))
		{
			copy[a] = array[x];
			x++;
		}
		else
		{
			copy[a] = array[n];
			n++;
		}
	}
	printf("[Done]: ");
	print_array(copy + first, last - first);
}

