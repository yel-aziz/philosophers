/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procces_not.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:44:55 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/05/09 21:55:00 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_init(t_philosopher *philos, t_routine *va, pthread_mutex_t *mtx)
{
	pthread_mutex_t	pr;
	int				i;

	i = 0;
	while (i < va->number_of_philosophers)
		pthread_mutex_init(&mtx[i++], NULL);
	pthread_mutex_init(&pr, NULL);
	i = 0;
	while (i < va->number_of_philosophers)
	{
		philos[i].pr = &pr;
		philos[i].id = i + 1;
		philos[i].mtx = mtx;
		philos[i].rot = va;
		philos[i].start_of = time_stamp();
		philos[i].n = 0;
		i++;
	}
}

int	ft_proc(t_routine *va, t_philosopher *philos, pthread_mutex_t *mtx)
{
	int	i;

	i = 0;
	while (1)
	{
		if (va->philos_full == va->number_of_philosophers)
		{
			ft_destroy(mtx, va, philos);
			return (0);
		}
		if (time_stamp() - (unsigned long)philos[i].last_meal
			> (unsigned long) va->time_to_die)
		{
			usleep(100);
			pthread_mutex_lock(philos->pr);
			printf("%lums %d is died", realy_time(philos), philos->id);
			ft_destroy(mtx, va, philos);
			return (0);
		}
		i = (i + 1) % va->number_of_philosophers;
		usleep(500);
	}
}
