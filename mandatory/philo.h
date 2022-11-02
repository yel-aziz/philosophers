/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:32:10 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/28 00:01:46 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct philo_life
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_philos;
	int	number_of_times_each_philosopher_must_eat;
	int	philofull;
}t_philo_life;

typedef struct philo_id
{
	int					id;
	pthread_mutex_t		*mtx;
	pthread_mutex_t		*prtintmtx;
	t_philo_life		*life;
	unsigned long		lastmeal;
	int					neat;
	unsigned long		starton;
}t_philo_id;

void			*ft_routine(void *p);
int				ft_atoi(const char *str);
unsigned long	timeseter(void);
void			printer(t_philo_id *philo, char *str, int id);
int				checker(t_philo_id *philo, t_philo_life *philo_life);
int				destroy(pthread_mutex_t *mtx, t_philo_id *philo);
int				parcing(char **av, int ac, t_philo_life *life);
#endif