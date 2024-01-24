#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void swap(listint_t **head, listint_t *node1, listint_t *node2);

/**
 * insertion_sort - implements insertion sorting algorithm
 * on doubly linked list
 * @list: list to be sorted
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (i = (*list)->next; i && i->prev; i = i->next)
	{
		for (; i && i->prev && i->n < i->prev->n;
				i = i->prev)
		{
			j = i->prev;
			swap(list, j, i);
			print_list(*list);
			i = i->next;
		}
	}
}

/**
 * swap - swap two nodes in list
 * @head: head of list
 * @node1: the first node
 * @node2: the second node
 * Return:nothing
 */
void swap(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *tmp_p, *tmp_n;

	tmp_p = node1->prev;
	tmp_n = node2->next;

	if (tmp_p != NULL)
		tmp_p->next = node2;
	else
		*head = node2;

	node1->prev = node2;
	node1->next = tmp_n;
	node2->prev = tmp_p;
	node2->next = node1;
	if (tmp_n)
		tmp_n->prev = node1;
}
