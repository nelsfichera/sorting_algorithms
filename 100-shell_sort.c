#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the Shell
 * sort algorithm, using the Knuth sequence
 * @array: array to be sorted
 * @size: size of the array
 *
 */
void shell_sort(int *array, size_t size)
{
	size_t x, n, interval = 1;
	int value;

	if (array == NULL || size < 2)
		return;

	while (interval < size / 3)
	{
		interval = interval * 3 + 1;
	}
	while (interval > 0)
	{
		for (x = interval; x < size; x++)
		{
			value = array[x];
			for (n = x; n >= interval && array[n - interval] >
				value; n = n - interval)
			{
				array[n] = array[n - interval];
			}
			array[n] = value;
		}
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}
