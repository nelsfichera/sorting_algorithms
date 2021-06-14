#include "sort.h"

/**
* swap_forward - swaps two nodes forward
* @current: the current node
* @list: head of list
* Return: 1
*/
int swap_forward(listint_t *current, listint_t **list)
{
	listint_t *scout = NULL;

	scout = current->next;
	scout->prev = current->prev;

	if (current->prev)
		current->prev->next = scout;
	else
		*list = current->next;
	current->next = scout->next;
	current->prev = scout;
	scout->next = current;
	if (current->next)
		current->next->prev = current;
	print_list(*list);
	return (1);
}

/**
* swap_backward - swaps two nodes forward
* @current: the current node
* @list: head of list
* Return: 1
*/
int swap_backward(listint_t *current, listint_t **list)
{
	listint_t *scout = NULL;

	scout = current->prev;

	scout->next = current->next;
	current->next->prev = scout;

	current->prev = scout->prev;
	current->next = scout;
	scout->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	print_list(*list);
	return (1);
}
/**
* cocktail_sort_list - sort list with cocktail method
* @list: pointer to head of list
* Return: void
*/
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = NULL;
	int swap = 1;

	if (list)
	{
		current = *list;
		while (swap)
		{
			swap = 0;
			while (current->next)
			{
				if (current->n > current->next->n)
				{
					swap = swap_forward(current, list);
					continue;
				}
				current = current->next;
			}
			if (!swap)
				break;
			swap = 0;
			while (current->prev)
			{
				if (current->n < current->prev->n)
				{
					swap = swap_backward(current, list);
					continue;
				}
				current = current->prev;
			}
		}
	}
}
