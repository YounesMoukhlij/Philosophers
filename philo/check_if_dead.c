/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:46:26 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/20 17:52:32 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_one(t_program *prg, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < prg->philo_members && !(prg->dead))
	{
		pthread_mutex_lock(&(prg->stop));
		if ((what_time_now() - philo[i].last_meal_time) > prg->time_to_die)
		{
			print_func(philo, "died");
			prg->dead = 1;
		}
		pthread_mutex_unlock(&(prg->stop));
		usleep(100);
	}
}

void	check_two(t_program *prg, t_philo *philo)
{
	int	i;

	i = 0;
	while (prg->times_philo_eats != -1
		&& i < prg->philo_members
		&& philo[i].eaten_times >= prg->times_philo_eats)
		i++;
	if (i == prg->philo_members)
		prg->philo_all_ate = 1;
}

void	check_if_some_philo_is_dead(t_program *prg, t_philo *philo)
{
	while (!(prg->philo_all_ate))
	{
		check_one(prg, philo);
		if (prg->dead == 1)
			break ;
		check_two(prg, philo);
	}
}
