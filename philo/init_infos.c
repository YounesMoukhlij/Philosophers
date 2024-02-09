/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_infos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:43:44 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/09 13:46:18 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// int	extra_init_infos(t_program *philo, char **av, int ac)
// {
// 	philo->philo->philo_members = ft_atoi(av[1]);
// 	philo->philo->time_to_die = ft_atoi(av[2]);
// 	philo->philo->time_to_eat = ft_atoi(av[3]);
// 	philo->philo->time_to_sleep = ft_atoi(av[4]);
// 	if (ac == 5)
// 		philo->philo->times_each_philo_must_eat = 0;
// 	else
// 		philo->philo->times_each_philo_must_eat = ft_atoi(av[5]);
// 	if (philo->philo->philo_members == 0 || philo->philo->time_to_die == 0
// 		|| philo->philo->time_to_eat == 0 || philo->philo->time_to_sleep == 0)
// 		return (1);
// 	return (0);
// }

int	init_infos(t_program *prg, char **av, int ac)
{
	int	i;

	i = -1;
	prg->philo_members = ft_atoi(av[1]);
	prg->philo = malloc(sizeof(t_philo) * prg->philo_members);
	if (!(prg->philo))
		error_message(prg, 1);
	while (++i <= prg->philo_members)
	{
		prg->philo[i].time_to_die = ft_atoi(av[2]);
		prg->philo[i].time_to_eat = ft_atoi(av[3]);
		prg->philo[i].time_to_sleep = ft_atoi(av[4]);
		if (ac == 5)
			prg->philo[i].times_each_philo_must_eat = -1;
		else
			prg->philo[i].times_each_philo_must_eat = ft_atoi(av[5]);
	}
	return (0);
}
