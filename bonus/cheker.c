#include <libc.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}	t_stack;

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

t_stack	*initialize_stacks(int argc, char *argv[], int *initial_i)
{
	t_stack	*stack_a;

	*initial_i = 1;
	input_checker(argc, argv);
	stack_a = linked_list_maker(argv + 1, argc - 1);
	first_index(stack_a);
	second_index(stack_a);
	return (stack_a);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] == '0')
		i++;
	while (s2[j] == '0')
		j++;
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}

void operation(char *str[], t_stack **stack_a)
{
	int i = 0;
	t_stack *stack_b = NULL;
	while (str[i])
	{
		if (ft_strcmp(str[i], "sa") == 0)
			sa();
		else if (ft_strcmp(str[i], "sb") == 0)
			sb();
		else if (ft_strcmp(str[i], "ss") == 0)
			ss();
		else if (ft_strcmp(str[i], "pa") == 0)
			pa();
		else if (ft_strcmp(str[i], "pb") == 0)
			pb();
		else if (ft_strcmp(str[i], "ra") == 0)
			ra();
		else if (ft_strcmp(str[i], "rb") == 0)
			rb();
		else if (ft_strcmp(str[i], "rr") == 0)
			rr();
		else if (ft_strcmp(str[i], "rra") == 0)
			rra();
		else if (ft_strcmp(str[i], "rrb") == 0)
			rrb();
		else if (ft_strcmp(str[i], "rrr") == 0)
			rrr();
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;

	stack_a = init
	ialize_stacks(argc, argv);
	operation(argv, &stack_a);
	free_the_list(&stack_a);
	return (0);
}