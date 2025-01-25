#include "push_swap.h"

#include <stdio.h>
#include <unistd.h>





int	ft_list_size(t_stack *stack_a)
{
	t_stack *lst = stack_a;
	int i = 0;
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
	else
		temp = *stack_a;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new_stack_a_node;
}



t_stack *node_list_maker(int data)
{
	t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->data = data;
	new_node->next = NULL;
	return new_node;

}

t_stack *linked_list_maker(char *argv[], int size)
{
	t_stack *head = NULL;
	int i = 0;
	while (i < size)
	{
		t_stack *new_node = node_list_maker(ft_atoi(argv[i]));
		ft_lstadd_back(&head, new_node);
		i++;
	}
	return head;

}
