#include <stdio.h>
#include "sort.h"
#include <unistd.h>

/**
 * swap - swaps the positions of two elements in an array
 * @array: the array
 * @element1: index of the first element
 * @element2: index of the second element
 */
void swap(int *array, ssize_t element1, ssize_t element2)
{
int tmp;

tmp = array[element1];
array[element1] = array[element2];
array[element2] = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme implementation
 * @array: the array
 * @low: index of the lower bound of the partition
 * @high: index of the upper bound of the partition
 * @size: size of the array
 * Return: index of the pivot element after partitioning
 */
int lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
int pivot = array[high];
ssize_t current = low;

ssize_t i;
for (i = low; i < high; i++)
{
if (array[i] < pivot)
{
if (array[current] != array[i])
{
swap(array, current, i);
print_array(array, size);
}
current++;
}
}

if (array[current] != array[high])
{
swap(array, current, high);
print_array(array, size);
}

return (current);
}

/**
* quick_sort_helper - recursive helper function for quick sort
* @array: the array
* @low: index of the lower bound of the partition
* @high: index of the upper bound of the partition
* @size: size of the array
*/
void quick_sort_helper(int *array, ssize_t low, ssize_t high, size_t size)
{
if (low < high)
{
ssize_t pivot = lomuto_partition(array, low, high, size);
quick_sort_helper(array, low, pivot - 1, size);
quick_sort_helper(array, pivot + 1, high, size);
}
}

/**
* quick_sort - sorts an array of integers in ascending order using quick sort
* @array: the array to sort
* @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
if (!array || size < 2)
	return;

quick_sort_helper(array, 0, size - 1, size);
}

