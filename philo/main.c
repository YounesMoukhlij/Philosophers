/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:43:15 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/09 14:25:49 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void show(void)
{
	system("leaks mmmm");
}

void	free_philos(t_program *philo)
{
	int	i;

	i = -1;
	while (++i < philo->philo_members)
		pthread_mutex_destroy(&(philo->forks[i]));
	pthread_mutex_destroy(&(philo->print_habbit));
	pthread_mutex_destroy(&(philo->check_if_dead));
	free(philo->philo);
	free(philo->forks);
}

int	main(int ac, char **av)
{
	t_program	philo;

	// atexit(show);
	ft_parse_param(ac, av);
	if (init_all_infos(&philo, av, ac))
		error_message(&philo, 4);

	int i = -1;

	while (++i <  philo.philo_members)
	{
		printf("Num philos %d\nTime die %d\nTime eat %d/nTime sleep %d times of eat%d\n", philo.philo_members, \
			philo.time_to_die, \
			philo.time_to_eat, \
			philo.time_to_sleep, \
			philo.times_each_philo_must_eat);
	}
	free_philos(&philo);
	puts("Program ended\n");
	return (0);
}
