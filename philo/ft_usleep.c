/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 19:13:16 by hhamdy            #+#    #+#             */
/*   Updated: 2022/08/12 19:19:14 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int n_sleep)
{
	long long	start;

	start = ft_get_time();
	while (ft_get_time() - start < n_sleep)
		usleep(100);
}
