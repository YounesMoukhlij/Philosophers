
#include "philosophers.h"

int	init_infos(t_philo *philo, char **av, int ac)
{
	philo->philo_members = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (ac == 5)
		philo->times_each_philo_must_eat = 0;
	else
		philo->times_each_philo_must_eat = ft_atoi(av[5]);
	if (philo->philo_members == 0 || philo->time_to_die == 0
		|| philo->time_to_eat == 0 || philo->time_to_sleep == 0)
		return (1);
	return (0);
}
