/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_life.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:47:48 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/16 19:40:37 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eats(t_philo *philo)
{
	t_program	*prg;

	prg = philo->philos_infos;
	pthread_mutex_lock(&(prg->forks[philo->left_fork_id]));
	print_func(philo, "has taken a fork");
	pthread_mutex_lock(&(prg->forks[philo->right_fork_id]));
	print_func(philo, "has taken a fork");
	pthread_mutex_lock(&(prg->eat_habbit));
	print_func(philo, "is eating");
	philo->last_meal_time = what_time_now();
	pthread_mutex_unlock(&(prg->eat_habbit));
	time_between_taches(prg->time_to_eat, prg);
	(philo->eaten_times)++;
	pthread_mutex_unlock(&(prg->forks[philo->left_fork_id]));
	pthread_mutex_unlock(&(prg->forks[philo->right_fork_id]));
}

void	*daily_philo_routine(void *param)
{
	t_philo		*philo;
	t_program	*prg;

	philo = (t_philo *)param;
	prg = philo->philos_infos;
	if (philo->philo_id % 2)
		usleep(20000);
	while (!is_dead(prg))
	{
		if (prg->philo_members == 1)
		{
			a_lonely_philo(prg);
			break ;
		}
		if (prg->philo_all_ate)
			break ;
		philo_eats(philo);
		print_func(philo, "is sleeping");
		time_between_taches(prg->time_to_sleep, prg);
		print_func(philo, "is thinking");
	}
	return (NULL);
}

void	philos_life(t_program *prg)
{
	t_philo	*phi;
	int		i;

	i = -1;
	phi = prg->philos;
	prg->time_start = what_time_now();
	while (++i < prg->philo_members)
	{
		if (pthread_create(&(phi[i].thread_id), NULL, \
		daily_philo_routine, &(phi[i])))
			return ;
		phi[i].last_meal_time = what_time_now();
	}
}
