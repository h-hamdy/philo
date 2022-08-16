/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 16:41:32 by hhamdy            #+#    #+#             */
/*   Updated: 2022/08/15 22:17:54 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

pid_t	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		display_msg("Error while trying to fork.");
	return (pid);
}

void	ft_usleep(int n_sleep)
{
	long long	start;

	start = ft_get_time();
	while (ft_get_time() - start < n_sleep)
		usleep(100);
}
