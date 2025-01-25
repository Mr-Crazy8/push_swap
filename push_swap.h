#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <libc.h>

typedef struct s_stack
{
	int data;
	int index;
	struct s_stack *next;
	
} t_stack;



t_stack *sa(t_stack *stack_a);  //1
t_stack *sb(t_stack *stack_b); //2
void ss(t_stack *stack_a, t_stack *stack_b);  //3
void pa(t_stack **stack_b, t_stack **stack_a); //4
void pb(t_stack **stack_a, t_stack **stack_b);   //5
void ra(t_stack **stack_a);  //6
void rb(t_stack **stack_b);   //7
void rr(t_stack *stack_a, t_stack *stack_b);  ///8
t_stack *rra(t_stack *stack_a);    ///9
void rrb(t_stack **stack_b);  ///10
void rrr(t_stack *stack_a, t_stack *stack_b);  ///111
int len_of_argemont(char *argv[]);
void error_checker(char *argv[]);
int int_range_checker(long nbr);
int all_range_checker(char *str[]);
int all_number_cheker(char *str[]);
char	**ft_split(char const *s, char c);
static char	*add(char const *s1, char const *s2);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
static char	**free_split(char **split, size_t j);
int duplicate(char *str[]);
static size_t	count_words(char const *s, char c);
static char	**split_string(char const *s, char c, char **split, size_t n);
long ft_atoi(char *str);
int ft_strlen(const char *str);
int ft_strcmp(char *s1, char *s2);
int range_finder(t_stack *head);
char	*ft_strdup(const char *s);
void input_checker(int argc, char *argv[]);
void second_index(t_stack *head);
void first_index(t_stack *head);
int  find_min(t_stack *haed);
void	ft_lstadd_back(t_stack **stack_a, t_stack *new_stack_a_node);
t_stack *node_list_maker(int data);
t_stack *linked_list_maker(char *argv[], int size);
int	ft_list_size(t_stack *stack_a);

#endif