
#include "philosophers.h"

int	check_avs(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' || av[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_parse_the_philos(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		error_parsing(0);
	if (check_avs(av))
		error_parsing(2);
}
