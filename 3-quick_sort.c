#include "sort.h"
/**
* quick_sort - sort an array into ascending order
* using the quicksort algorithm, must use lomuto partition scheme
* @array: the array to be sorted
* @size: size of the array
* Return: v0id
*/
void quick_sort(int *array, size_t size)
{
	execute(array, size, size, array);
}
/**
* execute - executes quicksort
* @array: array to sort
* @size: size of the array
* @total_size: total size of the array
* @aux: pointer to the beginning of the array
* Return: v0id
*/
void execute(int *array, size_t size, size_t total_size, int *aux)
{
	unsigned int pivot = 0;

	if (size > 1)
	{
		pivot = partition(array, pivot, size - 1, aux, total_size);
		if (pivot)
			execute(array, pivot++, total_size, aux);
		execute(array + pivot, size - pivot, total_size, aux);
	}
}
/**
* partition - lomuto partition
* @array: the array to sort
* @low: the lower limit
* @high: the upper limit
* @aux: start of the array pointer
* @size: the size of the array
* Return: index of the pivot
*/
size_t partition(int *array, size_t low, size_t high, int *aux, size_t size)
{
	int swap = 0, pivot = array[high];
	size_t x = low, n = low;

	for (n = low; n < high; n++)
		if (array[n] < pivot)
		{
			if (array[n] != array[x])
			{
				swap = array[n];
				array[n] = array[x];
				array[x] = swap;
				print_array(aux, size);
			}
			x++;
		}
	if (array[n] == array[x])
		return (n);
	if (array[x] != array[high])
	{
		swap = array[high];
		array[high] = array[x];
		array[x] = swap;
		print_array(aux, size);
	}
	return (x);
}


