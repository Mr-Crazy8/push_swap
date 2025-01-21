// #include "push_swap.h"

#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *argv[])
{
	int i = 1;

	while (argv[i])
		i++;
	return i;
}


int main(int argc, char *argv[])
{
	int r = 0;
	if (argc > 1)
	{
		int i = ft_strlen(&argv[r]);
		printf("%d", i -1 );
	}
}