/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_infos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:30:05 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/22 19:20:47 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_mutex(t_program *prg)
{
	int	i;

	i = -1;
	prg->forks = malloc(sizeof(pthread_mutex_t) * prg->philo_members);
	if (!(prg->philos))
		error_message(prg, 1);
	while (++i < prg->philo_members)
		if (pthread_mutex_init(&(prg->forks[i]), NULL))
			error_message(prg, 5);
	if (pthread_mutex_init(&(prg->print_habbit), NULL))
		error_message(prg, 5);
	if (pthread_mutex_init(&(prg->eat_habbit), NULL))
		error_message(prg, 5);
	if (pthread_mutex_init(&(prg->death), NULL))
		error_message(prg, 5);
}

void	wake_up_philosophers(t_program *prg)
{
	int	i;

	i = -1;
	prg->philos = malloc(sizeof(t_philo) * prg->philo_members);
	if (!(prg->philos))
		error_message(prg, 1);
	while (++i < prg->philo_members)
	{
		prg->philos[i].right_fork_id = (i + 2) % prg->philo_members;
		prg->philos[i].eaten_times = 0;
		prg->philos[i].philos_infos = prg;
		prg->philos[i].last_meal_time = 0;
		prg->philos[i].philo_id = i + 1;
		prg->philos[i].left_fork_id = i + 1;
	}
}

void	init_all_infos(t_program *prg, char **av)
{
	prg->philo_members = ft_atoi(av[1]);
	prg->time_to_die = ft_atoi(av[2]);
	prg->time_to_eat = ft_atoi(av[3]);
	prg->time_to_sleep = ft_atoi(av[4]);
	prg->philo_all_ate = 0;
	prg->dead = 0;
	if (av[5])
		prg->times_philo_eats = ft_atoi(av[5]);
	else
		prg->times_philo_eats = -1;
}
