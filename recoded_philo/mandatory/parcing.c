/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:55:02 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/23 17:40:43 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int parcing(char **av, int ac,philo_life *life)
{
    int i;
    int k;
    int c;
    int *tab;

    i = 1;
    if (ac == 1)
	{
		printf("please enter the right parameters");
		return 1;
	}
	if (ac < 5 || ac > 6)
	{
		printf("EROOR");
		return 1;
	}
    while (av[i])
        i++;
    tab = malloc(sizeof(int) * (i - 1));
    
    i = 1;
    k = 0;
    while (av[i])
    {
        c = ft_atoi(av[i++]);
        if(c <= 0)
            return 1;
        tab[k++] = c;
    }
    
    life->number_of_philos = tab[0];
    life->time_to_die = tab[1];
    life->time_to_eat = tab[2];
    life->time_to_sleep = tab[3];
    life->number_of_times_each_philosopher_must_eat = tab[4];
    life->philoFull = 0;
    return (0);

}