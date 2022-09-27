/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:31:58 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/28 00:55:03 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_routine_helper(t_philo_id *philo)
{
	pthread_mutex_lock(&(philo->mtx[philo->id - 1]));
	printer(philo, "has take a fork", philo->id);
	pthread_mutex_lock(&(philo->mtx[philo->id
			% philo->life->number_of_philos]));
	printer(philo, "has take a fork", philo->id);
	printer(philo, "is eating", philo->id);
	philo->lastmeal = timeseter();
}

void	*ft_routine(void *p)
{
	t_philo_id	*philo;

	philo = (t_philo_id *)p;
	philo->lastmeal = timeseter();
	while (1)
	{
		ft_routine_helper(philo);
		usleep((philo->life->time_to_eat * 1000));
		philo->neat++;
		if (philo->neat
			== philo->life->number_of_times_each_philosopher_must_eat)
			philo->life->philofull++;
		pthread_mutex_unlock(&philo->mtx[philo->id - 1]);
		pthread_mutex_unlock(&philo->mtx[philo->id
			% philo->life->number_of_philos]);
		printer(philo, "is sleeping", philo->id);
		usleep(philo->life->time_to_sleep * 1000);
		printer(philo, "is thinking", philo->id);
	}
	return (p);
}

int	ft_init(t_philo_id *philos, pthread_mutex_t *mtx, t_philo_life *philolife)
{
	int				i;
	pthread_mutex_t	pmtx;
	pthread_t		th;

	pthread_mutex_init(&pmtx, NULL);
	i = 0;
	while (i < philolife->number_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].mtx = mtx;
		philos[i].life = philolife;
		philos[i].neat = 0;
		philos[i].prtintmtx = &pmtx;
		philos[i].starton = timeseter();
		i++;
	}
	i = 0;
	while (i < philolife->number_of_philos)
	{
		pthread_create(&th, NULL, &ft_routine, &philos[i]);
		i++;
		usleep(500);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int				i;
	t_philo_id		*philoid;
	pthread_mutex_t	*mtx;
	t_philo_life	philolife;

	if (parcing(av, ac, &philolife) == 1)
		return (0);
	philoid = malloc(philolife.number_of_philos * sizeof(t_philo_id));
	if (!philoid)
		return (1);
	mtx = malloc(philolife.number_of_philos * sizeof(pthread_mutex_t));
	if (!mtx)
	{
		free (philoid);
		return (0);
	}
	i = 0;
	while (i < philolife.number_of_philos)
	{
		if (pthread_mutex_init(&(mtx[i]), NULL) != 0)
			return (1);
		i++;
	}
	ft_init(philoid, mtx, &philolife);
	checker(philoid, &philolife);
}
