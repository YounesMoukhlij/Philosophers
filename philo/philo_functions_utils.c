/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_functions_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:38:02 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/13 17:24:22 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	a_lonely_philo(t_program *prg)
{
	print_func(prg->philos, "has taken a fork");
}

int	ft_atoi(char *s)
{
	long	r;
	int		sign;

	r = 0;
	sign = 1;
	while (*s && (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s && (*s >= '0' && *s <= '9'))
	{
		r = r * 10 + *s - 48;
		if (r > INT_MAX || r < INT_MIN)
			error_parsing(1);
		s++;
	}
	return (r * sign);
}

long long	what_time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	time_between_taches(long long time, t_program *prg)
{
	long long	i;

	i = what_time_now();
	while (!(prg->dead))
	{
		if (what_time_now() - i >= time)
			break ;
		usleep(50);
	}
}

void	print_func(t_philo *prg, char *str)
{
	t_program	*p;

	p = prg->philos_infos;
	pthread_mutex_lock(&(p->print_habbit));
	if (!(p->dead))
		printf("%lld %d %s\n", (what_time_now() - p->time_start), \
		prg->philo_id, str);
	pthread_mutex_unlock(&p->print_habbit);
}
