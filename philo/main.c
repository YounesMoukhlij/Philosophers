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

int	main(int ac, char **av)
{
	t_program	philo;
	
	ft_parse_the_philos(ac, av);
	if (init_infos(&philo, av, ac))
		return (1);
	if (init_philosphers(&philo))
		return (1);
	int i = -1;
	while (++i <  philo.philo_members)
	{
		printf("%d %d %d %d %d\n", philo.philo_members, \
			philo.philo[i].time_to_die, \
			philo.philo[i].time_to_eat, \
			philo.philo[i].time_to_sleep, \
			philo.philo[i].times_each_philo_must_eat);
	}
	return (0);
}
