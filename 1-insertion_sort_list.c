#include "sort.h"


/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: the list to be sorted
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *node = NULL, *p_node = NULL, *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;
	current = current->next;

	while (current)
	{
		node = current;
		while (node->prev && (node->n < node->prev->n))
		{
			if (node->next)
				node->next->prev = node->prev;

			node->prev->next = node->next;
			node->next = node->prev;

			p_node = node->prev;
			node->prev = p_node->prev;
			if (p_node->prev)
				p_node->prev->next = node;
			p_node->prev = node;

			if (node->prev == NULL)
				*list = node;
			print_list(*list);
		}

		current = current->next;
	}


}
