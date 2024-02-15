/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_life.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:47:48 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/13 17:24:44 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	philo_eats(t_program *prg)
// {
// 	prg = philo->philos_infos;
// 	sem_wait();
// 	print_func(philo, "has taken a fork");
// 	sem_wait();
// 	print_func(philo, "has taken a fork");
// 	sem_wait();
// 	print_func(philo, "is eating");
// 	philo->last_meal_time = what_time_now();
// 	sem_wait();
// 	time_between_taches(prg->time_to_eat, prg);
// 	(philo->eaten_times)++;
// 	sem_wait();
// 	sem_wait();
// }

void	daily_philo_routine(t_program *philo)
{
	pthread_t	observator;

	pthread_create(&observator, 0, check_if_some_philo_is_dead, philo);
	while (1999)
	{
		philo_eats(philo);
		print_func(philo, "is sleeping");
		time_between_taches(philo->time_to_sleep, philo);
		print_func(philo, "is thinking");
	}
	pthread_join(observator, 0);
}

void	philos_life(t_program *prg)
{
	int		i;
	t_philo	*phi;

	i = -1;
	phi = prg->philos;
	prg->time_start = what_time_now();
	while (++i < prg->philo_members)
	{
		prg->philos[i].philo_pid = fork();
		if (prg->philos[i].philo_pid == 0)
		{
			daily_philo_routine(prg);
			break ;
		}
		phi[i].last_meal_time = what_time_now();
	}
}
