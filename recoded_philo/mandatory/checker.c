/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:57:14 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/23 17:02:47 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int checker(philo_id *philo, philo_life *philo_life)
{
    int i;
    unsigned long time;
    i = 0;
    while (1)
    {
        if (philo->life->philoFull == philo_life->number_of_philos)
        {
            pthread_mutex_lock(philo->prtintMtx);
            return(0);
        }
        else if (timeSeter() - philo[i].lastMeal > (unsigned long)philo_life->time_to_die)
        {
            time = (timeSeter() - philo[i].startOn);
            pthread_mutex_lock(philo->prtintMtx);
            printf("%lu %d is dead",time, philo->id);
            return(0);
        }
        i = ((i + 1) % philo->life->number_of_philos);
       usleep(500);
    }
}