/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 00:10:56 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/26 01:59:35 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void *ft_routine(void *p)
{
    philosopher *philo;
    int eating;
    int sleeping;
    int reminder;
    int modu;

    philo = (philosopher *)p;
    modu = (philo->id % philo->rot->number_of_philosophers);
    reminder = philo->rot->time_to_die;
    eating = philo->rot->time_to_eat;
    sleeping = philo->rot->time_to_sleep;
        
                    int n = 0;

    while (1) {
        pthread_mutex_lock(&philo->mtx[philo->id - 1]);
        printf("\n%lu %d hase take afork\n", realy_time(philo), philo->id);
        pthread_mutex_lock(&philo->mtx[modu]);
        printf("\n%lu %d hase take the seconde fork\n", realy_time(philo),philo->id);
        printf("\n%lu %d is eating\n", realy_time(philo), philo->id);
        usleep(eating * 1000);
        pthread_mutex_unlock(&philo->mtx[philo->id - 1]);
        pthread_mutex_unlock(&philo->mtx[modu]);
        printf("\n%lu %d is sleeping\n",realy_time(philo), philo->id);
        usleep(sleeping * 1000);
        printf("\n%lu %d is thinking\n",realy_time(philo), philo->id);
        ++n;
        if (n == philo->rot->number_of_times_each_philosopher_must_eat) return(0);
    }
        
    return(p);
}

int main(int ac, char **av)
{
    routine va;
    philosopher  *philos;
 
    int     n;
    int     i;

    i = 0;
    ft_parcing(av, ac, &va);
    n = va.number_of_philosophers;
    pthread_t th[n];
    philos = malloc(sizeof(philosopher) * n);
    pthread_mutex_t *mtx = malloc(sizeof(pthread_mutex_t) * va.number_of_philosophers);
    while (i < va.number_of_philosophers)
        pthread_mutex_init(&mtx[i++], NULL);
    i = 0;
    while (i < va.number_of_philosophers)
    {
        philos[i].id = i + 1;
        philos[i].mtx = mtx;
        philos[i].rot = &va;
        philos[i].start_of = time_stamp();
        i++;
    }
    i = 0;
    while (i < va.number_of_philosophers)
    {
        pthread_create(&th[i], NULL, &ft_routine, &philos[i]);
        usleep(100);
        i++;
    }
    while (1){
        
    }; 
}