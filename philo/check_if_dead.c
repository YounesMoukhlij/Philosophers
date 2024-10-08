/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:46:26 by youmoukh          #+#    #+#             */
/*   Updated: 2024/03/01 13:46:45 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	extra_check(t_program *prg, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < prg->philo_members && !(prg->dead))
	{
		pthread_mutex_lock(&prg->eat_habbit);
		if ((what_time_now() - philo[i].last_meal_time) > prg->time_to_die)
		{
			print_func(philo, "died");
			pthread_mutex_lock(&(prg->death));
			prg->dead = 1;
			pthread_mutex_unlock(&(prg->death));
		}
		pthread_mutex_unlock(&prg->eat_habbit);
		usleep(100);
	}
}

void	double_check(t_program *prg, t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(prg->check_eaten_times));
	while (prg->times_philo_eats != -1
		&& i < prg->philo_members
		&& philo[i].eaten_times >= prg->times_philo_eats)
		i++;
	pthread_mutex_unlock(&(prg->check_eaten_times));
	if (i == prg->philo_members)
	{
		pthread_mutex_lock(&(prg->all_eat));
		prg->philo_all_ate = 1;
		pthread_mutex_unlock(&(prg->all_eat));
	}
	pthread_mutex_unlock(&(prg->all_eat));
}

void	check_if_some_philo_is_dead(t_program *prg, t_philo *philo)
{
	while (!(prg->philo_all_ate))
	{
		extra_check(prg, philo);
		if (prg->dead == 1)
			break ;
		double_check(prg, philo);
	}
}

100 1000 1000 100 45