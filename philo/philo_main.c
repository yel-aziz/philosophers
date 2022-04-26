/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 00:10:56 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/26 05:04:52 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void printlock(philosopher *ph, int i)
{
    // mutex -> rot
    pthread_mutex_lock(&t);
    printf("\n%lu %d died\n", realy_time(&ph[i]), ph[i].id);
    pthread_mutex_unlock(&t);
}
//  lock mutext print
//  printf ()
//  unlock print

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
    philo->last_meal =  time_stamp();   
    while (1) {
        pthread_mutex_lock(&philo->mtx[philo->id - 1]);
        printf("\n%lu %d hase take afork\n", realy_time(philo), philo->id);
        pthread_mutex_lock(&philo->mtx[modu]);
        printf("\n%lu %d hase take the seconde fork\n", realy_time(philo),philo->id);
        printf("\n%lu %d is eating\n", realy_time(philo), philo->id);
        philo->n++;
        if (philo->n == philo->rot->number_of_times_each_philosopher_must_eat){
           philo->rot->philos_full++;
        };
        philo->last_meal =  time_stamp();
        usleep(eating * 1000);
        pthread_mutex_unlock(&philo->mtx[philo->id - 1]);
        pthread_mutex_unlock(&philo->mtx[modu]);
        printf("\n%lu %d is sleeping\n",realy_time(philo), philo->id);
        usleep(sleeping * 1000);
        printf("\n%lu %d is thinking\n",realy_time(philo), philo->id);
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
    pthread_t th;
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
        philos[i].n = 0;
        i++;
    }
    i = 0;
    while (i < va.number_of_philosophers)
    {
        pthread_create(&th, NULL, &ft_routine, &philos[i]);
        usleep(100);
        i++;
    }
    i = 0;
    while(1)
    {
        if (va.philos_full == va.number_of_philosophers)
            return (1);
        printf("%lu %lu %d %lu\n",
            time_stamp(), philos[i].last_meal, va.time_to_die
            , time_stamp() -  philos[i].last_meal);
        if (time_stamp() -  philos[i].last_meal > va.time_to_die) {
            printlock(philos, i);
            // mutex print lock
            // printf("\n%lu %d died\n", realy_time(&philos[i]), philos[i].id);
            // printf("index : %d\n", i);
            //exit (1);
        }
        i = (i + 1) % va.number_of_philosophers;
        usleep(100);
    }
}