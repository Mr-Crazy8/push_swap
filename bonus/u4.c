#include "push_swap_bonus.h"

int	is_same_number(char *str1, char *str2)
{
	int	num1;
	int	num2;

	num1 = ft_atoi(str1);
	num2 = ft_atoi(str2);
	if (num1 == num2)
		return (1);
	return (0);
}

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
			if (is_same_number(str[i], str[j]))
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
		return (1);
	return (0);
}

int	len_of_argument(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}
int	int_range_checker(long nbr)
{
	if (nbr < INT_MIN)
		return (0);
	if (nbr > INT_MAX)
		return (0);
	return (1);
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
	if ((str[j] == '-' || str[j] == '+') && str[j + 1] == '\0')
		return (0);
	if (str[j] == '-' || str[j] == '+')
		j++;
	if (str[j] == '\0')
		return (0);
	if ((str[j] == '-' || str[j] == '+') && str[j + 1] == '0')
		return (0);
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