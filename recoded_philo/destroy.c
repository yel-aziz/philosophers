/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:56:49 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/21 17:46:57 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void destroy(pthread_mutex_t *mtx, philo_id *philo, philo_life *life)
{
    int i;
    i = 0;

    // while (i <= life->number_of_philos)
    // {
        //pthread_mutex_destroy(&mtx[i++]);
    //}
    life->number_of_philos = 0;
    free(mtx);
    free(philo);
}