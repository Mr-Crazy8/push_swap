#include <libc.h>
#include "push_swap.h"

static char	*add(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*s3;

	i = 0;
	j = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	while (i < s1_len)
	{
		s3[i] = s1[i];
		i++;
	}
	while (j < s2_len)
		s3[i++] = s2[j++];
	s3[i] = '\0';
	return (s3);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s3 = add(s1, s2);
	return (s3);
}


void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (dest == src)
		return (dest);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}


static char	**free_split(char **split, size_t j)
{
	while (j > 0)
		free(split[--j]);
	free(split);
	return (NULL);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			n++;
		i++;
	}
	return (n);
}

static char	**split_string(char const *s, char c, char **split, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	start;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i] && j < n)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		len = i - start;
		split[j] = (char *)malloc(len + 1);
		if (!split[j])
			return (free_split(split, j));
		ft_memcpy(split[j], &s[start], len);
		split[j][len] = '\0';
		j++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	size_t	n;
	char	**split;

	if (s == NULL)
		return (NULL);
	n = count_words(s, c);
	split = (char **)malloc((n + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	return (split_string(s, c, split, n));
}


long ft_atoi(char *str)
{
    int    i;
    int    signe;
    long    res;

    i = 0;
    signe = 1;
    res = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            signe *= -1;
            i++;
    }
    while(str[i] && str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    if(str[i] && (str[i] < '0' || str[i] > '9'))
        return(LONG_MAX);
    return(res * signe);
}

int ft_strlen(const char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}
int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	while (s1[i]!= '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}

	return (s1[i] - s2[j]);
}


char	*ft_strdup(const char *s)
{
	int		i;
	int		j;
	int		s_len;
	char	*dup;

	i = 0;
	j = 0;
	s_len = ft_strlen(s);
	dup = (char *)malloc(s_len + 1);
	if (dup == NULL)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		dup[j] = s[i];
		j++;
		i++;
	}
	dup[j] = '\0';
	return (dup);
}

int int_range_checker(long nbr)
{
	int i = 1;
	if (nbr < INT_MIN || nbr > INT_MAX)
		return 0;			/// if arguments are	bigger than an integer it return 0                      
	return 1;
}
int all_range_checker(char *str[])
{
	int i = 1;
	int count = 0;
	while (str[i])
	{
		if ((int_range_checker(ft_atoi(str[i])) == 1))
			count++;
		i++;
	}
	//printf("count is : %d\n", count);
	if (count == len_of_argemont(str))
		return 1;
	return 0;	/// if arguments are	bigger than an integer it return 0   
}
int len_of_argemont(char *argv[])
{
	int i = 0;

	while (argv[i])
		i++;
	return (i -1);
}

int all_number_cheker(char *str[])
{
	int i = 1;
	int j = 0;

	int count = 0;
	while (str[i])
	{
		
		j = 0;
		while (str[i][j])
		{
			if (((str[i][j] == '-' || str[i][j] == '+')  && (str[i][j + 1] == '-' || str[i][j + 1] == '+')) )
				break;
			if (((str[i][j] == '-' || str[i][j] == '+') && (str[i][j + 1] != '\0' || str[i][j + 1] != '\0') && (str[i][j + 1] != '-' && str[i][j + 1] != '+')))
				j++;
			if (str[i][j] >= '0' && str[i][j] <= '9')
				j++;
			else
				break ;
		}
		if (str[i][j] == '\0')
			count += 1;
		i++;
	}
	if (count == len_of_argemont(str))
		return 1;
	return 0;						// if some arguments aren’t integers, return 0

}



int duplicate(char *str[]) 
{
    int i = 0;
    int j;
    int count = 0;
    while(str[i])
    {
        j = i + 1;
        while(str[j])
        {
            if(ft_strcmp(str[i], str[j]) == 0)
                count++;
            j++;
        }
        i++;
    }
	// printf("count is : %d\n", count);
    if(count == 0)
        return(1);
    return(0); 
}

void error_checker(char *argv[])
{
	if (all_number_cheker(argv) != 1 || duplicate(argv) == 0 || all_range_checker(argv) != 1)
		printf("Error\n");
	else
		printf("good\n");
}




void input_checker(int argc, char *argv[])
{
    if (argc >= 2)
    {
        char *result = argv[1];
        int i = 2;
        
        while (i < argc)
        {
            char *temp = result;
			char *res2 = ft_strjoin(result, " ");
			char *tmp2 = res2;
            result = ft_strjoin(res2, argv[i]);
			free(tmp2);
            if (i > 2)  // Only free if it's not the original argv[1]
				free(temp);
			i++;
        
		}
        char **split_result = ft_split(result, ' ');
        if (split_result)
        {
			
            error_checker(split_result);
            // Free the split result
            int j = 0;
            while (split_result[j])
            {
                free(split_result[j]);
                j++;
            }
            free(split_result);
        }
        
        if (result != argv[1])  // Only free if it's not the original argv[1]
            free(result);
    }
}





