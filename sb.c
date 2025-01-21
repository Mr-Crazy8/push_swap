// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.

#include <libc.h>

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

int main()
{
	int nbr[5] = {2, 1, 3, 4, 5};
	sb(nbr);

	int i = 0;
	while (i < 5)
	{
		printf("%d", nbr[i]);
		i++;
	}
}