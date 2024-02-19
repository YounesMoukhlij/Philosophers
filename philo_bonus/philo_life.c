/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:43:55 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/19 19:55:25 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	*ft_check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (check_one(philo))
			break ;
		if (check_two(philo))
			break ;
	}
	return (NULL);
}

void	ft_routine(t_philo *philo)
{
	pthread_t	death;
	t_program	*prg;

	prg = philo->data;
	philo->next_meal = what_time_now() + prg->time_to_die;
	pthread_create(&death, NULL, ft_check_death, philo);
	while (1)
	{
		sem_wait(prg->forks);
		print_message(philo, "has taken a fork");
		sem_wait(prg->forks);
		print_message(philo, "has taken a fork");
		print_message(philo, "is eating");
		prg->current_eat++;
		time_between_taches(prg->time_to_eat);
		philo->next_meal = what_time_now() + prg->time_to_die;
		sem_post(prg->forks);
		sem_post(prg->forks);
		print_message(philo, "is sleeping");
		time_between_taches(prg->time_to_sleep);
		print_message(philo, "is thinking");
	}
	pthread_join(death, 0);
}

void	inisialize_process(t_program *prg, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < prg->philo_numbers)
	{
		philo[i].pid = fork();
		if (philo[i].pid == 0)
		{
			ft_routine(philo + i);
			exit(0);
		}
		i++;
		usleep(100);
	}
}
