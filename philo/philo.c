/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:56:20 by hhamdy            #+#    #+#             */
/*   Updated: 2022/08/16 08:50:50 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	t_philo	*data;

	if (ac > 6 || ac < 5)
	{
		display_msg("Number of argument invalid!\n");
		return (0);
	}
	if (!err_handling(ac, av))
		return (0);
	data = (t_philo *)malloc(sizeof(t_philo));
	if (!data)
		return (1);
	alloc_fill_struct(av, data);
	return (0);
}
