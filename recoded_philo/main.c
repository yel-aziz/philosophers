/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:31:58 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/13 11:40:07 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *ft_routine(void *p)
{
    philo_id *philo;
    philo = (philo_id *)p;
    while(1)
    {
    pthread_mutex_lock(&philo->mtx[philo->id - 1]);
    printf("%d has take a fork\n",philo->id);
    pthread_mutex_lock(&philo->mtx[philo->id % philo->life->number_of_philos]);
    printf("%d has take a fork\n",philo->id);
    printf("%d eating\n",philo->id);
    usleep((philo->life->time_to_eat * 1000));
    pthread_mutex_unlock(&philo->mtx[philo->id - 1]);
    pthread_mutex_unlock(&philo->mtx[philo->id % philo->life->number_of_philos]);
    printf("%d is sleeping\n",philo->id);
    usleep(philo->life->time_to_sleep );
    printf("%d is thinking\n",philo->id);
    }
   
    return(p);
}

int main(int ac, char **av)
{
    int i = 0;
    philo_id *philo_id;
    pthread_mutex_t *mtx;
    philo_life philo_life;
    pthread_t th;
    philo_life.number_of_philos = ft_atoi(av[1]);
    philo_life.time_to_die = ft_atoi(av[2]);
    philo_life.time_to_eat = ft_atoi(av[3]);;
    philo_life.time_to_sleep = ft_atoi(av[4]);;
    if(ac == 6)
    philo_life.number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
    else
    philo_life.number_of_times_each_philosopher_must_eat = 0;
    
    philo_id = malloc(philo_life.number_of_philos * sizeof(philo_life));
    if (!philo_id)
    return(0);
    mtx = malloc(philo_life.number_of_philos * sizeof(pthread_mutex_t));
    if(!mtx)
    {
        free(philo_id);
        return (0);
    }
    i = 0;
    while (i < philo_life.number_of_philos)
    {
        pthread_mutex_init(&mtx[i],NULL);
        i++;
    }
    i = 0;
    while (i < philo_life.number_of_philos)
    {
        philo_id[i].id = i + 1;
        philo_id[i].mtx = mtx;
        philo_id[i].life = &philo_life;
        i++;
    }
    i = 0;
   while (i < philo_life.number_of_philos)
    {   
        pthread_create(&th,NULL,&ft_routine, &philo_id[i++]);
    }
    i = 0;
    while (1)
    {
    }
 
}