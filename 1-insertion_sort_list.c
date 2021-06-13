#include "sort.h"
/**
* insertion_sort_list - use insertion sort to sort
* doubly linked list into ascending order
* @list: the doubly linked list to sort
* Return: void
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *previous = NULL, *aux = NULL;

	if (list)
	{
		previous = *list;
		current = previous->next;
		while (current)
		{
			aux = previous;
			if (current->n < previous->n)
			{
				aux = previous;
				while (previous && previous->n  > current->n)
				{
					previous->next = current->next;
					if (current->next)
						current->next->prev = previous;
					previous = previous->prev;
					if (previous)
					{
						current->next = previous->next;
						previous->next = current;
						current->prev = previous;
					}
					else
					{
						current->next = *list;
						current->prev = NULL;
						*list = current;
					}
					if (current->next)
						current->next->prev = current;
					print_list(*list);
				}
				current = aux, previous = current->prev;
			}
			current = current->next, previous = previous->next;
		}
	}
}
