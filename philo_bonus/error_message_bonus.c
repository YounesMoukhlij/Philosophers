/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:54:28 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/05 16:37:02 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"


void	error_message(t_philo *philo, int mode)
{
	(void) philo;

	write(2, "Error\n", 6);
	if (mode == 0)
		write(2, "what ever!\n", 11);
	exit(EXIT_FAILURE);
}
