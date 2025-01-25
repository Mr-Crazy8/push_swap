// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.

#include "push_swap.h"

void pb(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;

    if (!(*stack_a)) 
        return;
    tmp = *stack_a;
    *stack_a = (*stack_a)->next;
    tmp->next = *stack_b;
    *stack_b = tmp;
    write(1, "pb\n", 3);
}