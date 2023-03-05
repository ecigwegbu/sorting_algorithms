#include <stdio.h>
#include "sort.h"

void do_insert(listint_t **list, listint_t **node);

/**
 * insertion_sort_list - sort a list using insertion sort algorithm
 * @list: double pointer to doubly-linked list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node = NULL;

	/* null checks */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	node = (*list)->next;  /* start checking from the second node */
	while (node != NULL)
		/* insert node in right place and */
		/* set ptr to the old ptr->next   */
		do_insert(list, &node);
}

/**
 * do_insert - insert a node in its sorted position
 * @list: double pointer to the head node of the doubly linked list
 * @node: double pointer to the node under consideration
 */

void do_insert(listint_t **list, listint_t **node)
{
	listint_t *nextNode, *ptr;

	ptr = (*node)->prev;

	nextNode = (*node)->next; /* save this before any swaps */


	/* check if swap needed */
	if ((*node)->n >= ptr->n)
	{
		(*node) = nextNode;
		return;
	}
	/* find insert poistion */
	while ((ptr != NULL) && ((*node)->n < ptr->n))
		ptr = ptr->prev;

	if (ptr == NULL) /* insert at beginning */
	{
		/* detach node from old neighbour nodes */
		(*node)->prev->next = nextNode;
		if (nextNode != NULL)
			nextNode->prev = (*node)->prev;
		/* attach node at beginning */
		(*node)->prev = NULL;
		(*node)->next = *list;
		(*list)->prev = (*node); /* nasty bug!!!???? */

		*list = *node;  /* reset head pointer */
		(*node) = nextNode;  /*reset node */
		print_list(*list);  /* debug */
	}
	else /* insert after ptr */
	{
		/* detach node from old neighbour nodes */
		(*node)->prev->next = nextNode;
		if (nextNode != NULL)
			nextNode->prev = (*node)->prev;

		/* attach node to new neighbour nodes */
		(*node)->next = ptr->next;
		ptr->next = (*node);
		(*node)->next->prev = (*node);
		(*node)->prev = ptr;

		(*node) = nextNode;
		print_list(*list); /* debug */
	}
}
