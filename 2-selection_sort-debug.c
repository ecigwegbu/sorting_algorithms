#include <stdio.h>
#include "sort.h"

size_t get_min(int *array, size_t size, size_t start);
void move_elt(int *array, size_t given_indx, size_t before_indx);

/**
 * insertion_sort_list - sort a list using insertion sort algorithm
 * @list: double pointer to doubly-linked list to sort
 */

void selection_sort(int *array, size_t size)
{
	size_t node; /* the index of the element under consideration */
	/* It is the node before which the smallest value will be moved */
	size_t min_indx;

	/* Array size must be at least 2 before proceding*/
	if (size < 2)
		return;

	node = 0;  /* start processing from first node */

	printf ("Process all nodes...\n");
	/* find smlst node starting from node, move it b4 node; for all nodes*/
	for (node = 0; node < size -1; node ++)
	{	
		printf ("Search for min\n");
		/* find min node */
		min_indx = get_min(array, size, node);

		printf ("Min found\n");
	printf ("min_indx: %lu; ", min_indx);  /* debug */
	printf ("min elt: %d\n", array[min_indx]);  /*debug */
		/* move elt at min_indx to just before node */
		if (min_indx == node) /* all remaining elements are sorted */
		{
			printf ("min_indx: %lu, node: %lu, Skipping move...\n", min_indx, node);
			continue;
		}
		move_elt(array, min_indx, node); 
		print_array(array, size);
	}
}

/**
 * get_min - get the smallest value from given node to array end
 * @array: array of integers
 * @size: size of the array
 * @start: starting node
 * @Return: the index of the node with minimum value
 */
size_t get_min(int *array, size_t size, size_t start)
{
	size_t indx, min_indx;
	int min;  /* min value at min_indx */

	printf ("Inside get_min....\n");
	min = array[start];   /* initialise min before iterating */
	min_indx = start;
	printf("size: %lu, start: %lu, initial min: %d\n", size, start, min);
	for (indx = start; indx < size; indx++) /* scan from start to end */
	{
		printf ("Scanning elts ...\n");
		if (array[indx] < min)
		{
			min = array[indx];
			min_indx = indx;
		}
	}
	return (min_indx);	
}

/**
 * move_elt - move an element leftwards to a desired position in an array
 * @array: array of integers
 * @given_indx: the index of the element to move
 * @before_indx: the index of the element before which to insert given index
 */
void move_elt(int *array, size_t given_indx, size_t before_indx)
{
	int temp;
	size_t j;

	printf("moving elt...\n");
	temp = array[given_indx];

	for (j = given_indx; j >= before_indx + 1; j--)
		array[j] = array[j - 1];
	array[before_indx] = temp;
}
