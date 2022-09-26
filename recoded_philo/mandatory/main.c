/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:31:58 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/25 17:23:15 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *ft_routine(void *p)
{
    philo_id *philo;
    philo = (philo_id *)p;
    // if(philo->id % 2 == 0)
    //     usleep(10);
    philo->lastMeal = timeSeter();
    while(1)
    {
        pthread_mutex_lock(&(philo->mtx[philo->id - 1]));
        printer(philo,"has take a fork",philo->id);
        pthread_mutex_lock(&(philo->mtx[philo->id % philo->life->number_of_philos]));
        printer(philo,"has take a fork",philo->id);
        printer(philo,"is eating",philo->id);
        philo->lastMeal = timeSeter();
        usleep((philo->life->time_to_eat * 1000));
        philo->nEat++;
        if(philo->nEat == philo->life->number_of_times_each_philosopher_must_eat)
            philo->life->philoFull++;
        pthread_mutex_unlock(&philo->mtx[philo->id - 1]);
        pthread_mutex_unlock(&philo->mtx[philo->id % philo->life->number_of_philos]);
        printer(philo,"is sleeping",philo->id);
        usleep(philo->life->time_to_sleep * 1000);
        printer(philo,"is thinking",philo->id);
    }
    return(p);
}

int main(int ac, char **av)
{
    int i;
    philo_id *_philo_id;
    pthread_mutex_t *mtx;
    philo_life philo_life;
    pthread_mutex_t pmtx;
    pthread_t th;
    
    if(parcing(av, ac, &philo_life) == 1)
        return (0);
    _philo_id = malloc(philo_life.number_of_philos * sizeof(philo_id));
    if (!_philo_id)
        return(1);
    mtx = malloc(philo_life.number_of_philos * sizeof(pthread_mutex_t));
    if(!mtx)
    {
        free(_philo_id);
        return (0);
    }
    i = 0;
    while (i < philo_life.number_of_philos)
    {
        if (pthread_mutex_init(&(mtx[i]), NULL) != 0)
        {
            perror("Error");
            return 1;
        }
        i++;
    }
    pthread_mutex_init(&pmtx,NULL);
    i = 0;
    while (i < philo_life.number_of_philos)
    {
        _philo_id[i].id = i + 1;
        _philo_id[i].mtx = mtx;
        _philo_id[i].life = &philo_life;
        _philo_id[i].nEat = 0;
        _philo_id[i].prtintMtx = &pmtx;
        _philo_id[i].startOn = timeSeter();
        i++;
    }
    i = 0;
   while (i < philo_life.number_of_philos)
    {   
        pthread_create(&th,NULL,&ft_routine, &_philo_id[i]);
        i++;
        usleep(500);
    }
    checker(_philo_id, &philo_life);
}