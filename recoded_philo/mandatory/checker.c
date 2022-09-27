/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:57:14 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/28 00:01:57 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	checker(t_philo_id *philo, t_philo_life *philo_life)
{
	int				i;
	unsigned long	time;

	i = 0;
	while (1)
	{
		if (philo->life->philofull == philo_life->number_of_philos)
		{
			pthread_mutex_lock(philo->prtintmtx);
			return (0);
		}
		else if (timeseter() - philo[i].lastmeal
			> (unsigned long)philo_life->time_to_die)
		{
			time = (timeseter() - philo[i].starton);
			pthread_mutex_lock(philo->prtintmtx);
			printf("%lu %d is dead", time, philo->id);
			return (0);
		}
		i = ((i + 1) % philo->life->number_of_philos);
		usleep (500);
	}
}
