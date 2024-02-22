/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:45:34 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/22 19:21:30 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_all_philos(t_program *prg, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < prg->philo_members)
		pthread_join(philos[i].thread_id, NULL);
	i = -1;
	while (++i < prg->philo_members)
		pthread_mutex_destroy(&(prg->forks[i]));
	pthread_mutex_destroy(&(prg->print_habbit));
	pthread_mutex_destroy(&(prg->eat_habbit));
	pthread_mutex_destroy(&(prg->death));
	free(prg->forks);
	free(prg->philos);
}

int	is_dead(t_program *prg)
{
	pthread_mutex_lock(&prg->death);
	if (prg->dead == 0)
		return (pthread_mutex_unlock(&prg->death), 0);
	pthread_mutex_unlock(&prg->death);
	return (1);
}
