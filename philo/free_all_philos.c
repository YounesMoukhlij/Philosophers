/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:45:34 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/20 17:56:45 by youmoukh         ###   ########.fr       */
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
	pthread_mutex_destroy(&(prg->stop));
	free(prg->forks);
	free(prg->philos);
}

int	is_dead(t_program *prg)
{
	if (prg->dead == 0)
		return (0);
	return (1);
}
