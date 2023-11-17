#include "sort.h"
/**
 * swapping - swaps elements at the index the pointer
 * is pointing to.
 * @x: pointer to first index
 * @y: ponter to last index
 *
 */
void swapping(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
/**
 * quick_sort - impliments quick sort lomuto partition
 * @array: array to be sorted
 * @size: size of array
 *
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	recursion(array, 0, (int)size - 1, size);
}
/**
 * recursion - sorts the array recursively
 * @array: array to be sorted
 * @low_ind: start index
 * @high_ind: end index
 * @size: size of array
 */
void recursion(int *array, int low_ind, int high_ind, size_t size)
{
	int pivot_ind;

	if (low_ind < high_ind)
	{
		pivot_ind = parts(array, low_ind, high_ind, size);
		recursion(array, low_ind, pivot_ind - 1, size);/*left portion of array*/
		recursion(array, pivot_ind + 1, high_ind, size);/*right portion of array*/
	}
}
/**
 * parts - searches for partition
 * @array: array to be partitioned
 * @low_ind: start index
 * @high_ind: end index
 * @size: size of array
 * Return: pivot index
 */
int parts(int *array, int low_ind, int high_ind, size_t size)
{
	int pivot_val, i, j;

	pivot_val = array[high_ind];
	i = low_ind;
	for (j = low_ind; j < high_ind; j++)
	{
		if (array[j] < pivot_val)
		{
			swapping(&array[i], &array[j]);
			if (array[i] != array[j])
				print_array(array, size);
			i++;
		}
	}
	/*place the pivot value at the index i*/
	swapping(&array[i], &array[high_ind]);
	if (array[i] != array[high_ind])
		print_array(array, size);
	return (i);
}
