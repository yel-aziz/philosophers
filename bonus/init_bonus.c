/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:58:35 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/25 15:25:04 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int init_bonus(char **av, int ac, t_routine *rot)
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
    rot->numbPhilo = tab[0];
    rot->timeToDie = tab[1];
    rot->timeToEat = tab[2];
    rot->timeToSleep = tab[3];
    rot->eachPhiloEat = tab[4];
    free(tab);
    return (0);
}
/*
void init_ptoc_var(philos *ph, routine *rt, int i)
{
    
}

void procInit(philos *ph, routine *rt)
{
    int i;
    i = 0;
    ph->pids = malloc(sizeof(pid_t) * rt->n);
    while (i < ph->philoID)
    {
        ph->pids[i] = fork();
        if(ph->pids[i] == 0)
       i++;
    }
    i = 0;
    while (i < ph->philoID)
    {
        waitpid(ph->pids[i++],0,0);
    }
    
    
}*/