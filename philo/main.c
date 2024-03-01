/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youmoukh <youmoukh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:29:50 by youmoukh          #+#    #+#             */
/*   Updated: 2024/02/23 19:09:00 by youmoukh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_program	prg;

	ft_parse_param(ac, av);
	init_all_infos(&prg, av);
	init_mutex(&prg);
	wake_up_philosophers(&prg);
	philos_life(&prg);
	check_if_some_philo_is_dead(&prg, prg.philos);
	free_all_philos(&prg, prg.philos);
	return (0);
}
