/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_infos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:43:44 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/09 13:46:18 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_if_dead(t_program *prg)
{
	int	i;

	while (prg->philo_all_eaten == 0)
	{
		i = -1;
		while (++i < prg->philo_members)
		{ // test every philo
			pthread_mutex_lock(&(prg->check_if_dead));
			if ((what_time_now() - prg->philo->dernier_repas) >= prg->time_to_die)
			{
				print_func(prg->philo, "is dead");
				prg->dead = 1;
			}
			pthread_mutex_unlock(&(prg->check_if_dead));
			usleep(100);
		}
		if (prg->dead)
			break ;
		i = 0;
		while (prg->times_each_philo_must_eat != -1 && i < prg->philo_members && prg->philo[i].eaten_times >= prg->times_each_philo_must_eat)
			i++;
		if (i == prg->philo_members)
			prg->philo_all_eaten = 1;
	}
}





void	init_philosphers(t_program *prg)
{
	int		i;

	i = -1;
	prg->t_start = what_time_now();
	while (++i < prg->philo_members)
	{
		if (pthread_create(&(prg->philo[i].thread_philo), NULL, daily_philo_routine, &(prg->philo[i])))
			error_message(prg, 2);
		prg->philo[i].dernier_repas = what_time_now();
	}
	i = -1;
	while (++i < prg->philo_members)
		if (pthread_join(prg->philo[i].thread_philo, NULL))
			error_message(prg, 3);
	check_if_dead(prg);
}

void	init_mutex(t_program *prg)
{
	int	i;

	i = -1;
	prg->forks = malloc(sizeof(pthread_mutex_t) * prg->philo_members);
	if (!prg->forks)
		error_message(prg, 1);
	while (++i < prg->philo_members)
		if (pthread_mutex_init(&(prg->forks[i]), NULL))
			error_message(prg, 1);
	if (pthread_mutex_init(&(prg->check_if_dead), NULL))
		error_message(prg, 1);
	if (pthread_mutex_init(&(prg->eat_habbit), NULL))
		error_message(prg, 1);
	if (pthread_mutex_init(&(prg->print_habbit), NULL))
		error_message(prg, 1);
}

void	init_philo_infos(t_program *prg)
{
	int	i;

	i = -1;
	prg->philo = malloc(sizeof(t_philo) * prg->philo_members);
	if (!prg->philo)
		error_message(prg, 1);
	while (++i < prg->philo_members)
	{
		prg->philo[i].dernier_repas = 0;
		prg->philo[i].eaten_times = 0;
		prg->philo[i].phi_d = i + 1;
		prg->philo[i].left_fork_d = i + 1;
		prg->philo[i].right_fork_d = (i + 2) % prg->philo_members;
		prg->philo[i].philos_infos = prg;
	}
}

int	init_all_infos(t_program *prg, char **av, int ac)
{
	prg->philo_members = ft_atoi(av[1]);
	prg->time_to_die = ft_atoi(av[2]);
	prg->time_to_eat = ft_atoi(av[3]);
	prg->time_to_sleep = ft_atoi(av[4]);
	prg->philo_all_eaten = 0;
	prg->dead = 0;
	if (ac == 5)
		prg->times_each_philo_must_eat = -1;
	else
		prg->times_each_philo_must_eat = ft_atoi(av[5]);
	if (prg->time_to_die < 0 || prg->time_to_sleep < 0
		|| prg->time_to_eat < 0)
		return (1);
	init_philo_infos(prg);
	init_mutex(prg);
	init_philosphers(prg);
	return (0);
}
