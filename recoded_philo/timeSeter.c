/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeSeter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:02:14 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/21 17:14:37 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void printer(philo_id *philo,char *str, int id)
{
	pthread_mutex_lock(philo->prtintMtx);
	printf("%lu %d %s\n",timeSeter() - philo->startOn,id,str);
	pthread_mutex_unlock(philo->prtintMtx);
}
unsigned long	timeSeter(void)
{
	unsigned long	fractions;
	unsigned long	sec;
	unsigned long	mSec;
	struct timeval	clock;

	sec = 0;
	mSec = 0;
	gettimeofday(&clock, NULL);
	sec = (clock.tv_sec * 1000);
	mSec = (clock.tv_usec / 1000);
	fractions = sec + mSec;
	return (fractions);
}