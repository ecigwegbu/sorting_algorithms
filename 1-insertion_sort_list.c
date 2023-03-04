#include <stdio.h>
#include "sort.h"

void do_insert(listint_t **list, listint_t **node);

/**
 * insertion_sort_list - sort a list using insertion sort algorithm
 * @list: double pointer to doubly-linked list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node = *list;

	/* null checks */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	printf("head: %d\n", (*list)->n);  /*debug */
	printf("node: %d\n", node->n);  /*debug */
	printf("------\n"); /* debug */
	printf("(*list)->next->n: %d\n", (*list)->next->n); /* debug */
	node = (*list)->next;  /* start checking from the second node */

	printf("?????\n"); /* debug */
	printf("head: %d\n", (*list)->n);  /*debug */
	printf("node: %d\n", node->n);  /*debug */
	printf("Entering loop...\n"); /* debug */
	while (node != NULL)
	{
		/* insert node in right place and */
		/* set ptr to the old ptr->next   */
		printf("Top Loop: Node: %d\n", node->n); /*debug*/
		print_list(*list); /* debug */
		do_insert(list, &node);
	}
	printf("After loop. Node: %p\n", (void *)node); /* debug */
}

/**
 * do_insert - insert a node in its sorted position
 * @list: double pointer to the head node of the doubly linked list
 * @node: double pointer to the node under consideration
 */

void do_insert(listint_t **list, listint_t **node)
{
	listint_t *nextNode, *ptr = (*node)->prev;
	
	printf("ptr (ie (*node)->prev: %d\n", ptr->n);
	printf("ptr->prev(NULL): %p\n", (void *) ptr->prev); /*debug */

	nextNode = (*node)->next; /* save this before any swaps */

	printf("Here-1 \t"); /* debug */
	printf("PTR-n0 %d \t", ptr->n); /* debug */
	printf("Node-n0 %d \n", (*node)->n); /* debug */
	if (nextNode)
		printf("nextNode: %d\n", nextNode->n); /* debug */
	else
		printf("nextNode: %p\n", (void *)nextNode); /* debug */
		

	/* check if swap needed */
	if ((*node)->n >= ptr->n)
	{
		printf("Swap not needed; returning...\n");  /* debug */
		(*node) = nextNode;
	}
	/* find insert poistion */
	printf("Here-1.5 \n Swap needed, searching for new ptr...\n"); /* debug */
	while ((ptr != NULL) && ((*node)->n < ptr->n))
	{
		print_list(*list);  /* debug */
		printf("Searching...\n"); /* debug */
		if (nextNode)
			printf("In-search: ptr: %d, node: %d, ptr-prev: %p, nextNode: %d\n", ptr->n, (*node)->n, (void *) ptr->prev, nextNode->n); /* debug */
		else
		{
			printf("*********In-search: ptr: %d, node: %d, nextNode: %p, ptr->prev: %p\n", ptr->n, (*node)->n, (void *) nextNode, (void *)ptr->prev); /* debug */
		printf("BEFORE ptr backoff: ptr: %d, ptr->prev: %d\n", ptr->n, ptr->prev->n); /* debug */
		}
		ptr = ptr->prev;
	if (ptr != NULL)  /* debug */
		printf("INSIDE LOOP: NEW PTR: %d \n", ptr->n); /* debug */
	else
		printf("INSIDE LOOP: NEW PTR: %p \n", (void *)ptr); /* debug */
	}
	printf("Search finished: \t"); /*debug */
	if (ptr != NULL)  /* debug */
		printf("NEW PTR: %d \n", ptr->n); /* debug */
	else
		printf("NEW PTR: %p \n", (void *)ptr); /* debug */

	if (ptr == NULL) /* insert at beginning */
	{
		printf("Here-2; Inserting at beginning... \n"); /* debug */
		/* detach node from old neighbour nodes */
		(*node)->prev->next = nextNode;
		if (nextNode != NULL)
			nextNode->prev = (*node)->prev;
		/* attach node at beginning */
		(*node)->prev = NULL;
		(*node)->next = *list;
		/* ALERT: need to reset head here !!!*/
		*list = *node;  /* may not be enough :( */
		(*node) = nextNode;  /*debug */
		print_list(*list);  /* debug */
		printf("...done\n"); /* debug */
	}
	else /* insert after ptr */
	{



		printf("Here-3: Next:detach node first \n"); /* debug */
		print_list(*list); /* debug */
		printf("PTR-b4Swap %d \t", ptr->n); /* debug */
		printf("Node-b4Swap %d \n", (*node)->n); /* debug */
		/* detach node from old neighbour nodes */

		(*node)->prev->next = nextNode;
		if (nextNode != NULL)
			nextNode->prev = (*node)->prev;

		printf("Here-4: node detatched: \n"); /* debug */
		print_list(*list); /* debug */
		printf("PTR-n4 %d \t", ptr->n); /* debug */
		printf("Node-n4 %d \n", (*node)->n); /* debug */
		/* attach node to new neighbour nodes */
		printf("Finally Here-: next insert node in new posn: \n"); /* debug */
		(*node)->next = ptr->next;
		ptr->next = (*node);
		(*node)->next->prev = (*node);
		(*node)->prev = ptr;
		printf("Here-5: swap done: \n"); /* debug */
		print_list(*list); /* debug */
	}


	printf("Here-6 \n"); /* debug */
	(*node) = nextNode;
}
