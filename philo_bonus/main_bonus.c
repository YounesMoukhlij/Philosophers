
#include "philosophers_bonus.h"

int main(int ac, char **av)
{
	t_philo	philo;

	ft_parse_the_philos(ac, av);
	if (init_infos(&philo, av, ac))
		return (1);

	printf("%d %d %d %d %d\n", philo.philo_members, philo.time_to_die, philo.time_to_eat, philo.time_to_sleep, philo.times_each_philo_must_eat);
	return (0);
}
