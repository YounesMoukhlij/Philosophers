/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sem_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:02:12 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/17 17:48:22 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

int	ft_init_sem(t_info *info)
{
	info->forks = sem_open("sem", O_CREAT | O_EXCL, 0644,
			info->number_of_philosophers);
	if (info->forks == SEM_FAILED || sem_unlink("sem"))
		ft_puterr("ft_init_sem:12 - error initializing semaphore\n");
	return (FT_SUCCESS);
}
