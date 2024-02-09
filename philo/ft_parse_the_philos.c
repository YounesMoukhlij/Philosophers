/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_the_philos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:05:06 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/09 13:38:01 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_if_num(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 && av[i][j] == '+')
				j++;
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_if_valid(char **av)
{
	if (ft_atoi(av[0]) <= 0 || ft_atoi(av[0]) >= INT_MAX)
		return (1);
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[1]) >= INT_MAX)
		return (1);
	if (ft_atoi(av[2]) <= 0 || ft_atoi(av[2]) >= INT_MAX)
		return (1);
	if (ft_atoi(av[3]) <= 0 || ft_atoi(av[3]) >= INT_MAX)
		return (1);
	if (av[4] != NULL)
	{
		if (ft_atoi(av[1]) <= 0 || ft_atoi(av[1]) >= INT_MAX)
			return (1);
	}
	return (0);
}
void	ft_parse_the_philos(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		error_parsing(0);
	if (check_if_num(av + 1) == 1)
		error_parsing(2);
	if (check_if_valid(av + 1))
		error_parsing(3);
}
