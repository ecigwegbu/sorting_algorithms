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
	int temp;

	for (i = 0; i < (size - 1); i++)  /* i is starting cell */
	/* i is starting cell; ending cell will be (size - i - 1) */
	{
		printf("i: %lu\n", i);
		if (1)
		{
			/* try swap */
			for (j = 0; j < size - 1 - i; j++)
			/* j is swap cell */
			{
				/* now swap cells */
				if (array[j + 1] < array[j])
				{
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
					/* swap = 0; */
					print_array(array, size);
				}
			}


		}
	}
}
