/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:56:20 by hhamdy            #+#    #+#             */
/*   Updated: 2022/07/03 15:49:15 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int main(int ac, char **av)
{
	if (ac > 6 || ac < 5)
		display_msg("Number of argument invalid!\n");
	err_handling(ac, av);
	alloc_fill_struct(ac, av);
	return (0);
}
