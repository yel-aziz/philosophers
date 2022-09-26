/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:01:19 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/26 15:13:21 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
# include <sys/time.h>
#include <stddef.h>
#include <fcntl.h>       
#include <sys/stat.h> 
#include <signal.h>

typedef struct  s_routine
{
    int numbPhilo;
    int timeToDie;
    int  timeToSleep;
    int  timeToEat;
    int  eachPhiloEat;
}   t_routine;


typedef struct s_philo
{
    pid_t *pids;
    sem_t *forks;
    sem_t *printer;
    t_routine life;
    int philoID;
    unsigned long long lastmeal;
    unsigned long long  starOf;
}   t_philos;

int init_bonus(char **av, int ac, t_routine *rot);
int	ft_atoi(const char *str);
void ft_routine(t_philos *);
unsigned long long	timeSeter(void);
void ft_printer(t_philos *ph, char *str);
void *checkdeath(void *p);
//void init_ptoc_var(t_philos *ph, t_routine *rt, int i);
//void procInit(t_philos *ph, t_routine *rt);

#endif