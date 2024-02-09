/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosphers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:50:49 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/09 18:03:59 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t mutex;

void	*daily_philo_routine(void *param)
{
	(void) param;
	int *n = (int *)param;
	int i = -1;
	pthread_mutex_lock(&mutex);
	while (++i < 100)
	{
		(*n)++;
		i++;
	}
	pthread_mutex_unlock(&mutex);
	return (NULL);
}


int	init_philosphers(t_program *prg)
{
	int	i;

	i = -1;
	int *n;
	pthread_mutex_init(&mutex, NULL);

	n = malloc(sizeof(int));
	*n = 0;
	while (++i < prg->philo_members)
	{
		if (pthread_create(&(prg->philo[i].thread_philo), NULL, daily_philo_routine, n))
			error_message(prg, 2);
	}
	i = -1;
	while (++i < prg->philo_members)
	{
		if (pthread_join(prg->philo[i].thread_philo, NULL))
			error_message(prg, 3);
	}

	pthread_mutex_destroy(&mutex);
	printf(">>>>> %d\n", *n);
	return (0);
}

mlx_key_hook(mlx, 2, 0 , salah)

void salah(void *)
{
	
}