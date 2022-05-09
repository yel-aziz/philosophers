/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:25:57 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/05/09 21:49:34 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_eating(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->mtx[philo->id - 1]);
	printing(philo, realy_time(philo),
		philo->id, "has taken a fork");
	pthread_mutex_lock(&philo->mtx[philo->id
		% philo->rot->number_of_philosophers]);
	printing(philo, realy_time(philo), philo->id, "has taken a fork");
	printing(philo, realy_time(philo), philo->id, "is eating");
}

void	ft_is_dead(t_routine *va)
{
	int	i;

	i = va->time_to_die;
	while (i > 0)
		i--;
	if (i == 0)
		return ;
}
