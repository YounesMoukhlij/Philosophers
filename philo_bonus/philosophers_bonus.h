/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:37:37 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/23 19:10:26 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <stdio.h>
# include <limits.h>
# include <semaphore.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <signal.h>

typedef struct s_philo
{
	struct s_program	*data;
	pid_t				pid;
	long long			eating_time;
	long long			next_meal;
	int					index;
	int					is_dead;
	int					eat_counter;
}				t_philo;

typedef struct s_program
{
	sem_t			*forks;
	sem_t			*message;
	sem_t			*death;
	sem_t			*last_meaal;
	sem_t			*stop;
	long long		start;
	int				philo_numbers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_counter;
	int				max_eat;
	t_philo			*philos;
	int				current_eat;
}				t_program;

void			inisialize_data(t_program *prg, char **av);
void			ft_parse_param(int ac, char **av);
int				ft_atoi(char *s);
void			error_parsing(int mode);
void			error_message(t_program *philo, int mode);
long long		what_time_now(void);
void			time_between_taches(long long time);
int				check_two(t_philo *philo);
int				check_one(t_philo *philo);
void			ft_routine(t_philo *philo);
void			*ft_check_death(void *arg);
void			deliver_message(t_philo *philo, char *str);
void			inisialize_philosophers(t_program *prg);
void			inisialize_semaphores(t_program *prg);
int				ft_parsing(char **av, t_program *prg);
void			finish_all(t_program *prg, t_philo *philo);

#endif
