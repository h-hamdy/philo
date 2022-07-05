/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:25:14 by hhamdy            #+#    #+#             */
/*   Updated: 2022/07/03 19:55:27 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	inisalise_struct(char **av, t_philo *data)
{
	int n_fork;

	data->thread = (pthread_t *)malloc(sizeof(pthread_t) * (ft_atoi(av[1])));
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (ft_atoi(av[1])));
	if (!data->thread || !data->forks)
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
	while (n_fork < data->n_philo)
	{
		pthread_mutex_init(&data->forks[n_fork], NULL);
		n_fork++;
	}
}

void	*routine(void *philo)
{
	return (NULL);
}

void	create_philos(t_philo *data)
{
	int index;

	index = 0;
	while (index < data->n_philo)
	{
		if (pthread_create(&data->thread[index], NULL, &routine, data) != 0)
			display_msg("pthread_create fail\n");
		index += 2;
	}
	index = 1;
	while (index < data->n_philo)
	{
		if (pthread_create(&data->thread[index], NULL, &routine, data) != 0)
			display_msg("pthread_create fail\n");
		index += 2;
	}
}

void	alloc_fill_struct(int ac, char **av)
{
	t_philo *data;

	(void)ac;
	data = (t_philo *)malloc(sizeof(t_philo));
	if (!data)
		return ;
	inisalise_struct(av, data);
	create_philos(data);
}