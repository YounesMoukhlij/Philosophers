
#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_philo
{
	int		philo_members;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		times_each_philo_must_eat;
}	t_philo;

// UTILS
int		ft_strlen(char *s);
void	error_parsing(int mode);
int		ft_atoi(char *s);
void	error_message(t_philo *philo, int mode);

// CORE FUNC
int		main(int ac, char **av);
int		init_infos(t_philo *philo, char **av, int ac);
void	ft_parse_the_philos(int ac, char **av);

#endif
