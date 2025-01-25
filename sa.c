// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
// #include "push_swap.h"


#include "push_swap.h"


t_stack *sa(t_stack *stack_a)
{
	int tmp2 = stack_a->data;
	stack_a->data = stack_a->next->data;
	stack_a->next->data = tmp2;


	write (1, "sa\n", 3);
	return(stack_a);
}