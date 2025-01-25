//rb (rotate b): Shift up all elements of stack b by 1.
//The first element becomes the last one.

///here
#include "push_swap.h"

#include <libc.h>


void rb(t_stack **stack_b)
{
	

	t_stack *lst = *stack_b;
	t_stack *tmp = *stack_b;

	*stack_b = tmp->next;

	if (*stack_b == NULL || stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = tmp;
	tmp->next = NULL;
}

