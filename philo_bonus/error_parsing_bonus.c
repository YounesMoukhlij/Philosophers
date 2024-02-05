/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:54:32 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/05 16:36:58 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	error_parsing(int mode)
{
	write(2, "Error\n", 6);
	if (mode == 0)
		write(2, "Invalid Argument!\n", 19);
	if (mode == 1)
		write(2, "You depassed integers try INT_MIN < n < INT_MAX!\n", 50);
	if (mode == 2)
		write(2, "Emm something smells fishy! Try AGAIN\n", 39);
	exit(1);
}
