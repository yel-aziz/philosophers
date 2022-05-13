/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 21:25:57 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/05/10 14:15:37 by yel-aziz         ###   ########.fr       */
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
