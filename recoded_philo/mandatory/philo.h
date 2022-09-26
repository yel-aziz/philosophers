/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:32:10 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/24 18:28:12 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H


#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
# include <sys/time.h>


typedef struct philo_life
{
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_philos;
    int number_of_times_each_philosopher_must_eat;
    int philoFull;
}philo_life;

typedef struct philo_id
{
    int id;
    pthread_mutex_t *mtx;
    pthread_mutex_t *prtintMtx;
    philo_life *life;
    unsigned long lastMeal;
    int nEat;
    unsigned long startOn;
}philo_id;


void *ft_routine(void *p);
int	ft_atoi(const char *str);
unsigned long	timeSeter(void);
void printer(philo_id *philo,char *str, int id);
// void init_all(philo_life *philo_life, int *tab);
int checker(philo_id *philo, philo_life *philo_life);
int destroy(pthread_mutex_t *mtx, philo_id *philo);
int parcing(char **av, int ac, philo_life *life);
#endif