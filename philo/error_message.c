/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:04:58 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/09 15:01:21 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	error_message(t_program *philo, int mode)
{
	(void) philo;

	write(2, "Error\n", 6);
	if (mode == 0)
		write(2, "what ever!\n", 11);
	if (mode == 1)
		write(2, "Malloc Failed!\n", 16);
	if (mode == 2)
		write(2, "Error creating threads!\n", 25);
	if (mode == 3)
		write(2, "Error joing threads!\n", 22);
	exit(EXIT_FAILURE);
}
