/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:56:49 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/20 18:12:48 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void destroy(pthread_mutex_t *mtx,pthread_mutex_t *pmtx)
{
    int i;
    i = 0;
    pthread_mutex_destroy(&mtx[i++]);
    pthread_mutex_destroy(pmtx);
    free(mtx);
}