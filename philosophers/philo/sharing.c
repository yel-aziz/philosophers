/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sharing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:12:06 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/05/09 20:14:11 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_checking(int c, int *tab)
{
	if (c < 0)
	{
		free(tab);
		printf("\nnegative is here\n");
		return ;
	}
}

void	ft_sharing(int *tab, t_routine *rt)
{
	if (tab[0] > 200)
		return ;
	rt->number_of_philosophers = tab[0];
	rt->time_to_die = tab[1];
	rt->time_to_eat = tab[2];
	rt->time_to_sleep = tab[3];
	rt->number_of_times_each_philosopher_must_eat = tab[4];
	rt->philos_full = 0;
	free(tab);
}
