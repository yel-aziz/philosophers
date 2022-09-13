/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:32:10 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/13 11:35:03 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct philo_life
{
    unsigned int time_to_die;
    unsigned int time_to_eat;
    unsigned int time_to_sleep;
    int number_of_philos;
    int number_of_times_each_philosopher_must_eat;
}philo_life;

typedef struct philo_id
{
    int id;
    pthread_mutex_t *mtx;
    philo_life *life;
}philo_id;


void *ft_routine(void *p);
int	ft_atoi(const char *str);
unsigned long	timeSeter(void);
#endif