//rrb (reverse rotate b): Shift down all elements of stack b by 1.
//The last element becomes the first one.
///here
#include "push_swap.h"



void rrb(t_stack **stack_b)
{
    if (!(*stack_b) || !stack_b || !(*stack_b)->next)
        return;

    t_stack *lst = *stack_b;
    t_stack *tmp = *stack_b;

    while (lst->next != NULL)
        lst = lst->next;

    while (tmp->next->next != NULL)
        tmp = tmp->next;
    lst->next = *stack_b;
    *stack_b = lst;
    tmp->next = NULL;
}