#include <stdio.h>
#include "sort.h"

void do_swaps(listint_t **list, listint_t **node);

/**
 * insertion_sort_list - sort a list using insertion sort algorithm
 * @list: double pointer to doubly-linked list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node = NULL, *nextNode;

	/* null checks: at least 2 nodes must be present before proceding*/
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	node = (*list)->next;  /* start checking from the second node */
	while (node != NULL) /* swap node left until it fits; do to list end*/
	{
		nextNode = node->next; /* save next node before any swaps */
		while (node->prev && (node->n < node->prev->n))
		{
			/*swap node and node->prev */
			do_swaps(list, &node);
			print_list(*list);
		}
		node = nextNode; /* reset node */
	}
}

/**
 * do_swaps - swap nodes until node is in the right place
 * @list: double pointer to doubly-linked list to sort
 * @node: double pointer to node being processed
 */

void do_swaps(listint_t **list, listint_t **node)
{
	listint_t *ptr = (*node)->prev->prev, *nextNode = (*node)->next;

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
		/*(*node) = nextNode;  reset node */
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

		/*(*node) = nextNode;*/
	}
}
