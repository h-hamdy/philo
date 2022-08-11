/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:56:20 by hhamdy            #+#    #+#             */
/*   Updated: 2022/08/11 09:47:07 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	err_handling(int ac, char **av)
{
	int	index;

	index = 1;
	while (index < ac)
	{
		if (!ft_atoi(av[index]) && ft_atoi(av[index]) <= 0)
			display_msg("Argumets is not valid!\n");
		index++;
	}
}

int	main(int ac, char **av)
{
	if (ac > 6 || ac < 5)
		display_msg("Number of argument invalid!\n");
	err_handling(ac, av);
	alloc_fill_struct(ac, av);
	return (0);
}
