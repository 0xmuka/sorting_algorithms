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
int tmp = array[element1];
array[element1] = array[element2];
array[element2] = tmp;
}

/**
 * partition - partitions the array using the Hoare scheme
 * @array: the array to be partitioned
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array
 *
 * Return: index of the pivot element after partitioning
 */
int partition(int *array, int low, int high, int size)
{
int pivot = array[high];
int i = low - 1, j = high + 1;

while (1)
{
do {
i++;
} while (array[i] < pivot);

do {
j--;
} while (array[j] > pivot);

if (i >= j)
return (j);

swap(array, i, j);
print_array(array, size);
}
}

/**
* quick_sort_helper - recursive helper function for quick sort
* @array: the array to be sorted
* @low: starting index of the partition
* @high: ending index of the partition
* @size: size of the array
*/
void quick_sort_helper(int *array, ssize_t low, ssize_t high, size_t size)
{
ssize_t pivot = 0;

if (low < high)
{
pivot = partition(array, low, high, size);
quick_sort_helper(array, low, pivot - 1, size);
quick_sort_helper(array, pivot + 1, high, size);
}
}

/**
* quick_sort_hoare - sorts an array of integers using the quick sort algorithm
* @array: the array to be sorted
* @size: size of the array
*/
void quick_sort_hoare(int *array, size_t size)
{
if (!array || size < 2)
return;

quick_sort_helper(array, 0, size - 1, size);
}

