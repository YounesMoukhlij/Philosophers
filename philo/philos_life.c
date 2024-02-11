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
void	time_between_taches(int time, t_program *prg)
{
	(void) prg;
	usleep(time * 1000);
}

int	is_not_dead(t_philo *prg)
{
	printf(">>> times must eat %d\n", prg->eaten_times);
	if (prg->eaten_times == prg->times_each_philo_must_eat)
		return (0);
	return (1);
}

void	philo_sleep(t_philo *prg, t_program *p)
{
	print_func(prg, "is sleeping");
	time_between_taches(prg->time_to_sleep, p);
}

void	philo_think(t_philo *prg, t_program *p)
{
	(void) p;
	// pthread_mutex_lock(&p->print_habbit);
	print_func(prg, "is thinking");
	// pthread_mutex_unlock(&p->print_habbit);
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
	time_between_taches(philo->time_to_eat, prg);
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
		// philo_sleep(philo, prg);
		// philo_think(philo, prg);
	}
	return (NULL);
}



