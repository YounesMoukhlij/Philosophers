/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:39:23 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/19 19:15:48 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

int	main(int ac, char **av)
{
	t_program	prg;

	ft_parse_param(ac, av);
	inisialize_data(&prg, av);
	inisialize_philosophers(&prg);
	inisialize_semaphores(&prg);
	sem_wait(prg.stop);
	inisialize_process(&prg, prg.philos);
	sem_wait(prg.stop);
	free_all(&prg, prg.philos);
}
