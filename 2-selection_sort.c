#include "sort.h"
/**
* selection_sort - sort an array into ascending order
* using selection sort algorithm
* @array: the array to sort
* @size: the size of the array
* Return: void
*/
void selection_sort(int *array, size_t size)
{
	unsigned int x = 0, n = 0, idx = 0;
	int swap;

	for (x = 0; x < size - 1; x++)
	{
		idx = 1;

		for (n = x + 1; n < size; n++)
			if (array[n] < array[idx])
				idx = n;
		if (idx != x)
		{
			swap = array[x];
			array[x] = array[idx];
			array[idx] = swap;
			print_array(array, size);
		}
	}
}
