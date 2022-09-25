/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:01:19 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/25 15:24:32 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
# include <sys/time.h>
#include <semaphore.h>
#include <stddef.h>

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
    sem_t *sForsks;
    sem_t *pSema;
    pid_t *pids;
    t_routine *life;
    int philoID;
    int starOf;
}   t_philos;

int init_bonus(char **av, int ac, t_routine *rot);
int	ft_atoi(const char *str);
void ft_routine(t_philos *philos);
unsigned long	timeSeter(void);
//void init_ptoc_var(t_philos *ph, t_routine *rt, int i);
//void procInit(t_philos *ph, t_routine *rt);

#endif