/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 23:33:32 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/05/10 13:42:45 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	c_check(int c, int *tab)
{
	if (c <= 0)
	{
		printf("ERROR");
		free(tab);
		return (1);
	}
	return (0);
}

int	parcing_to(char **av, t_routine *va)
{
	int	i;
	int	*tab;
	int	c;
	int	k;

	i = 1;
	k = 0;
	while (av[i])
		i++;
	tab = malloc(sizeof(int) * i);
	if (!tab)
		return (1);
	i = 1;
	while (av[i])
	{
		c = ft_atoi(av[i++]);
		if (c_check(c, tab) == 1)
			return (1);
		tab[k++] = c;
	}
	k--;
	ft_sharing(tab, va);
	return (0);
}

int	ft_parcing(char **av, int ac, t_routine *va)
{
	int		i;
	int		k;

	i = 1;
	k = 0;
	if (ac == 1)
	{
		printf("please enter the right parameters");
		return (1);
	}
	if (ac < 5 || ac > 6)
	{
		printf("EROOR");
		return (1);
	}
	parcing_to(av, va);
	return (0);
}

unsigned long	time_stamp(void)
{
	unsigned long	sec;
	unsigned long	msec;
	unsigned long	fraction;
	struct timeval	time;

	sec = 0;
	msec = 0;
	gettimeofday(&time, NULL);
	sec = (time.tv_sec * 1000);
	msec = (time.tv_usec / 1000);
	fraction = sec + msec;
	return (fraction);
}

unsigned long	realy_time(t_philosopher *va)
{
	unsigned long	set;

	set = time_stamp() - va->start_of;
	return (set);
}
