/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_infos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:58:42 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/23 19:10:20 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	inisialize_semaphores(t_program *prg)
{
	sem_unlink("death");
	sem_unlink("message");
	sem_unlink("stop");
	sem_unlink("last_meaal");
	sem_unlink("forks");
	prg->death = sem_open("death", O_CREAT, 0600, 1);
	prg->message = sem_open("message", O_CREAT, 0600, 1);
	prg->stop = sem_open("stop", O_CREAT, 0600, 1);
	prg->last_meaal = sem_open("last_meaal", O_CREAT, 0600, 1);
	prg->forks = sem_open("forks", O_CREAT, 0600,
			prg->philo_numbers);
}

void	finish_all(t_program *prg, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < prg->philo_numbers)
		kill(philo[i++].pid, SIGKILL);
	sem_close(prg->death);
	sem_close(prg->message);
	sem_close(prg->stop);
	sem_close(prg->last_meaal);
	sem_close(prg->forks);
	free(philo);
}

void	inisialize_philosophers(t_program *prg)
{
	int		i;

	i = -1;
	prg->philos = malloc(sizeof(t_philo) * prg->philo_numbers);
	if (!prg->philos)
		error_message(prg, 1);
	while (++i < prg->philo_numbers)
	{
		prg->philos[i].index = i;
		prg->philos[i].is_dead = 0;
		prg->philos[i].data = prg;
		prg->philos[i].pid = -1;
		if (prg->eat_counter == -1)
			prg->philos[i].eat_counter = -1;
		else
			prg->philos[i].eat_counter = prg->eat_counter;
	}
}

void	inisialize_data(t_program *prg, char **av)
{
	prg->philo_numbers = ft_atoi(av[1]);
	prg->time_to_die = ft_atoi(av[2]);
	prg->time_to_eat = ft_atoi(av[3]);
	prg->time_to_sleep = ft_atoi(av[4]);
	prg->start = what_time_now();
	if (av[5])
	{
		prg->eat_counter = ft_atoi(av[5]);
		prg->current_eat = 0;
		prg->max_eat = prg->eat_counter * prg->philo_numbers;
	}
	else
	{
		prg->eat_counter = -1;
		prg->current_eat = -1;
		prg->max_eat = -1;
	}
}

void	deliver_message(t_philo *philo, char *str)
{
	sem_wait(philo->data->message);
	printf("%lld %d %s\n", (what_time_now() - philo->data->start), \
		philo->index + 1, str);
	sem_post(philo->data->message);
}
