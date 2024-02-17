/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_actions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:03:16 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/17 18:05:54 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	*ft_check_death(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = arg;
	while (1)
	{
		if ((philo->last_meal + philo->info->time_to_die) <= ft_get_time())
		{
			ft_print_msg(philo, "died");
			exit(1);
		}
		usleep(100);
	}
	return (NULL);
}

void	ft_philo_actions(t_philo *philo)
{
	pthread_t	observator;

	pthread_create(&observator, 0, ft_check_death, philo);
	while (1)
	{
		sem_wait(philo->info->forks);
		ft_print_msg(philo, "has taken a fork");
		sem_wait(philo->info->forks);
		ft_print_msg(philo, "has taken a fork");
		philo->last_meal = ft_get_time();
		ft_print_msg(philo, "is eating");
		usleep(philo->info->time_to_eat * 1000);
		sem_post(philo->info->forks);
		sem_post(philo->info->forks);
		philo->eaten_times++;
		if (philo->eaten_times == philo->info->number_of_times_each_philosopher_must_eat)
			exit(0);
		ft_print_msg(philo, "is sleeping");
		usleep(philo->info->time_to_sleep * 1000);
		ft_print_msg(philo, "is thinking");
		// exit(0);
	}
	pthread_join(observator, 0);
}
