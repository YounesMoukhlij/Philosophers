/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:24:14 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/23 19:26:21 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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

void	part_1(t_program *prg, t_philo *philo)
{
	sem_wait(prg->forks);
	deliver_message(philo, "has taken a fork");
	sem_wait(prg->forks);
	deliver_message(philo, "has taken a fork");
	deliver_message(philo, "is eating");
	if (prg->eat_counter != -1)
		prg->current_eat++;
	time_between_taches(prg->time_to_eat);
	philo->eating_time = what_time_now();
}

void	ft_routine(t_philo *philo)
{
	pthread_t	death;
	t_program	*prg;

	prg = philo->data;
	sem_wait(prg->last_meaal);
	philo->next_meal = what_time_now() + prg->time_to_die;
	sem_post(prg->last_meaal);
	pthread_create(&death, 0, ft_check_death, philo);
	while (1)
	{
		part_1(prg, philo);
		sem_wait(prg->last_meaal);
		philo->next_meal = philo->eating_time + prg->time_to_die;
		sem_post(prg->last_meaal);
		sem_post(prg->forks);
		sem_post(prg->forks);
		deliver_message(philo, "is sleeping");
		time_between_taches(prg->time_to_sleep);
		deliver_message(philo, "is thinking");
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

int	main(int ac, char **av)
{
	t_program	prg;

	ft_parse_param(ac, av);
	inisialize_data(&prg, av);
	inisialize_philosophers(&prg);
	inisialize_semaphores(&prg);
	sem_wait(prg.stop);
	inisialize_process(&prg, prg.philos);
	sem_wait(prg.stop);
	finish_all(&prg, prg.philos);
	return (0);
}
