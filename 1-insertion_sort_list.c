#include <stdio.h>
#include "sort.h"

void swap_first(listint_t *head);

/**
 * insertion_sort_list - sort a list using insertion sort algorithm
 * @list: double pointer to doubly-linked list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head; /*, *tail, *last_sorted, *ins_next, *tmp; */

	printf("Address of head: %p\n", (void *) *list);

	/* handle NULL/trivial  edge case */
	if (list == NULL || *list == NULL)
		return;
	head = *list;
	
	/* do first two nodes */
	if (head->next != NULL && head->next->n < head->n)
		swap_first(head);
	head = head->prev;


	printf("Address of head: %p\n", (void *) *list);
	print_list(head);
}


/**
 * swap_first - swap first and second nodes
 * @head: pointer to head node of doubly linked list
 */

void swap_first(listint_t *head)
{
	listint_t *ins_next, *tmp;

	if (head->next->next == NULL)
	{
		head = head->next;
		head->next = head->prev;
		head->next->next = NULL;
		head->prev = NULL;
		head->next->prev = head;
	}
	else
	{
		printf("Why?\n"); /* debug */
		ins_next = head->next->next;
		tmp = head;
		head = head->next;
		head->prev = NULL;
		tmp->prev = head;
		ins_next->prev = tmp;
		head->next = tmp;
		tmp->next = ins_next;
		print_list(head);
	}
}
