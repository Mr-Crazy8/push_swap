#include "push_swap.h"


void rrb(t_stack **stack_b)
{
    if (!(*stack_b) || !(*stack_b)->next)
        return;

    t_stack *lst = *stack_b;
    t_stack *tmp = *stack_b;

    while (lst->next != NULL)
        lst = lst->next;

    while (tmp->next->next != NULL)
        tmp = tmp->next;
    lst->next = *stack_b;
    *stack_b = lst;
    tmp->next = NULL;
}

void pa(t_stack **stack_b, t_stack **stack_a)
{
    t_stack *tmp;
    
    if (!(*stack_b))
        return;
    
    tmp = *stack_b;
    *stack_b = (*stack_b)->next;
    tmp->next = *stack_a;
    *stack_a = tmp;
}
void pb(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    if (!(*a))
        return;
    tmp = *a;
    *a = (*a)->next;
    tmp->next = *b;
    *b = tmp;
}

void ra(t_stack **stack_a)
{
    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return;

    t_stack *first = *stack_a;
    *stack_a = first->next;

    t_stack *last = *stack_a;
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = first;
    first->next = NULL;
}

void rb(t_stack **stack_b)
{
    if (*stack_b == NULL || (*stack_b)->next == NULL)
        return;

    t_stack *first = *stack_b;
    *stack_b = first->next;

    t_stack *last = *stack_b;
    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = first;
    first->next = NULL;
}
void print_list(t_stack *head) {
	while (head) {
		printf("Data: %d, Index: %d\n", head->data, head->index);
		head = head->next;
	}
}

int range_finder(t_stack *head)
{
	int size;
	int range;
	size = ft_list_size(head);

	if (size > 100)
		range = 42;
	if (size <= 100)
		range = 15;
	return range;
}



int find_max(t_stack *stack_b)
{
    if (!stack_b)
        return INT_MIN;

    int max = stack_b->data;
    t_stack *tmp = stack_b->next;

    while (tmp)
    {
        if (tmp->data > max)
            max = tmp->data;
        tmp = tmp->next;
    }
    return max;
}

int	from_last_to_max(t_stack *stack_b, int index)
{
	t_stack *lst = stack_b;
	int i = 0;
	int j = 0;
	while (lst && lst->index != index)
	{
		i++;
		lst = lst->next;
	}
	t_stack *tmp = lst;

	while (tmp)
	{
		j++;
		tmp = tmp->next;
	}
    // write(1, "here\n", 5);

	return (j);
}

int	from_top_to_max(t_stack *stack_b, int index)
{
	t_stack *lst = stack_b;
	int i = 0;
	while (lst && lst->index != index)
	{
		i++;
		lst = lst->next;
	}

	return (i);
}
int check_if_last(t_stack *stack_b, int index)
{

	t_stack *lst = stack_b;
	while (lst && lst->next != NULL)
		lst = lst->next;
	if (lst && lst->index == index)
		return 1;
	return (0);
}
int check_if_top(t_stack *stack_b, int index)
{
	if (stack_b && stack_b->index == index)
		return 1;
	return 0;
}




void final_sort(t_stack *stack_b, t_stack *stack_a)
{
    int lent = ft_list_size(stack_b);
    int i = 1;
	while (lent > 0)
	{
		if (check_if_top(stack_b, (lent - i)) == 1)
        {
			pa(&stack_b, &stack_a);
 			write(1, "pa\n", 3);
        }
		else if (check_if_last(stack_b, (lent - i)) == 1)
		{
			rrb(&stack_b);
 			write(1, "rrb\n", 4);
 			pa(&stack_b, &stack_a);
            write(1, "pa\n", 3);
		}
		else if (from_last_to_max(stack_b, (lent - i)) > from_top_to_max(stack_b, (lent - i)))
		{
			while (check_if_top(stack_b, (lent - i)) != 1)
            {
				rb(&stack_b);
                write(1, "rb\n", 3);
            }
            pa(&stack_b, &stack_a);
            write(1, "pa\n", 3);
		}
		else if (from_last_to_max(stack_b, (lent - i)) <= from_top_to_max(stack_b, (lent - i)))
		{
			while (check_if_top(stack_b, (lent - i)) != 1)
            {
				rrb(&stack_b);
 				write(1, "rrb\n", 4);
            }
		    pa(&stack_b, &stack_a);
            write(1, "pa\n", 3);
		}
        // printf("here========================\n");
        lent--;
	}
}
int main(int argc, char *argv[])
{
	int i = 1;
	int size = 0;
	int range;
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;
	input_checker(argc, argv);

	stack_a = linked_list_maker(argv + 1, argc - 1);


	first_index(stack_a);
	second_index(stack_a);
	range = range_finder(stack_a);

	//print_list(stack_a);
	

	int j = 0;
	int lent;
	t_stack *tmp_stack_a;

	lent =ft_list_size(stack_a);
	//print_list(stack_a);
	while (stack_a)
	{
		
		tmp_stack_a = stack_a;
		if (tmp_stack_a->index <= i)
			{
				pb(&stack_a, &stack_b);
				write(1, "pb\n", 3);
				i++;
			}
		else if (tmp_stack_a->index <= (i + range))
			{
				pb(&stack_a, &stack_b);
				write(1, "pb\n", 3);
				if (ft_list_size(stack_b) > 1)
                {
				    rb(&stack_b);
				    write(1, "rb\n", 3);
                }
				i++;
			}
		else
		{
			ra(&stack_a);
			write(1, "ra\n", 3);
		}
        // stack_a = stack_a->next;
		//lent--;
	}
	final_sort(stack_b, stack_a);
            //printf("here========================");


	//printf("%d", find_max(stack_b));
}





////make a func to check if the stack sorted
////make a func to keep track of every instruction
////add in the error_checker to check for empty string and a string that have only space
////make the sorting for 5 and less then 5
///make the sorting for 100 
///make the sorting for 500
///make the sorting for 700