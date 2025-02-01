/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:02:29 by anel-men          #+#    #+#             */
/*   Updated: 2025/01/27 16:02:34 by anel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_sort(t_stack **stack_b, t_stack **stack_a)
{
	int	lent;
	int	size;
	int	top_max;

	lent = ft_list_size((*stack_b));
	while (lent > 0)
	{
		size = ft_list_size((*stack_b));
		top_max = from_top_to_max((*stack_b), (lent - 1));
		if ((size - top_max) <= top_max)
		{
			while (check_if_top((*stack_b), (lent - 1)) != 1)
				rrb(stack_b);
			pa(stack_b, stack_a);
		}
		else
		{
			while (check_if_top((*stack_b), (lent - 1)) != 1)
				rb(stack_b);
			pa(stack_b, stack_a);
		}
		lent--;
	}
}

void	free_the_list(t_stack **a)
{
	t_stack	*tmp;

	while (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
	}
	*a = NULL;
}

t_stack	*initialize_stacks(int argc, char *argv[])
{
	t_stack	*stack_a;
	char	*string;
	char	**split_r;

	input_checker(argc, argv);
	string = concatenate_arguments(argc, argv);
	split_r = ft_split(string, ' ');
	stack_a = linked_list_maker(split_r, len_of_argument(split_r));
	first_index(stack_a);
	second_index(stack_a);
	return (stack_a);
}

void	sort_stacks(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;
	int		range;

	stack_b = NULL;
	i = 1;
	range = range_finder(*stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, &stack_b);
			i++;
		}
		else if ((*stack_a)->index <= (i + range))
		{
			pb(stack_a, &stack_b);
			rb(&stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
	final_sort(&stack_b, stack_a);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	stack_a = initialize_stacks(argc, argv);
	check_if_sorted(stack_a);
	if (ft_list_size(stack_a) == 1)
		exit(1);
	else if (ft_list_size(stack_a) == 2)
	{
		sa(&stack_a);
		exit(0);
	}
	else if (ft_list_size(stack_a) == 3)
		sort_tree(&stack_a);
	else if (ft_list_size(stack_a) == 5)
		sort_five(&stack_a);
	else
		sort_stacks(&stack_a);
	free_the_list(&stack_a);
	return (0);
}
