#include <stdio.h>
#include "sort.h"

void q_sort(int *array, ssize_t start_indx, ssize_t end_indx, size_t size);
ssize_t q_part(int *array, ssize_t start_indx, ssize_t end_indx, size_t size);

/**
 * quick_sort - sorting algorithm using quick sort and lomuto parti'n scheme
 * @array: array of integers to sort
 * @size: the number of elements of the array
 */

void quick_sort(int *array, size_t size)
{
	ssize_t start_indx = 0, end_indx = (ssize_t)size - 1;

	/* NULL check */
	if (array == NULL)
		return;

	q_sort(array, start_indx, end_indx, size);
}

/**
 * q_sort - quick sort helper function
 * @array: array to sort
 * @start_indx: starting index
 * @size: the size of the array
 * @end_indx: ending index
 */
void q_sort(int *array, ssize_t start_indx, ssize_t end_indx, size_t size)
/* based on the demo as presented by Bro Code (YouTube) */
{
	ssize_t pivot;

	if (end_indx <= start_indx)
		return; /* base case */

	/* Now recursively call q-sort of the part and qsort functions */
	pivot = q_part(array, start_indx, end_indx, size);
	q_sort(array, start_indx, pivot - 1, size);
	q_sort(array, pivot + 1, end_indx, size);
}

/**
 * q_part - quick sort partitioning helper function
 * @array: array to sort
 * @start_indx: starting index
 * @end_indx: ending index
 * @size: the size of the array
 * Return: the pivot location
 */
ssize_t q_part(int *array, ssize_t start_indx, ssize_t end_indx, size_t size)
{
	int pivot = array[end_indx], temp;
	ssize_t i = start_indx - 1, j;

	/*for (j = start_indx; j <= end_indx - 1; j++)  */
	for (j = start_indx; j <= end_indx; j++)
	{
		/* swap array i,j */
		if (array[j] < pivot) /* check if swapping needed */
		{
			i++; /* i_index box */
			/* swap array i, j */
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			/* print_array(array, size);  display result of swap */
		}
	}
	/* move i to determine the final restin place of the pivot: */
	i++;  /* move i_index box once j reaches the pivot; */
	/* then swap array i, j, thus placing the pivot in its final place */
	temp = array[i];
	array[i] = array[end_indx];
	array[end_indx] = temp;
	print_array(array, size);  /*display result of swap */

	return (i);  /* i is the pivot location; use to split array into 2 */
}
