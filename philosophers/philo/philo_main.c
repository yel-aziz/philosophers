/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 00:10:56 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/05/09 15:49:37 by yel-aziz         ###   ########.fr       */
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
    ;
    philo->last_meal =  time_stamp();   
    while (1) {
        pthread_mutex_lock(&philo->mtx[philo->id - 1]);
        printing(philo, realy_time(philo), philo->id, "hase taken the first fork");
        pthread_mutex_lock(&philo->mtx[modu]);
        printing(philo, realy_time(philo), philo->id, "hase taken the seconde fork");
        printing(philo, realy_time(philo), philo->id, "is eating");
        philo->n++;
        if (philo->n == (unsigned long)philo->rot->number_of_times_each_philosopher_must_eat){
           philo->rot->philos_full++;
        };
        usleep(eating * 1000);
        philo->last_meal =  time_stamp();
        pthread_mutex_unlock(&philo->mtx[philo->id - 1]);
        pthread_mutex_unlock(&philo->mtx[modu]);
        printing(philo, realy_time(philo), philo->id, "is sleeping");
        usleep(sleeping * 1000);
        printing(philo, realy_time(philo), philo->id, "is thinking");
    }
    return(p);
}

int main(int ac, char **av)
{
    routine va;
    philosopher  *philos;
    pthread_mutex_t pr;
 
    int     n;
    int     i;

    i = 0;
    ft_parcing(av, ac, &va);
    n = va.number_of_philosophers;
    pthread_t th;
    philos = malloc(sizeof(philosopher) * n);
    if(!philos)
        return(0);
    pthread_mutex_t *mtx = malloc(sizeof(pthread_mutex_t) * va.number_of_philosophers);
    if(!mtx)
        return (0);
    while (i < va.number_of_philosophers)
        pthread_mutex_init(&mtx[i++], NULL);
        pthread_mutex_init(&pr, NULL);
    i = 0;
    while (i < va.number_of_philosophers)
    {
        philos[i].pr = &pr;
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
        {
            ft_destroy(mtx, &va, philos);
            return (1);
        }
        if (time_stamp() -  (unsigned long)philos[i].last_meal >(unsigned long) va.time_to_die) {
            usleep(100);
            pthread_mutex_lock(philos->pr);
            printf("%lums %d is died\n",realy_time(philos) ,philos->id);
            ft_destroy(mtx, &va, philos);
            return(0);
        }
        i = (i + 1) % va.number_of_philosophers;
        usleep(500);
    }
}