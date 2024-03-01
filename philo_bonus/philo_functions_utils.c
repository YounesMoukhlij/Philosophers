/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_functions_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:38:02 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/23 18:05:25 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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

void	time_between_taches(long long time)
{
	long long	i;

	i = what_time_now();
	while (1)
	{
		if (what_time_now() - i >= time)
			break ;
		usleep(100);
	}
}

int	check_one(t_philo *philo)
{
	sem_wait(philo->data->death);
	if (philo->next_meal < what_time_now())
	{
		deliver_message(philo, "died");
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
