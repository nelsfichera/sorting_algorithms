#include "sort.h"
/**
* counting_sort - sorts with counting method
* @array: pointer to array
* @size: the size of the array
* Return: v0id
*/
void counting_sort(int *array, size_t size)
{
	int max, position, *count = NULL, *sorted = NULL;
	size_t x;

	if (size < 2 || !array)
		return;
	max = array[0];
	for (x = 0; x < size; x++)
		if (array[x] > max)
			max = array[x];
	count = malloc(sizeof(int) * (max + 1));
	for (x = 0; x <= (size_t)max; x++)
		count[x] = 0;
	for (x = 0; x < size; x++)
		count[array[x]] = count[array[x]] + 1;
	for (x = 1; x <= (size_t)max; x++)
		count[x] = count[x] + count[x - 1];
	print_array(count, (size_t)max + 1);
	sorted = malloc(sizeof(int) * size);
	for (x = 0; x < size; x++)
	{
		count[array[x]] = count[array[x]] - 1;
		position = count[array[x]];
		sorted[position] = array[x];
	}
	for (x = 0; x < size; x++)
		array[x] = sorted[x];
	free(count);
	free(sorted);
}
