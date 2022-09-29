/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:58:35 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/28 16:39:03 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_var(int *tab, t_routine *rot)
{
	rot->numbphilo = tab[0];
	rot->timetodie = tab[1];
	rot->timetoeat = tab[2];
	rot->timetosleep = tab[3];
	rot->eachphiloeat = tab[4];
	free (tab);
}

int	init_bonus(char **av, int ac, t_routine *rot)
{
	int	i;
	int	k;
	int	c;
	int	*tab;

	i = 1;
	if (ac < 5 || ac > 6 || ac == 1)
	{
		printf("please enter the right parameters");
		return (1);
	}
	while (av[i])
		i++;
	tab = malloc(sizeof(int) * (i - 1));
	i = 1;
	k = 0;
	while (av[i])
	{
		c = ft_atoi(av[i++]);
		if (c <= 0)
			return (1);
		tab[k++] = c;
	}
	init_var(tab, rot);
	return (0);
}

void	*checkdeath(void *p)
{
	t_philos	*pp;

	pp = (t_philos *)p;
	while (1)
	{
		if (timeseter() - pp->lastmeal > (unsigned long long)pp->life.timetodie)
		{
			sem_wait(pp->printer);
			printf("%llu %d died", (timeseter() - pp->starof), pp->philoid);
			exit (1);
		}
		usleep (500);
	}
	return (0);
}

void	ft_printer(t_philos *pr, char *str)
{
	sem_wait(pr->printer);
	printf("%llu %d %s \n", (timeseter() - pr->starof), pr->philoid, str);
	sem_post(pr->printer);
}
