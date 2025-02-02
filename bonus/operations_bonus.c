/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:02:12 by anel-men          #+#    #+#             */
/*   Updated: 2025/01/27 16:02:14 by anel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
// #include <unistd.h>
// #include <stdio.h>

void	rrb(t_stack **stack_b)
{
	t_stack	*lst;
	t_stack	*tmp;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	lst = *stack_b;
	tmp = *stack_b;
	while (lst->next != NULL)
		lst = lst->next;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	lst->next = *stack_b;
	*stack_b = lst;
	tmp->next = NULL;
	// write(1, "rrb\n", 4);
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*tmp;

	if (!(*stack_b))
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	// write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	// write(1, "pb\n", 3);
}

void	ra(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	*stack_a = first->next;
	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	// write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL
		|| ft_list_size(*stack_b) < 2)
		return ;
	first = *stack_b;
	*stack_b = first->next;
	last = *stack_b;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
	// write(1, "rb\n", 3);
}

void	sa(t_stack **stack_a)
{
	int	tmp2;

	tmp2 = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->next->data = tmp2;
	// write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	int	tmp2;

	tmp2 = (*stack_b)->data;
	(*stack_b)->data = (*stack_b)->next->data;
	(*stack_b)->next->data = tmp2;
	// write(1, "sa\n", 3);
}
void 	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);

}
void rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

void	rra(t_stack **stack_a)
{
	t_stack	*lst;
	t_stack	*tmp;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	lst = *stack_a;
	tmp = *stack_a;
	while (lst->next != NULL)
		lst = lst->next;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	lst->next = (*stack_a);
	*stack_a = lst;
	tmp->next = NULL;
	// write(1, "rra\n", 4);
}