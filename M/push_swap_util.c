/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:02:43 by anel-men          #+#    #+#             */
/*   Updated: 2025/01/27 16:02:46 by anel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	sb(t_stack **stack_b)
{
	int	tmp2;

	tmp2 = (*stack_b)->data;
	(*stack_b)->data = (*stack_b)->next->data;
	(*stack_b)->next->data = tmp2;
	write(1, "sb\n", 3);
}

int	ft_list_size(t_stack *stack_a)
{
	t_stack	*lst;
	int		i;

	lst = stack_a;
	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	ft_lstadd_back(t_stack **stack_a, t_stack *new_stack_a_node)
{
	t_stack	*temp;

	if (stack_a == NULL || new_stack_a_node == NULL)
		return ;
	if (*stack_a == NULL)
	{
		*stack_a = new_stack_a_node;
		return ;
	}
	temp = *stack_a;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_stack_a_node;
}

t_stack	*node_list_maker(int data)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*linked_list_maker(char *argv[], int size)
{
	t_stack	*head;
	t_stack	*new_node;
	t_stack	*tmp;
	int		i;

	head = NULL;
	i = 0;
	while (i < size)
	{
		new_node = node_list_maker(ft_atoi(argv[i]));
		if (!new_node)
		{
			while (head)
			{
				tmp = head;
				head = head->next;
				free(tmp);
			}
			return (NULL);
		}
		ft_lstadd_back(&head, new_node);
		i++;
	}
	return (head);
}
