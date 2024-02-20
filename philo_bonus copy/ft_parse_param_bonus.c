/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:05:06 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/19 19:22:51 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	error_message(t_program *philo, int mode)
{
	(void) philo;
	write(2, "Error\n", 6);
	if (mode == 0)
		write(2, "what ever!\n", 11);
	if (mode == 1)
		write(2, "Malloc Failed!\n", 16);
	if (mode == 2)
		write(2, "Creating threads Failed!\n", 26);
	if (mode == 3)
		write(2, "Joing threads Failed!\n", 23);
	if (mode == 4)
		write(2, "Program Failed!\n", 17);
	if (mode == 5)
		write(2, "Creating Mutex Failed!\n", 24);
	exit(EXIT_FAILURE);
}

void	error_parsing(int mode)
{
	write(2, "Error\n", 6);
	if (mode == 0)
		write(2, "Invalid Argument!\n", 19);
	if (mode == 1)
		write(2, "You depassed integers try 0 < n < INT_MAX!\n", 44);
	if (mode == 2)
		write(2, "Emm something smells fishy! Try AGAIN\n", 39);
	if (mode == 3)
		write(2, "Numbers not valid\n", 19);
	exit(EXIT_FAILURE);
}

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
		if (ft_atoi(av[4]) <= 0 || ft_atoi(av[4]) >= INT_MAX)
			return (1);
	}
	return (0);
}

void	ft_parse_param(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		error_parsing(0);
	if (check_if_num(av + 1) == 1)
		error_parsing(2);
	if (check_if_valid(av + 1))
		error_parsing(3);
}
