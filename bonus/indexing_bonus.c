/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:01:59 by anel-men          #+#    #+#             */
/*   Updated: 2025/01/27 16:02:01 by anel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	duplicate(char *str[])
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_strcmp(str[i], str[j]) == 0)
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
		return (1);
	return (0);
}

int	find_min(t_stack *head)
{
	t_stack	*tmp;
	int		nbr;

	tmp = head;
	nbr = INT_MAX;
	while (tmp)
	{
		if (tmp->index == -1 && tmp->data < nbr)
			nbr = tmp->data;
		tmp = tmp->next;
	}
	return (nbr);
}

void	first_index(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp)
	{
		tmp->index = -1;
		tmp = tmp->next;
	}
}

void	second_index(t_stack *head)
{
	t_stack	*tmp;
	int		index;
	int		min;

	index = 0;
	while (1)
	{
		min = find_min(head);
		if (min == INT_MAX)
			break ;
		tmp = head;
		while (tmp)
		{
			if (tmp->index == -1 && tmp->data == min)
				tmp->index = index;
			tmp = tmp->next;
		}
		index++;
	}
}

long	ft_atoi(char *str)
{
	int		i;
	int		signe;
	long	res;

	i = 0;
	signe = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] && (str[i] < '0' || str[i] > '9'))
		return (LONG_MAX);
	return (res * signe);
}
