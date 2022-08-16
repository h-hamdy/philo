/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:25:14 by hhamdy            #+#    #+#             */
/*   Updated: 2022/08/16 15:34:44 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	allocate_struct(t_philo *data, char **av)
{
	data->thread = (pthread_t *)malloc(sizeof(pthread_t) * (ft_atoi(av[1])));
	data->forks = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * (ft_atoi(av[1])));
	data->last_eat = (long long *)malloc(sizeof(long long) * (ft_atoi(av[1])));
	data->n_eat = (int *)malloc(sizeof(int) * ft_atoi(av[1]));
	if (!data->thread || !data->forks || !data->last_eat || !data->n_eat)
		return ;
}

void	inisalise_struct(char **av, t_philo *data)
{
	int	n_fork;

	allocate_struct(data, av);
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

void	create_philos(t_philo *data, int index)
{
	data->start_time = ft_get_time();
	while (index < data->n_philo)
	{
		pthread_mutex_lock(&data->l);
		data->philo_id = index;
		pthread_mutex_unlock(&data->l);
		if (pthread_create(&data->thread[index], NULL, &routine, data) != 0)
			display_msg("pthread_create fail\n");
		pthread_join(data->thread[index], NULL);
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
		pthread_join(data->thread[index], NULL);
		usleep(50);
		index += 2;
	}
}

void	check_child_philos(t_philo *data)
{
	int	i;

	while (1)
	{
		i = 0;
		if (!check_n_eat(data))
			return ;
		while (i < data->n_philo)
		{
			pthread_mutex_lock(&data->l);
			if (ft_get_time() - data->last_eat[i] >= data->time_to_die)
			{
				pthread_mutex_lock(&data->p);
				printf("%lld ms %d, died.\n", ft_get_time()
					- data->start_time, i + 1);
				return ;
			}
			pthread_mutex_unlock(&data->l);
			i++;
		}
	}
}

void	alloc_fill_struct(char **av, t_philo *data)
{
	int	index;

	index = 0;
	inisalise_struct(av, data);
	create_philos(data, index);
	check_child_philos(data);
}
