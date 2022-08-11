/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:35:25 by hhamdy            #+#    #+#             */
/*   Updated: 2022/08/11 11:15:50 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	size_t				i;
	unsigned long		n;
	int					mult;

	i = 0;
	mult = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		return (0);
	if (str[i] == '0')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i++] - '0');
		if (n > INT_MAX)
			return (0);
	}
	if (str[i])
		return (0);
	return (mult * (int )n);
}

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

void	display_msg(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit (1);
}

int	check_n_eat(t_philo *data)
{
	int	index;
	int	flag;

	index = 0;
	flag = 0;
	if (data->n_must_eat == -1)
		return (1);
	while (index < data->n_philo)
	{
		if (data->n_eat[index] >= data->n_must_eat)
			flag++;
		index++;
	}
	if (flag == data->n_must_eat)
		return (0);
	return (1);
}

long long	ft_get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}
