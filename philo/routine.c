/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 09:53:16 by hhamdy            #+#    #+#             */
/*   Updated: 2022/08/11 11:32:19 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_take_fork(t_philo *data, int p_id)
{
    pthread_mutex_lock(&data->forks[p_id]);
	pthread_mutex_lock(&data->p);
	printf("%lld ms %d, has taken a fork.\n", ft_get_time() - data->start_time, p_id + 1);
	pthread_mutex_unlock(&data->p);
    pthread_mutex_lock(&data->forks[(p_id + 1) % data->n_philo]);
	pthread_mutex_lock(&data->p);
	printf("%lld ms %d, has taken a fork.\n", ft_get_time() - data->start_time, p_id + 1);
	pthread_mutex_unlock(&data->p);
}

void    ft_eat(t_philo *data, int p_id)
{
    pthread_mutex_lock(&data->p);
	printf("%lld ms %d, is eating.\n", ft_get_time() - data->start_time, p_id + 1);
	pthread_mutex_lock(&data->l);
	data->n_eat[p_id] += 1;
	data->last_eat[p_id] = ft_get_time();
	pthread_mutex_unlock(&data->p);
	pthread_mutex_unlock(&data->l);
	ft_usleep(data->time_to_eat);
	pthread_mutex_unlock(&data->forks[p_id]);
	pthread_mutex_unlock(&data->forks[(p_id + 1) % data->n_philo]);
}

void    ft_sleep(t_philo *data, int p_id)
{
    pthread_mutex_lock(&data->p);
	printf("%lld ms %d, is sleeping.\n", ft_get_time() - data->start_time, p_id + 1);
	pthread_mutex_unlock(&data->p);
	ft_usleep(data->time_sleep);
}

void    ft_think(t_philo *data, int p_id)
{
    pthread_mutex_lock(&data->p);
	printf("%lld ms %d, is thinking.\n", ft_get_time() - data->start_time, p_id + 1);
	pthread_mutex_unlock(&data->p);
}

void	*routine(void *philo)
{
	int		p_id;
	t_philo	*data;

	data = (t_philo *)philo;
	pthread_mutex_lock(&data->l);
	p_id = ((t_philo *)data)->philo_id;
	pthread_mutex_unlock(&data->l);
	while (1)
	{
		ft_take_fork(data, p_id);
        ft_eat(data, p_id);
        ft_sleep(data, p_id);
        ft_think(data, p_id);
	}
	return (NULL);
}