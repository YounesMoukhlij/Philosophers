/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:53:44 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/17 17:53:45 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "philosopher_bonus.h"

long long	ft_get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

long long	ft_current_time(t_philo *philo)
{
	long long time;

	time = ft_get_time() - philo->info->creation_time;
	return (time);
}
