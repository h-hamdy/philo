/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:59:03 by hhamdy            #+#    #+#             */
/*   Updated: 2022/08/16 14:25:18 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	inisalise_struct(char **av, t_philo *data)
{
	data->process = (pid_t *)malloc(sizeof(pid_t) * (ft_atoi(av[1])));
	if (!data->process)
		return ;
	data->n_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->last_eat = ft_get_time();
	data->n_eat = 0;
	if (!av[5])
		data->n_must_eat = -1;
	else
		data->n_must_eat = ft_atoi(av[5]);
}

void	set_up_philos(t_philo *data)
{
	pthread_t	thread;

	if (pthread_create(&thread, NULL, &routine, data) != 0)
		display_msg("pthread_create fail\n");
	while (1)
	{
		if (!check_n_eat(data))
			exit (0);
		sem_wait(data->lock);
		if (ft_get_time() - data->last_eat >= data->time_to_die)
		{
			sem_wait(data->message);
			printf("%lld ms %d, died.\n", ft_get_time()
				- data->start_time, data->philo_id + 1);
			exit (1);
		}
		sem_post(data->lock);
	}
}

void	create_philos(t_philo *data)
{
	int		index;
	pid_t	p_id;

	index = 0;
	data->start_time = ft_get_time();
	while (index < data->n_philo)
	{
		data->philo_id = index;
		p_id = ft_fork();
		if (p_id == 0)
			set_up_philos(data);
		data->process[index] = p_id;
		usleep(100);
		index++;
	}
	while (waitpid(-1, &index, 0) != -1)
	{
		if (index)
		{
			index = 0;
			while (index++ < data->n_philo)
				kill(data->process[index], SIGKILL);
			exit (1);
		}
	}
}

void	open_semaphore(t_philo *data)
{
	sem_unlink("forks");
	sem_unlink("lock_message");
	sem_unlink("lock");
	data->forks = sem_open("forks", O_CREAT, 0644, data->n_philo);
	data->message = sem_open("lock_message", O_CREAT, 0644, 1);
	data->lock = sem_open("lock", O_CREAT, 0644, 1);
}

void	alloc_fill_struct(char **av)
{
	t_philo	*data;

	data = (t_philo *)malloc(sizeof(t_philo));
	if (!data)
		return ;
	inisalise_struct(av, data);
	open_semaphore(data);
	create_philos(data);
}
