// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.

#include "push_swap.h"



t_stack *sb(t_stack *stack_b)
{
	int tmp2 = stack_b->data;
	stack_b->data = stack_b->next->data;
	stack_b->next->data = tmp2;


	write(1, "sb\n", 3);
	return(stack_b);
}