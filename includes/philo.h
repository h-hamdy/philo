/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:56:24 by hhamdy            #+#    #+#             */
/*   Updated: 2022/07/04 13:52:00 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>

typedef	struct t_philo
{
    pthread_t			*thread;
    pthread_mutex_t		*forks;
    int					n_philo;
    int                 philo_id;
    int					time_to_die;
    int					time_to_eat;
    int					time_sleep;
    int					n_must_eat;
}				t_philo;

void	display_msg(char *msg);
int		ft_strlen(char *str);
void	err_handling(int ac, char **av);
void	alloc_fill_struct(int ac, char **av);
int     ft_atoi(char *str);

#endif
