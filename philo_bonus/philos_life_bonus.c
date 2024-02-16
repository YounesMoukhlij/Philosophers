/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_life_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:47:48 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/16 21:12:18 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	philo_eats(t_program *prg)
{
	sem_wait(prg->forks);
	print_func(prg->philos, "has taken a fork");
	sem_wait(prg->forks);
	print_func(prg->philos, "has taken a fork");
	print_func(prg->philos, "is eating");
	time_between_taches(prg->time_to_eat, prg);
	(prg->philos->eaten_times)++;
	prg->philos->last_meal_time = what_time_now();
	sem_post(prg->forks);
	sem_post(prg->forks);
}

void	daily_philo_routine(t_philo *philo)
{
	pthread_t	observator;
	t_program	*prg;

	prg = philo->philos_infos;
	if (philo->philo_id % 2)
		usleep(20000);
	pthread_create(&observator, 0, check_if_some_philo_is_dead, philo);
	while (!is_dead(prg))
	{
		if (prg->philo_all_ate || prg->philo_members == 1)
			break ;
		philo_eats(philo->philos_infos);
		print_func(philo, "is sleeping");
		time_between_taches(prg->time_to_sleep, prg);
		print_func(philo, "is thinking");
		usleep(100);
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
			daily_philo_routine(&(prg->philos[i]));
			phi[i].last_meal_time = what_time_now();
			// break ;
		}
		usleep(100);
	}
}
