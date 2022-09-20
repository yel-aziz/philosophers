/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:32:10 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/20 18:06:54 by yel-aziz         ###   ########.fr       */
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
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_philos;
    int number_of_times_each_philosopher_must_eat;
}philo_life;

typedef struct philo_id
{
    int id;
    pthread_mutex_t *mtx;
    pthread_mutex_t *prtintMtx;
    philo_life *life;
    unsigned long lastMeal;
    int nEat;
}philo_id;


void *ft_routine(void *p);
int	ft_atoi(const char *str);
unsigned long	timeSeter(void);
void printer(philo_id *philo,char *str, int id);
void init_all(philo_life *philo_life, char **av, int ac);
int checker(philo_id *philo, philo_life *philo_life, pthread_mutex_t *mtx, pthread_mutex_t *pmtx);
void destroy(pthread_mutex_t *mtx,pthread_mutex_t *pmtx);
#endif