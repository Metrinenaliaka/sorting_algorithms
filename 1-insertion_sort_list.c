#include "sort.h"
/**
 * insertion_sort_list - insertion sort algorithm
 * @list: ppointer to head node
 *
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *temp, *swap, *new;

	head = *list;
	temp = head->next;
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (temp)
	{
		new = temp->next;
		while (head && temp->n < head->n)
		{
			if (head->prev)
				head->prev->next = temp;
			else
				*list = temp;
			if (temp->next)
				temp->next->prev = head;
			swap = temp->next;
			temp->next = head;
			temp->prev = head->prev;
			head->next = swap;
			head->prev = temp;
			print_list(*list);
			head = temp->prev;

		}
		temp = new;
		if (temp)
			head = temp->prev;
	}
}
