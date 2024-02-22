
#include "philosophers_bonus.h"

int	check_one(t_philo *philo)
{
	sem_wait(philo->data->death);
	if (philo->next_meal < what_time_now())
	{
		ft_print_message(philo, "died");
		sem_post(philo->data->stop);
		return (1);
	}
	sem_post(philo->data->death);
	return (0);
}

int	check_two(t_philo *philo)
{
	sem_wait(philo->data->death);
	if ((philo->data->eat_counter != -1)
		&& (philo->data->current_eat >= philo->data->max_eat))
	{
		sem_post(philo->data->stop);
		return (1);
	}
	sem_post(philo->data->death);
	return (0);
}

void	*ft_check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (check_one(philo))
			break ;
		if (check_two(philo))
			break ;
	}
	return (NULL);
}

void	ft_routine(t_philo *philo)
{
	pthread_t	death;
	t_program	*prg;

	prg = philo->data;
	philo->next_meal = what_time_now() + prg->time_to_die;
	pthread_create(&death, NULL, ft_check_death, philo);
	while (1)
	{
		sem_wait(prg->forks);
		ft_print_message(philo, "has taken a fork");
		sem_wait(prg->forks);
		ft_print_message(philo, "has taken a fork");
		ft_print_message(philo, "is eating");
		if (prg->eat_counter != -1)
			prg->current_eat++;
		time_between_taches(prg->time_to_eat);
		philo->eating_time = what_time_now();
		philo->next_meal = philo->eating_time + prg->time_to_die;
		sem_post(prg->forks);
		sem_post(prg->forks);
		ft_print_message(philo, "is sleeping");
		time_between_taches(prg->time_to_sleep);
		ft_print_message(philo, "is thinking");
	}
	pthread_join(death, 0);
}

void	inisialize_process(t_program *prg, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < prg->philo_numbers)
	{
		philo[i].pid = fork();
		if (philo[i].pid == 0)
		{
			ft_routine(philo + i);
			exit(0);
		}
		i++;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	t_program	prg;

	ft_parse_param(ac, av);
	inisialize_data(&prg, av);
	inisialize_philosophers(&prg);
	inisialize_semaphores(&prg);
	sem_wait(prg.stop);
	inisialize_process(&prg, prg.philos);
	sem_wait(prg.stop);
	ft_destroy_all(&prg, prg.philos);
}
