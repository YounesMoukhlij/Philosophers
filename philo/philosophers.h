/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:43:56 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/09 16:48:56 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <sys/time.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_philo
{
	int					phi_d;
	int					eaten_times;
	int					left_fork_d;
	pthread_t			thread_philo;
	int					right_fork_d;
	int					dernier_repas;
	struct s_program	*philos_infos;
}	t_philo;

typedef struct s_program
{
	int				philo_members;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_each_philo_must_eat;
	int				philo_all_eaten;
	long long		t_start;
	int				dead;
	pthread_mutex_t	eat_habbit;
	pthread_mutex_t	print_habbit;
	pthread_mutex_t	check_if_dead;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}	t_program;

// UTILS
int			ft_strlen(char *s);
void		error_parsing(int mode);
int			ft_atoi(char *s);
long long	what_time_now(void);
void		print_func(t_philo *prg, char *str);
void		error_message(t_program *philo, int mode);

// CORE FUNC
int		main(int ac, char **av);
int		init_all_infos(t_program *prg, char **av, int ac);
void	ft_parse_param(int ac, char **av);
void	init_philosphers(t_program *prg);
void	*daily_philo_routine(void *param);

#endif
