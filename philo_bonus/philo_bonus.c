/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:50:24 by hhamdy            #+#    #+#             */
/*   Updated: 2022/08/15 15:51:58 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	err_handling(int ac, char **av)
{
	int	index;

	index = 1;
	while (index < ac)
	{
		if (!ft_atoi(av[index]) && ft_atoi(av[index]) <= 0)
		{
			display_msg("Argumets is not valid!\n");
			return (0);
		}
		index++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	if (ac > 6 || ac < 5)
	{
		display_msg("Number of argument invalid!\n");
		return (0);
	}
	if (!err_handling(ac, av))
		return (0);
	alloc_fill_struct(av);
	return (0);
}
