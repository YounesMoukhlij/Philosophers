/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:55:13 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/17 17:17:22 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	ft_free_all(t_info *info)
{
	int	ret;
	int	i;

	i = -1;
	while (++i < info->number_of_philosophers)
	{
		waitpid(-1, &ret, 0);
		if (ret != 0)
		{
			i = 0;
			while (i < info->number_of_philosophers)
				kill(info->id_table[i++], SIGKILL);
			break ;
		}
	}
	sem_close(info->forks);
	free(info->id_table);
	free(info);
}
