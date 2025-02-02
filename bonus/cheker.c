#include <libc.h>
#include "push_swap_bonus.h"


void ok_or_ko(t_stack **stack_a)
{
	if (check_if_sorted(*stack_a) == 0)
		write(1, "OK\n", 3);
	else if (check_if_sorted(*stack_a) == 1)
		write(1, "KO\n", 3);
	
}

static void execute_operation(const char *op, t_stack **stack_a, t_stack **stack_b)
{
    if (ft_strcmp(op, "sa\n") == 0)
        sa(stack_a);
    else if (ft_strcmp(op, "sb\n") == 0)
        sb(stack_b);
    else if (ft_strcmp(op, "ss\n") == 0)
        ss(stack_a, stack_b);
    else if (ft_strcmp(op, "pa\n") == 0)
        pa(stack_b, stack_a);
    else if (ft_strcmp(op, "pb\n") == 0)
        pb(stack_a, stack_b);
    else if (ft_strcmp(op, "ra\n") == 0)
        ra(stack_a);
    else if (ft_strcmp(op, "rb\n") == 0)
        rb(stack_b);
    else if (ft_strcmp(op, "rr\n") == 0)
        rr(stack_a, stack_b);
    else if (ft_strcmp(op, "rra\n") == 0)
        rra(stack_a);
    else if (ft_strcmp(op, "rrb\n") == 0)
        rrb(stack_b);
    else if (ft_strcmp(op, "rrr\n") == 0)
        rrr(stack_a, stack_b);
	else
		(write(1, "Error\n", 6), exit(1));
}

void operation(char *str[], t_stack **stack_a)
{
    int i;
    t_stack *stack_b;

    i = 0;
    stack_b = NULL;
    while (str[i])
    {
        execute_operation(str[i], stack_a, &stack_b);
        i++;
    }
    ok_or_ko(stack_a);
     if (stack_b)  // Make sure to free stack_b
        free_the_list(&stack_b);
}


char **read_instra()
{
    char *line;
    char **str;
	int j;
    int i = 0;
    int capacity = 5;

    str = (char **)malloc(sizeof(char *) * (capacity + 1));
    if (!str)
        return (NULL);

    while ((line = get_next_line(0)) != NULL)
    {
        if (i >= capacity)
        {
            capacity += 1;
            char **temp = (char **)malloc(sizeof(char *) * (capacity + 1));
            if (!temp)
            {
                 free(line);
                while (j < i)
                {
					free(str[j]);
                    j++;
                }
				free(str);
                return (NULL);
            }
			j = 0;
			while (j < i)
			{
				temp[j] = str[j];
				j++;
			}
            free(str);
            str = temp;
        }
        str[i++] = line;
    }
    if (i == 0)  // Handle empty input
    {
        free(str);
        return (NULL);
    }
    str[i] = NULL;
    return (str);
}
// void f()
// {
// 	system("leaks a.out");
// }

void free_instructions(char **instra)
{
    int i;

    if (!instra)
        return;
    i = 0;
    while (instra[i])
    {
        free(instra[i]);
        i++;
    }
    free(instra);
}
int main(int argc, char *argv[])
{
	t_stack	*stack_a;

	int i;
	i = 0;
	char **instra = read_instra();
    if (!instra)  // Check if read_instra failed
        return (0);
	stack_a = initialize_stacks(argc, argv);
    if (!stack_a)  // Check if initialize_stacks failed
    {
        free_instructions(instra);
        return (0);
    }
	if (check_if_sorted(stack_a) == 1)
		operation(instra, &stack_a);
	free_instructions(instra);
    free_the_list(&stack_a);
	return (0);

}