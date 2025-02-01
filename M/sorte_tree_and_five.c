/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorte_tree_and_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:39:12 by anel-men          #+#    #+#             */
/*   Updated: 2025/01/31 17:39:15 by anel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	int	tmp2;

	tmp2 = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->next->data = tmp2;
	write(1, "sa\n", 3);
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
	write(1, "rra\n", 4);
}

void	check_if_sorted(t_stack *stack_a)
{
	if (!stack_a || !stack_a->next)
		return ;
	while (stack_a->next)
	{
		if (stack_a->data > stack_a->next->data)
			return ;
		stack_a = stack_a->next;
	}
	exit(0);
}

void	sort_tree(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	a = (*stack_a)->index;
	b = (*stack_a)->next->index;
	c = (*stack_a)->next->next->index;
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c)
		(sa(stack_a), rra(stack_a));
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
		(sa(stack_a), ra(stack_a));
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

void	sort_five(t_stack **stack_a)
{
	int		size;
	t_stack	*stack_b;

	stack_b = NULL;
	size = ft_list_size(*stack_a);
	while (size--)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			pb(stack_a, &stack_b);
		else
			ra(stack_a);
	}
	sort_tree(stack_a);
	pa(&stack_b, stack_a);
	pa(&stack_b, stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}
