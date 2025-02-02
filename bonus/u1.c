#include "push_swap_bonus.h"


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
		new_node = node_list_maker(atoi(argv[i]));
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

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}

t_stack	*initialize_stacks(int argc, char *argv[])
{
	t_stack	*stack_a;
	char	*string;
	char	**split_r;
	int i = 0;
	input_checker(argc, argv);
	string = concatenate_arguments(argc, argv);
	split_r = ft_split(string, ' ');
	stack_a = linked_list_maker(split_r, len_of_argument(split_r));
	while (split_r[i])
		free(split_r[i++]);
	free(string);
	return (stack_a);
}

int	check_if_sorted(t_stack *stack_a)
{
	if (!stack_a || !stack_a->next)
		return (0);
	while (stack_a->next)
	{
		if (stack_a->data > stack_a->next->data)
			return (1) ;
		stack_a = stack_a->next;
	}
	return (0);
}