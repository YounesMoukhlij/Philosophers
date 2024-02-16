/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_dead_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:46:26 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/16 21:14:28 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	extra_check(t_program *prg, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < prg->philo_members && !(prg->is_dead))
	{
		sem_wait(prg->print);
		if ((what_time_now() - philo->last_meal_time) > prg->time_to_die)
		{
			print_func(philo, "died");
			prg->is_dead = 1;
			// kill(philo->philo_pid, SIGKILL);
			// exit(1);
		}
		sem_post(prg->print);
		usleep(100);
	}
}

void	double_check(t_program *prg, t_philo *philo)
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

void	*check_if_some_philo_is_dead(void *param)
{
	t_program	*prg;

	prg = (t_program *)param;
	while (!(prg->philo_all_ate))
	{
		extra_check(prg, prg->philos);
		if (prg->is_dead)
			break ;
		double_check(prg, prg->philos);
	}
	return (NULL);
}
