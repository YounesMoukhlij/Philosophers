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

// void	check_if_dead(t_program *prg)
// {
// 	int	i;

// 	while (!(r->all_ate))
// 	{
// 		i = -1;
// 		while (++i < r->nb_philo && !(r->dieded))
// 		{
// 			pthread_mutex_lock(&(r->meal_check));
// 			if (time_diff(p[i].t_last_meal, timestamp()) > r->time_death)
// 			{
// 				action_print(r, i, "died");
// 				r->dieded = 1;
// 			}
// 			pthread_mutex_unlock(&(r->meal_check));
// 			usleep(100);
// 		}
// 		if (r->dieded)
// 			break ;
// 		i = 0;
// 		while (r->nb_eat != -1 && i < r->nb_philo && p[i].x_ate >= r->nb_eat)
// 			i++;
// 		if (i == r->nb_philo)
// 			r->all_ate = 1;
// 	}
// }





void	init_philosphers(t_program *prg)
{
	int		i;

	i = -1;
	while (++i < prg->philo_members)
		if (pthread_create(&(prg->philo[i].thread_philo), NULL, daily_philo_routine, &(prg->philo[i])))
			error_message(prg, 2);
	i = -1;
	while (++i < prg->philo_members)
		if (pthread_join(prg->philo[i].thread_philo, NULL))
			error_message(prg, 3);
	// check_if_dead(prg);

}

void	init_mutex(t_program *prg)
{
	int	i;

	i = -1;
	prg->forks = malloc(sizeof(pthread_mutex_t) * prg->philo->forks_number);
	if (!prg->forks)
		error_message(prg, 1);
	while (++i < prg->philo->forks_number)
		if (pthread_mutex_init(&(prg->forks[i]), NULL))
			error_message(prg, 1);
	if (pthread_mutex_init(&(prg->think_habbit), NULL))
		error_message(prg, 1);
	if (pthread_mutex_init(&(prg->eat_habbit), NULL))
		error_message(prg, 1);
	if (pthread_mutex_init(&(prg->print_habbit), NULL))
		error_message(prg, 1);
}

int	init_all_infos(t_program *prg, char **av, int ac)
{
	int	i;

	i = -1;
	prg->philo_members = ft_atoi(av[1]);
	prg->philo = malloc(sizeof(t_philo) * prg->philo_members);
	if (!prg->philo)
		error_message(prg, 1);
	while (++i < prg->philo_members)
	{
		prg->philo[i].time_to_die = ft_atoi(av[2]);
		prg->philo[i].time_to_eat = ft_atoi(av[3]);
		prg->philo[i].time_to_sleep = ft_atoi(av[4]);
		prg->philo[i].forks_number = prg->philo_members;
		prg->philo[i].dernier_repas = 0;
		prg->philo[i].eaten_times = 0;
		prg->philo[i].phi_d = i + 1;
		prg->philo[i].left_fork = i + 1;
		prg->philo[i].right_fork = (i + 2) % prg->philo_members;
		prg->philo[i].t_start = 0;
		if (ac == 5)
			prg->philo[i].times_each_philo_must_eat = -1;
		else
			prg->philo[i].times_each_philo_must_eat = ft_atoi(av[5]);
		prg->philo[i].philos_infos = prg;
	}
	init_mutex(prg);
	init_philosphers(prg);
	return (0);
}
