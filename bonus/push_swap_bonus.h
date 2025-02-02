/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-men <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:39:11 by anel-men          #+#    #+#             */
/*   Updated: 2025/01/27 18:39:13 by anel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <libc.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
#include "get_next_line.h"

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	rrb(t_stack **stack_b);
void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rra(t_stack **stack_a);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void 	ss(t_stack **stack_a, t_stack **stack_b);
void rr(t_stack **stack_a, t_stack **stack_b);
void rrr(t_stack **stack_a, t_stack **stack_b);
int	ft_list_size(t_stack *stack_a);
int	empty_space_checker(char *str[]);
int	error_checker(char *argv[]);
int	is_same_number(char *str1, char *str2);
int	duplicate(char *str[]);
int	all_range_checker(char *str[]);
int	int_range_checker(long nbr);
int	all_number_checker(char *str[]);
int	is_valid_number(char *str);
int	len_of_argument(char *argv[]);
char	*concatenate_arguments(int argc, char *argv[]);
void	validate_input(char *concatenated_str, char *original_str);
void	input_checker(int argc, char *argv[]);
int	check_if_sorted(t_stack *stack_a);
t_stack	*initialize_stacks(int argc, char *argv[]);
int	ft_strcmp(const char *s1, const char *s2);
void	free_the_list(t_stack **a);
t_stack	*linked_list_maker(char *argv[], int size);
t_stack	*node_list_maker(int data);
void	ft_lstadd_back(t_stack **stack_a, t_stack *new_stack_a_node);
long	ft_atoi(char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(char const *s, char c);
#endif
