/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 23:33:32 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/25 23:55:05 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void ft_parcing(char **av, int ac, routine *va)
{
    int i;
    int k;
    int c;
    int *tab;
    
    i = 1;
    k = 0;
    if(ac == 1)
    printf("please enter the following parameters : \nnumber_of_philosophers time_to_die time_to_eat time_to_sleep && number_of_times_each_philosopher_must_eat");
    while (av[i])
    i++;
    if(ac < 5 || ac  > 6)
        exit(0);
    tab = malloc(sizeof(int) * i);
    i = 1;
    while (av[i])
    {
        c = ft_atoi(av[i++]);
        ft_checking(c, tab);
        tab[k++] = c;
    }
    k--;
    ft_sharing(tab, va);
}

unsigned long    time_stamp()
{
    unsigned long sec;
    unsigned long msec;
    unsigned long fraction;
    struct  timeval time;

    sec = 0;
    msec = 0;
    gettimeofday(&time, NULL);
    sec = (time.tv_sec * 1000);
    msec = (time.tv_usec / 1000);
    fraction = sec + msec;
    return (fraction);
}

unsigned long realy_time(philosopher *va)
{
    unsigned long set;

    set =  time_stamp() - va->start_of;
    return(set);
}