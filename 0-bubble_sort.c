#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - bubble sort function to sort an array of integers
 * @array: array of integers
 * @size: number of elements in the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swap = 1;

	for (i = 0; i < (size - 1) && swap; i++)  /* i is starting cell */
	/* i is starting cell; ending cell will be (size - 1 - i) */
	{
		/* try swap */
		swap = 0; /* reset swap indicator */
		for (j = 0; j < size - 1 - i; j++)
		/* j is swap cell */
		{
			/* now swap cells */
			if (array[j + 1] < array[j])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap = 1;
				print_array(array, size);
			}
		}
	}
}
