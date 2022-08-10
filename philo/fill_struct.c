/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:25:14 by hhamdy            #+#    #+#             */
/*   Updated: 2022/08/10 04:39:47 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	inisalise_struct(char **av, t_philo *data)
{
	int	n_fork;

	data->thread = (pthread_t *)malloc(sizeof(pthread_t) * (ft_atoi(av[1])));
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (ft_atoi(av[1])));
	data->last_eat = (long long *)malloc(sizeof(long long) * (ft_atoi(av[1])));
	data->n_eat = (int *)malloc(sizeof(int) * ft_atoi(av[1]));
	if (!data->thread || !data->forks || !data->last_eat)
		return ;
	data->n_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	if (!av[5])
		data->n_must_eat = -1;
	else
		data->n_must_eat = ft_atoi(av[5]);
	n_fork = 0;
	pthread_mutex_init(&data->l, 0);
	pthread_mutex_init(&data->p, 0);
	while (n_fork < data->n_philo)
	{
		pthread_mutex_init(&data->forks[n_fork], NULL);
		data->last_eat[n_fork] = ft_get_time();
		data->n_eat[n_fork] = 0;
		n_fork++;
	}
}

void	ft_usleep(int n_sleep)
{
	long long	start;

	start = ft_get_time();
	while (ft_get_time() - start < n_sleep)
		usleep(100);
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
		pthread_mutex_lock(&data->forks[p_id]);
		pthread_mutex_lock(&data->p);
		printf("%lld ms %d, has taken a fork.\n", ft_get_time() - data->start_time, p_id + 1);
		pthread_mutex_unlock(&data->p);

		pthread_mutex_lock(&data->forks[(p_id + 1) % data->n_philo]);
		pthread_mutex_lock(&data->p);
		printf("%lld ms %d, has taken a fork.\n", ft_get_time() - data->start_time, p_id + 1);
		pthread_mutex_unlock(&data->p);

		pthread_mutex_lock(&data->p);
		printf("%lld ms %d, is eating.\n", ft_get_time() -  data->start_time, p_id + 1);
		pthread_mutex_unlock(&data->p);
		pthread_mutex_lock(&data->l);
		data->n_eat[p_id] += 1;
		ft_usleep(data->time_to_eat);
		data->last_eat[p_id] = ft_get_time();
		pthread_mutex_unlock(&data->l);

		pthread_mutex_lock(&data->l);
		pthread_mutex_unlock(&data->forks[p_id]);
		pthread_mutex_unlock(&data->forks[(p_id + 1) % data->n_philo]);
		pthread_mutex_unlock(&data->l);

		pthread_mutex_lock(&data->p);
		printf("%lld ms %d, is sleeping.\n", ft_get_time() - data->start_time, p_id + 1);
		pthread_mutex_unlock(&data->p);
		ft_usleep(data->time_sleep);

		pthread_mutex_lock(&data->p);
		printf("%lld ms %d, is thinking.\n", ft_get_time() - data->start_time, p_id + 1);
		pthread_mutex_unlock(&data->p);
    }
	return (NULL);
}

void	create_philos(t_philo *data)
{
	int	index;

	index = 0;
	((t_philo *)data)->start_time = ft_get_time();
	while (index < data->n_philo)
	{
		pthread_mutex_lock(&data->l);
		data->philo_id = index;
		pthread_mutex_unlock(&data->l);
		if (pthread_create(&data->thread[index], NULL, &routine, data) != 0)
			display_msg("pthread_create fail\n");
		usleep(50);
		index += 2;
	}
	index = 1;
	while (index < data->n_philo)
	{
		pthread_mutex_lock(&data->l);
		data->philo_id = index;
		pthread_mutex_unlock(&data->l);
		if (pthread_create(&data->thread[index], NULL, &routine, data) != 0)
			display_msg("pthread_create fail\n");
		usleep(50);
		index += 2;
	}
}

void	alloc_fill_struct(int ac, char **av)
{
	t_philo	*data;
	int		index;
	int		i;

	index = 0;
	(void)ac;
	data = (t_philo *)malloc(sizeof(t_philo));
	if (!data)
		return ;
	inisalise_struct(av, data);
	create_philos(data);
	while (1)
	{
		i = 0;
		while (i < data->n_philo)
		{
			pthread_mutex_lock(&data->l);
			if (ft_get_time() - data->last_eat[i] >= data->time_to_die)
			{
				pthread_mutex_lock(&data->p);
				printf("%lld ms %d, is died.\n", ft_get_time() - data->start_time, i + 1);
				exit (1);
			}
			pthread_mutex_unlock(&data->l);
			usleep(50);
			i++;
		}
	}
}
