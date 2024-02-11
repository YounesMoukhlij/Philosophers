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
	t_program	*p;

	p = prg->philos_infos;
	pthread_mutex_lock(&(p->print_habbit));
	printf("%lld %d %s\n", (what_time_now() - prg->t_start), prg->phi_d, str);
	pthread_mutex_unlock(&p->print_habbit);

}

void	time_between_taches(long long time, t_program *prg)
{
	(void) prg;
	long long	i;

	i = what_time_now();
	while (1)
	{
		if (what_time_now() - i >= time)
			break ;
		usleep(50);
	}
}

int	is_not_dead(t_philo *prg)
{
	if (prg->eaten_times == prg->times_each_philo_must_eat)
		return (0);
	return (1);
}

void	philo_eat(t_philo *philo, t_program *prg)
{
	pthread_mutex_lock(&(prg->forks[philo->left_fork]));
	print_func(philo, "has taken a fork");
	pthread_mutex_lock(&(prg->forks[philo->right_fork]));
	print_func(philo, "has taken a fork");
	pthread_mutex_lock(&(prg->eat_habbit));
	print_func(philo, "is eating");
	philo->dernier_repas = what_time_now();
	pthread_mutex_unlock(&(prg->eat_habbit));
	time_between_taches(philo->time_to_eat, prg);
	philo->eaten_times++;
	pthread_mutex_unlock(&(prg->forks[philo->left_fork]));
	pthread_mutex_unlock(&(prg->forks[philo->right_fork]));
}


void	*daily_philo_routine(void *param)
{
	t_philo		*philo;
	t_program	*prg;

	philo = (t_philo *)param;
	prg = philo->philos_infos;
	philo->t_start = what_time_now();
	if (philo->phi_d % 2 == 0)
		usleep(20000);
	while (is_not_dead(philo) != 0)
	{
		philo_eat(philo, prg);
		print_func(philo, "is sleeping");
		time_between_taches(philo->time_to_sleep, prg);
		print_func(philo, "is thinking");
	}
	return (NULL);
}



