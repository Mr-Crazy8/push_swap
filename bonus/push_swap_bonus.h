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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libc.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}	t_stack;
void	final_sort(t_stack **stack_b, t_stack **stack_a);
void	sort_stacks(t_stack **stack_a);
void	free_the_list(t_stack **a);
t_stack	*initialize_stacks(int argc, char *argv[], int *initial_i);
t_stack	*linked_list_maker(char *argv[], int size);
void	ft_lstadd_back(t_stack **stack_a, t_stack *new_stack_a_node);
t_stack	*node_list_maker(int data);
int		ft_list_size(t_stack *stack_a);
int		error_checker(char *argv[]);
int		empty_space_checker(char *str[]);
int		duplicate(char *str[]);
int		all_range_checker(char *str[]);
int		all_number_checker(char *str[]);
int		is_valid_number(char *str);
void	input_checker(int argc, char *argv[]);
void	validate_input(char *concatenated_str, char *original_str);
char	*concatenate_arguments(int argc, char *argv[]);
void	first_index(t_stack *head);
void	second_index(t_stack *head);
long	ft_atoi(char *str);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
int		ft_strcmp(char *s1, char *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	rrb(t_stack **stack_b);
void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
int		range_finder(t_stack *head);
int		find_max(t_stack *stack_b);
int		find_min(t_stack *head);
int		from_last_to_max(t_stack *stack_b, int index);
int		from_top_to_max(t_stack *stack_b, int index);
int		check_if_top(t_stack *stack_b, int index);
int		int_range_checker(long nbr);
int		len_of_argument(char *argv[]);

#endif
