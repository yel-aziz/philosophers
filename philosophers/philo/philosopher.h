/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:45:03 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/05/09 15:18:51 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct rot
{
   int  number_of_philosophers;
   int  time_to_die;
   int  time_to_eat;
   int  time_to_sleep;
   int  number_of_times_each_philosopher_must_eat;
   int  philos_full;
}routine;

typedef struct philosopher
{
    int             id;
    pthread_mutex_t *mtx;
    routine *rot;
    unsigned long             start_of;
    pthread_mutex_t *pr;
   unsigned long  n;
   unsigned long  last_meal;
}philosopher;


int               ft_atoi(const char *str);
void              ft_checking(int c, int *tab);
void              ft_sharing(int *tab, routine *rt);
void              ft_parcing(char **av, int ac, routine *va);
void              ft_is_dead(routine *va);
unsigned long     time_stamp();
unsigned long     realy_time(philosopher *va);
void              printing(philosopher *ph, unsigned long  i, int id, char *str);
void ft_destroy(pthread_mutex_t *mtx, routine *va, philosopher  *philos);


#endif