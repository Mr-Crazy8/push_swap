#include "push_swap.h"

// int find_max(t_stack *stack_b)
// {
//    if (!stack_b)
//        return INT_MIN;

//    int max = stack_b->data;
//    t_stack *tmp = stack_b->next;
   
//    while (tmp)
//    {
//        if (tmp->data > max)
//            max = tmp->data;
//        tmp = tmp->next;
//    }
//    return max;
// }

int find_max(t_stack *stack)
{
    if (!stack)
        return INT_MIN;
    
    if (!stack->next)
        return stack->data;
    
    int max_rest = find_max(stack->next);
    return (stack->data > max_rest) ? stack->data : max_rest;
}

// int	from_last_to_max(t_stack *stack_b, int data)
// {
// 	t_stack *lst = stack_b;
// 	int i = 0;
// 	int j = 0;
// 	while (lst->data != data)
// 	{
// 		i++;
// 		lst = lst->next;
// 	}
// 	t_stack *tmp = lst;

// 	while (tmp)
// 	{
// 		j++;
// 		tmp = tmp->next;
// 	}

// 	return (j);
// }

// int	from_top_to_max(t_stack *stack_b, int data)
// {
// 	t_stack *lst = stack_b;
// 	int i = 0;
// 	while (lst->data != data)
// 	{
// 		i++;
// 		lst = lst->next;
// 	}

// 	return (i);
// }
// int check_if_last(t_stack *stack_b, int data)
// {

// 	t_stack *lst = stack_b;
// 	while (lst->data != data)
// 		lst = lst->next;
// 	if (lst->data == data)
// 		return 1;
// 	return (0);
// }
// int check_if_top(t_stack *stack_b, int data)
// {
// 	if (stack_b->data == data)
// 		return 1;
// 	return 0;
// }

// void final_sort(t_stack *stack_b, t_stack *stack_a)
// {
// 	while (stack_b)
// 	{
// 		while (check_if_last(stack_b, find_max(stack_b)) == 1)
// 		{
// 			rb(&stack_b);
// 			pa(&stack_a, &stack_b);
// 		}
// 		while (check_if_top(stack_b, find_max(stack_b)) == 1)
// 			pa(&stack_a, &stack_b);
// 		while (from_last_to_max(stack_b, find_max(stack_b)) < from_top_to_max(stack_b, find_max(stack_b)))
// 		{
// 			if (check_if_top(stack_b, find_max(stack_b)) != 1)
// 				rb(&stack_b);
// 			pa(&stack_a, &stack_b);
// 		}
// 		while (from_last_to_max(stack_b, find_max(stack_b)) > from_top_to_max(stack_b, find_max(stack_b)))
// 		{
// 			if (check_if_top(stack_b, find_max(stack_b)) != 1)
// 				rrb(&stack_b);
// 			pa(&stack_a, &stack_b);
// 		}
// 		stack_b = stack_b->index;
// 	}
// }

int main()
{
	t_stack *stack_b = NULL;

	t_stack nbr1;
	t_stack nbr2;
	t_stack nbr3;
	t_stack nbr4;
	t_stack nbr5;
	t_stack nbr6;
	t_stack nbr7;
	t_stack nbr8;
	t_stack nbr9;
	t_stack nbr10;


	nbr1.data = 46;
	nbr2.data = 649;
	nbr3.data = 6;
	nbr4.data = 391;
	nbr5.data = 4;
	nbr6.data = 230;
	nbr7.data = 3;
	nbr8.data = 159;
	nbr9.data = 241;
	nbr10.data = 910;

	stack_b = &nbr1;
	nbr1.next = &nbr2;
	nbr2.next = &nbr3;
	nbr3.next = &nbr4;
	nbr4.next = &nbr5;
	nbr5.next = &nbr6;
	nbr6.next = &nbr7;
	nbr7.next = &nbr8;
	nbr8.next = &nbr9;
	nbr9.next = NULL;

	t_stack *tmp1 = stack_b;
	t_stack *tmp2 = stack_b;
	//int fromlasttomax = from_last_to_max(tmp1, find_max(tmp1));
	//int fromtoptomax = from_top_to_max(tmp2, find_max(tmp2));
	int max = find_max(tmp1);
	//int checkiflast = find_max(tmp1);
	//printf("from_last_to_max  : %d\n", fromlasttomax);
	//printf("from_top_to_max  : %d\n", fromtoptomax);

	printf("max  : %d\n", max);
	//printf("check_if_last : %d\n", checkiflast);
}