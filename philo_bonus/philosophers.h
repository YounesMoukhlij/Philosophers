/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:28:29 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/13 17:25:47 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <semaphore.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_t			thread_id;
	int					philo_pid;
	int					eaten_times;
	long long			last_meal_time;
	struct s_program	*philos_infos;
}	t_philo;

typedef struct s_program
{
	int			philo_members;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			times_philo_eats;
	int			dead;
	long long	time_start;
	sem_t		*forks;
	t_philo		*philos;
}	t_program;

int			ft_atoi(char *str);
long long	what_time_now(void);
int			is_dead(t_program *prg);
void		error_parsing(int mode);
void		init_mutex(t_program *prg);
void		philos_life(t_program *rules);
void		ft_parse_param(int ac, char **av);
void		wake_up_philosophers(t_program *prg);
void		init_all_infos(t_program *prg, char **av);
void		error_message(t_program *philo, int mode);
void		print_func(t_philo *prg, char *str);
void		free_all_philos(t_program *prg, t_philo *philos);
void		time_between_taches(long long time, t_program *prg);
void		check_if_some_philo_is_dead(t_program *r, t_philo *p);




void	show(void);

#endif
