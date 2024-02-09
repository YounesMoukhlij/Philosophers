/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:04:54 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/09 13:31:03 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	error_parsing(int mode)
{
	write(2, "Error\n", 6);
	if (mode == 0)
		write(2, "Invalid Argument!\n", 19);
	if (mode == 1)
		write(2, "You depassed integers try 0 < n < INT_MAX!\n", 44);
	if (mode == 2)
		write(2, "Emm something smells fishy! Try AGAIN\n", 39);
	if (mode == 3)
		write(2, "Numbers not valid\n", 19);
	exit(1);
}
