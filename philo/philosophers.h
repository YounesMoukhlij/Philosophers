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
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_t	thread_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			times_each_philo_must_eat;
	// int			nbr_forks;
	// int			fork_left;
	// int			fork_right;
}	t_philo;

typedef struct s_program
{
	int			philo_members;
	t_philo		*philo;
}	t_program;

// UTILS
int		ft_strlen(char *s);
void	error_parsing(int mode);
int		ft_atoi(char *s);
void	error_message(t_program *philo, int mode);

// CORE FUNC
int		main(int ac, char **av);
int		init_infos(t_program *prg, char **av, int ac);
void	ft_parse_the_philos(int ac, char **av);
int		init_philosphers(t_program *prg);


#endif
