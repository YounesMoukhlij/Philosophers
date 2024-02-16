/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:28:29 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/16 21:00:04 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <semaphore.h>
# include <pthread.h>

typedef struct s_philo
{
	int					philo_id;
	pthread_t			thread_id;
	int					philo_pid;
	int					eaten_times;
	struct s_program	*philos_infos;
	long long			last_meal_time;
}	t_philo;

typedef struct s_program
{
	sem_t		*eat;
	sem_t		*forks;
	sem_t		*death;
	sem_t		*print;
	int			is_dead;
	t_philo		*philos;
	long long	time_start;
	int			time_to_die;
	int			time_to_eat;
	int			philo_members;
	int			time_to_sleep;
	int			philo_all_ate;
	int			times_philo_eats;
}	t_program;

int			ft_atoi(char *str);
long long	what_time_now(void);
int			is_dead(t_program *prg);
void		error_parsing(int mode);
void		init_mutex(t_program *prg);
void		philos_life(t_program *rules);
void		init_semaphores(t_program *prg);
void		ft_parse_param(int ac, char **av);
void		wake_up_philosophers(t_program *prg);
void		init_all_infos(t_program *prg, char **av);
void		error_message(t_program *philo, int mode);
void		print_func(t_philo *prg, char *str);
void		free_all_philos(t_program *prg, t_philo *philos);
void		time_between_taches(long long time, t_program *prg);
void		*check_if_some_philo_is_dead(void *param);




void	show(void);

#endif
