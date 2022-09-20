/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker->c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:57:14 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/20 16:57:50 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int checker(philo_id *philo, philo_life *philo_life, pthread_mutex_t *mtx, pthread_mutex_t *pmtx)
{
    int i;
    i = 0;
     while (1)
    {
        if (timeSeter() - (unsigned long)philo[i].lastMeal > (unsigned long)philo_life->time_to_die)
        {
            printf("philo %d is dead\n",i);
            destroy(mtx, pmtx);
            return(0);
        }
        if (philo[i].nEat == philo_life->number_of_times_each_philosopher_must_eat)
        {
            destroy(mtx, pmtx);
            return(0);
        }
        i = ((i + 1) % philo_life->number_of_philos);
        usleep(500);   
    }
}