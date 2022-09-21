/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:56:49 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/21 15:52:06 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void destroy(pthread_mutex_t *mtx,pthread_mutex_t *pmtx, philo_id *philo)
{
    int i;
    i = 0;
    pthread_mutex_destroy(&mtx[i++]);
    pthread_mutex_destroy(pmtx);
    free(mtx);
    free(philo);
}