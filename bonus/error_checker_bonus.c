/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:01:41 by anel-men          #+#    #+#             */
/*   Updated: 2025/01/27 16:01:45 by anel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

int	empty_space_checker(char *str[])
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == (void *)0)
			count++;
		while (str[i][j] == 32)
			j++;
		if (str[i][j] == '\0')
			count++;
		i++;
	}
	if (count == 0)
		return (1);
	return (0);
}

int	error_checker(char *argv[])
{
	if (all_number_checker(argv) != 1 || duplicate(argv) != 1
		|| all_range_checker(argv) != 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (0);
}

char	*concatenate_arguments(int argc, char *argv[])
{
	char	*result;
	char	*temp;
	char	*res2;
	int		i;

	result = argv[1];
	i = 2;
	while (i < argc)
	{
		temp = result;
		res2 = ft_strjoin(result, " ");
		result = ft_strjoin(res2, argv[i]);
		free(res2);
		if (i > 2)
			free(temp);
		i++;
	}
	return (result);
}

void	validate_input(char *concatenated_str, char *original_str)
{
	char	**split_result;
	int		i;

	split_result = ft_split(concatenated_str, ' ');
	if (split_result)
	{
		error_checker(split_result);
		i = 0;
		while (split_result[i])
		{
			free(split_result[i]);
			i++;
		}
		free(split_result);
	}
	if (concatenated_str != original_str)
		free(concatenated_str);
}

void	input_checker(int argc, char *argv[])
{
	char	*concatenated_str;

	if (argc >= 2)
	{
		if (empty_space_checker(argv) != 1)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		concatenated_str = concatenate_arguments(argc, argv);
		validate_input(concatenated_str, argv[1]);
	}
}
