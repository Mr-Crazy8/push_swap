// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.
// #include "push_swap.h"

// typedef struct s_a
// {
// 	int data;
// 	struct s_a *next;
	
// } t_a;

// typedef struct s_b
// {
// 	int data;
// 	struct s_b *next;
	
// } t_b;

#include <libc.h>

void	sa(int nbr[])
{
	//int i = 0;

	int tmp;

	if (nbr)
	{
		tmp = nbr[0];
		nbr[0] = nbr[1];
		nbr[1] = tmp;
	}

}

void	sb(int nbr[])
{
	//int i = 0;

	int tmp;

	if (nbr)
	{
		tmp = nbr[0];
		nbr[0] = nbr[1];
		nbr[1] = tmp;
	}

}

void ss(int a[], int b[])
{
	return (sa(a), sb(b));
}

int main()
{
	int a[5] = {2, 1, 3, 4, 5};

	int b[5] = {7, 6, 8, 9, 10};
	ss(a, b);

	int i = 0;
	while (i < 5)
	{
		printf("%d\n", a[i]);
		i++;
	}

	i = 0;
	while (i < 5)
	{
		printf("%d\n", b[i]);
		i++;
	}
}