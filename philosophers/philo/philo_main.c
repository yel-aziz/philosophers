/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 00:10:56 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/05/09 22:01:55 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*ft_t_routine(void *p)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)p;
	if (philo->id % 2 == 0)
		usleep(10);
	philo->last_meal = time_stamp();
	while (1)
	{
		ft_eating(philo);
		philo->n++;
		if (philo->n == (unsigned long)
			philo->rot->number_of_times_each_philosopher_must_eat)
			philo->rot->philos_full++;
		usleep(philo->rot->time_to_eat * 1000);
		philo->last_meal = time_stamp();
		pthread_mutex_unlock(&philo->mtx[philo->id - 1]);
		pthread_mutex_unlock(&philo->mtx[philo->id
			% philo->rot->number_of_philosophers]);
		printing(philo, realy_time(philo), philo->id, "is sleeping");
		usleep(philo->rot->time_to_sleep * 1000);
		printing(philo, realy_time(philo), philo->id, "is thinking");
	}
	return (p);
}

int	main(int ac, char **av)
{
	t_routine			va;
	t_philosopher		*philos;
	int					i;	
	pthread_t			th;
	pthread_mutex_t		*mtx;

	if (ft_parcing(av, ac, &va) == 0)
	{
	
	
	philos = malloc(sizeof(t_philosopher) * va.number_of_philosophers);
	if (!philos)
		return (0);
	mtx = malloc(sizeof(pthread_mutex_t) * va.number_of_philosophers);
	if (!mtx)
		return (0);
	ft_init(philos, &va, mtx);
	i = 0;
	while (i < va.number_of_philosophers)
	{
		pthread_create(&th, NULL, &ft_t_routine, &philos[i]);
		usleep(100);
		i++;
	}
	ft_proc(&va, philos, mtx);
	}
}
