/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:09:32 by hhamdy            #+#    #+#             */
/*   Updated: 2022/08/16 13:37:06 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct t_philo
{
	pid_t				*process;
	sem_t				*forks;
	sem_t				*message;
	sem_t				*lock;
	int					n_eat;
	int					philo_id;
	int					n_philo;
	long long			start_time;
	int					time_to_die;
	int					time_to_eat;
	int					time_sleep;
	int					n_must_eat;
	long long			last_eat;
}				t_philo;

void		display_msg(char *msg);
int			ft_strlen(char *str);
int			ft_atoi(char *str);
long long	ft_get_time(void);
void		ft_usleep(int n_sleep);
void		alloc_fill_struct(char **av);
pid_t		ft_fork(void);
void		*routine(void *philo);
void		ft_usleep(int n_sleep);
int			check_n_eat(t_philo *data);

#endif