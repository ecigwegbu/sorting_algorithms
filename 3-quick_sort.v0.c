#include <stdio.h>
#include "sort.h"

void q_sort(int *array, size_t start_indx, size_t end_indx);
size_t q_part(int *array, size_t start_indx, size_t end_indx);

/**
 * quick_sort - sorting algorithm using quick sort and lomuto parti'n scheme
 * @array: array of integers to sort
 * @size: the number of elements of the array
 */
void quick_sort(int *array, size_t size)
{
	size_t start_indx = 0, end_indx = size - 1;

	q_sort(array, start_indx, end_indx);
}

/**
 * q_sort - quick sort helper function
 * @array: array to sort
 * @start_indx: starting index
 * @end_indx: ending index
 */
void q_sort(int *array, size_t start_indx, size_t end_indx)
{
	size_t pivot;

	if (end_indx <= start_indx)
		return; /* base case */

	pivot = q_part(array, start_indx, end_indx);
	q_sort(array, start_indx, pivot - 1);
	q_sort(array, pivot + 1, end_indx);


}

/**
 * q_part - quick sort partitioning helper function
 * @array: array to sort
 * @start_indx: starting index
 * @end_indx: ending index
 * Return: the pivot location
 */
size_t q_part(int *array, size_t start_indx, size_t end_indx)
{
	int pivot = array[end_indx], temp;
	size_t i = start_indx - 1, j;

	for (j = start_indx; j <= end_indx - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	i++;
	temp = array[i];
	array[i] = array[end_indx];
	array[end_indx] = temp;

	return (i);
}
