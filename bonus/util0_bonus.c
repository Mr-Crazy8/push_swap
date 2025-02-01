/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:00:37 by anel-men          #+#    #+#             */
/*   Updated: 2025/01/27 16:00:43 by anel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	range_finder(t_stack *head)
{
	int	size;
	int	range;

	size = ft_list_size(head);
	if (size > 100)
		range = 39;
	else if (size <= 100)
		range = 11;
	return (range);
}

int	find_max(t_stack *stack_b)
{
	int		max;
	t_stack	*tmp;

	if (!stack_b)
		return (INT_MIN);
	max = stack_b->data;
	tmp = stack_b->next;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

int	from_last_to_max(t_stack *stack_b, int index)
{
	t_stack	*lst;
	t_stack	*tmp;
	int		i;
	int		j;

	lst = stack_b;
	i = 0;
	j = 0;
	while (lst && lst->index != index)
	{
		i++;
		lst = lst->next;
	}
	tmp = lst;
	while (tmp)
	{
		j++;
		tmp = tmp->next;
	}
	return (j);
}

int	from_top_to_max(t_stack *stack_b, int index)
{
	t_stack	*lst;
	int		i;

	lst = stack_b;
	i = 0;
	while (lst && lst->index != index)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	check_if_top(t_stack *stack_b, int index)
{
	if (stack_b && stack_b->index == index)
		return (1);
	return (0);
}
