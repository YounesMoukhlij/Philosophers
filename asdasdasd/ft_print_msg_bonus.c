/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_msg_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:03:06 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/17 17:03:10 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philosopher_bonus.h"


void	ft_print_msg(t_philo *philo, char *msg)
{
	if (!philo->should_die)
		printf("%lli\t%i\t%s\n", ft_current_time(philo), philo->id + 1, msg);
}
