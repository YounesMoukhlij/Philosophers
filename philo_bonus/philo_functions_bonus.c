/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_functions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:37:25 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/05 16:37:28 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
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
