#include "philosopher.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	just_digit(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))	
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_usage(int ac, char **av)
{
	if (ac != 4 && ac != 5)
	{
		printf("%s\n", ARG_NUMBER);
		return (0);
	}
	if (!just_digit(av))
	{
		printf("%s\n", INVALID_ARG);
		return (0);
	}
	return (1);
}
