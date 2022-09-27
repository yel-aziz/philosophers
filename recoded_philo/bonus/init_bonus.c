/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:58:35 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/27 16:38:26 by yel-aziz         ###   ########.fr       */
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

void *checkdeath(void *p)
{
    t_philos *pp;
    pp = (t_philos*)p;
    

   while (1)
    {
        if(timeSeter() - pp->lastmeal > (unsigned long long)pp->life.timeToDie)
        {
            sem_wait(pp->printer);
            printf("%d neeed to dead",pp->philoID);
            exit(1);
        }
        usleep(500);
    }
    return 0;
}

void ft_printer(t_philos *pr, char *str)
{
    sem_wait(pr->printer);
    printf("%llu %d %s \n",(timeSeter() - pr->starOf), pr->philoID, str);
    sem_post(pr->printer);
}