//ra (rotate a): Shift up all elements of stack a by 1.
//The first element becomes the last one.

#include "push_swap.h"
#include <libc.h>
// typedef struct s_stack
// {
// 	int data;
// 	int index;
// 	struct s_stack *next;
	
// } t_stack;
// void ra(t_stack **stack_a);
// t_stack *create_node(int data);
// void print_list(t_stack *head);
// void free_list(t_stack *head);

// // Node creation function
// t_stack *create_node(int data)
// {
//     t_stack *new_node = malloc(sizeof(t_stack));
//     new_node->data = data;
//     new_node->next = NULL;
//     return new_node;
// }
 

void ra(t_stack **stack_a)
{
	

	t_stack *lst = *stack_a;
	t_stack *tmp = *stack_a;


	*stack_a = tmp->next; 

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	lst->next = tmp;
	tmp->next = NULL;

}



// void print_list(t_stack *head)
// {
//     printf("List: ");
//     while (head) {
//         printf("%d ", head->data);
//         head = head->next;
//     }
//     printf("\n");
// }

// // Memory cleanup
// void free_list(t_stack *head)
// {
//     t_stack *tmp;
//     while (head) {
//         tmp = head;
//         head = head->next;
//         free(tmp);
//     }
// }

// int main()
// {
//     // Create a sample linked list
//     t_stack *head = create_node(1);
//     head->next = create_node(2);
//     head->next->next = create_node(3);
//     head->next->next->next = create_node(4);
//     head->next->next->next->next = create_node(5);

//     printf("Original List:\n");
//     print_list(head);

//     // Perform rotation
//     ra(&head);

//     printf("After First Rotation:\n");
//     print_list(head);

//     // Perform another rotation
//     ra(&head);

//     printf("After Second Rotation:\n");
//     print_list(head);

//     // Free the list
//     free_list(head);

//     return 0;
// }
