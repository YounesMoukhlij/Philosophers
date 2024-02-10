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

void	print_func(t_philo *prg, char *str)
{
	(void) prg;

	printf("%lld %d %s\n", (what_time_now() - prg->t_start) % 10, prg->phi_d, str);

}


int	is_not_dead(t_philo *prg)
{
	if (prg->eaten_times == 5)
		return (0);
	return (1);
}

void	philo_eat(t_philo *philo, t_program *prg)
{
	pthread_mutex_lock(&prg->forks[philo->left_fork]);
	print_func(philo, "has taken a fork");
	pthread_mutex_lock(&prg->forks[philo->right_fork]);
	print_func(philo, "has taken a fork");
	print_func(philo, "is eating");
	philo->dernier_repas = what_time_now();
	philo->eaten_times++;
	pthread_mutex_unlock(&prg->forks[philo->right_fork]);
	pthread_mutex_unlock(&prg->forks[philo->right_fork]);
}

void	*daily_philo_routine(void *param)
{
	t_philo		*philo;
	t_program	*prg;

	philo = (t_philo *)param;
	prg = philo->philos_infos;
	philo->t_start = what_time_now();
	while (is_not_dead(philo) != 0)
	{
		philo_eat(philo, prg);
		// philo_think(prg);
		// philo_sleep(prg);
	}

	return (NULL);
}



