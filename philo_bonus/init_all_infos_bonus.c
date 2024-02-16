/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_infos_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:30:05 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/16 21:23:11 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	init_semaphores(t_program *prg)
{
	sem_unlink("/death");
	sem_unlink("/print");
	sem_unlink("/forks");
	prg->death = sem_open("/death", O_CREAT, 0660, 0);
	if (prg->death == SEM_FAILED)
		error_message(prg, 6);
	prg->forks = sem_open("/forks", O_CREAT, 0660, prg->philo_members);
	if (prg->forks == SEM_FAILED)
		error_message(prg, 6);
	prg->print = sem_open("/print", O_CREAT, 0660, 0);
	if (prg->print == SEM_FAILED)
		error_message(prg, 6);
	prg->eat = sem_open("/eat", O_CREAT, 0660, 0);
	if (prg->eat == SEM_FAILED)
		error_message(prg, 6);
}

void	wake_up_philosophers(t_program *prg)
{
	int	i;

	i = -1;
	prg->philos = malloc(sizeof(t_philo) * prg->philo_members);
	if (!(prg->philos))
		error_message(prg, 1);
	while (++i < prg->philo_members)
	{
		prg->philos[i].eaten_times = 0;
		prg->philos[i].philos_infos = prg;
		prg->philos[i].last_meal_time = 0;
		prg->philos[i].philo_id = i + 1;
	}
}

void	init_all_infos(t_program *prg, char **av)
{
	prg->philo_members = ft_atoi(av[1]);
	prg->time_to_die = ft_atoi(av[2]);
	prg->time_to_eat = ft_atoi(av[3]);
	prg->time_to_sleep = ft_atoi(av[4]);
	prg->philo_all_ate = 0;
	prg->is_dead = 0;
	if (av[5])
		prg->times_philo_eats = ft_atoi(av[5]);
	else
		prg->times_philo_eats = -1;
}
