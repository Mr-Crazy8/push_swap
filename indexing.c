#include "push_swap.h"

int  find_min(t_stack *haed)
{
	t_stack *tmp;
	tmp = haed;
	int nbr = INT_MAX;
	static int last_min = 0;
	while (tmp)
	{
		if(tmp->index == -1 && tmp->data < nbr)
			nbr = tmp->data;
		tmp = tmp->next;
	}
	return nbr;
}

void first_index(t_stack *head)
{
	t_stack *tmp = head;
	while (tmp) {
		tmp->index = -1;
		tmp = tmp->next;
	}
	
}

void second_index(t_stack *head)
{
	t_stack *tmp;
	int index = 0;
	
	int min;

	while (1)
	{
		min = find_min(head);

		if (min == INT_MAX)
			break;
		tmp = head;
		while (tmp)
		{
			if (tmp->index == -1 && tmp->data == min)
				tmp->index = index;
		tmp = tmp->next;
		}
		index++;
	}

}

