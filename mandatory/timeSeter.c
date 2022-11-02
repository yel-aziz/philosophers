/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeSeter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:02:14 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/28 00:01:24 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printer(t_philo_id *philo, char *str, int id)
{
	pthread_mutex_lock(philo->prtintmtx);
	printf("%lu %d %s\n", timeseter() - philo->starton, id, str);
	pthread_mutex_unlock(philo->prtintmtx);
}

unsigned long	timeseter(void)
{
	unsigned long	fractions;
	unsigned long	sec;
	unsigned long	msec;
	struct timeval	clock;

	sec = 0;
	msec = 0;
	gettimeofday(&clock, NULL);
	sec = (clock.tv_sec * 1000);
	msec = (clock.tv_usec / 1000);
	fractions = sec + msec;
	return (fractions);
}
