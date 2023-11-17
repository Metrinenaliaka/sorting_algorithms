#include "sort.h"
/**
 * bubble_sort - bubblesort function
 * @array: array to be sorted
 * @size: size or array
 * Return: None
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j, temp;
	bool swap = false;

	if (size < 2 || !array)
		return;
	do {
		swap = false;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap = true;
				print_array(array, size);
			}
		}
		i++;
	} while (swap);
}
