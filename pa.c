// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty

#include "push_swap.h"

void pa(t_stack **stack_b, t_stack **stack_a)
{
	t_stack *tmp;
	if (!stack_b || !(*stack_b)) 
        return;
	tmp = *stack_b;
	*stack_b = (*stack_b)->data;
	tmp->next = *stack_a;
	*stack_a = tmp;

}

