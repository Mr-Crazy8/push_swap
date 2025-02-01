/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:01:22 by anel-men          #+#    #+#             */
/*   Updated: 2025/01/27 16:01:25 by anel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_range_checker(long nbr)
{
	if (nbr < INT_MIN)
		return (0);
	if (nbr > INT_MAX)
		return (0);
	return (1);
}

int	len_of_argument(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	all_range_checker(char *str[])
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (int_range_checker(ft_atoi(str[i])))
			count++;
		i++;
	}
	if (count == len_of_argument(str))
		return (1);
	return (0);
}

int	is_valid_number(char *str)
{
	int	j;

	j = 0;
	if ((str[j] == '-' || str[j] == '+')
		&& (str[j + 1] == '-' || str[j + 1] == '+'))
		return (0);
	if (str[j] == '-' || str[j] == '+')
		j++;
	while (str[j])
	{
		if (str[j] < '0' || str[j] > '9')
			return (0);
		j++;
	}
	return (1);
}

int	all_number_checker(char *str[])
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (is_valid_number(str[i]))
			count++;
		i++;
	}
	if (count == len_of_argument(str))
		return (1);
	return (0);
}
