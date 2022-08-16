/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:53:54 by hhamdy            #+#    #+#             */
/*   Updated: 2022/08/16 14:25:58 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_take_fork(t_philo *data, int p_id)
{
	sem_wait(data->forks);
	sem_wait(data->message);
	printf("%lld ms %d, has taken a fork.\n", ft_get_time()
		- data->start_time, p_id + 1);
	sem_post(data->message);
	sem_wait(data->forks);
	sem_wait(data->message);
	printf("%lld ms %d, has taken a fork.\n", ft_get_time()
		- data->start_time, p_id + 1);
	sem_post(data->message);
}

void	ft_eat(t_philo *data, int p_id)
{
	sem_wait(data->message);
	printf("%lld ms %d, is eating.\n", ft_get_time()
		- data->start_time, p_id + 1);
	sem_post(data->message);
	sem_wait(data->lock);
	data->last_eat = ft_get_time();
	sem_post(data->lock);
	ft_usleep(data->time_to_eat);
	sem_post(data->forks);
	sem_post(data->forks);
	sem_wait(data->lock);
	if (data->n_must_eat != -1)
		data->n_eat += 1;
	sem_post(data->lock);
}

void	ft_sleep(t_philo *data, int p_id)
{
	sem_wait(data->message);
	printf("%lld ms %d, is sleeping.\n", ft_get_time()
		- data->start_time, p_id + 1);
	sem_post(data->message);
	ft_usleep(data->time_sleep);
}

void	ft_think(t_philo *data, int p_id)
{
	sem_wait(data->message);
	printf("%lld ms %d, is thinking.\n", ft_get_time()
		- data->start_time, p_id + 1);
	sem_post(data->message);
}

void	*routine(void *philo)
{
	int		p_id;
	t_philo	*data;

	data = (t_philo *)philo;
	p_id = ((t_philo *)data)->philo_id;
	while (data->n_must_eat == -1 || data->n_eat < data->n_must_eat)
	{
		ft_take_fork(data, p_id);
		ft_eat(data, p_id);
		ft_sleep(data, p_id);
		ft_think(data, p_id);
	}
	return (NULL);
}
