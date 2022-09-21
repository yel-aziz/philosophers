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
            printer(philo, "is dead", philo->id);
            destroy(mtx, pmtx, philo);
            return(0);
        }
        if (philo->life->philoFull == philo_life->number_of_philos)
        {
            destroy(mtx, pmtx, philo);
            return(0);
        }
        i = ((i + 1) % philo_life->number_of_philos);
        usleep(50);
    }
}