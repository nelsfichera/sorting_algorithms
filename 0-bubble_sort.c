#include "sort.h"
/**
* bubble_sort - sort an array into ascending
* order using the bubble sort algorithm
* @array: the array to be sorted
* @size: the size of the array
* Return: v0id
*/
void bubble_sort(int *array, size_t size)
{
	unsigned int x, swap = 1;
	int temp;

	if (size < 2)
		return;

	while (swap)
	{
		swap = 0;
		for (x = 1; x < size; x++)
			if (array[x - 1] > array[x])
			{
				temp = array[x - 1];
				array[x - 1] = array[x];
				array[x] = temp;
				print_array(array, size);
				swap = 1;
			}
	}
}
