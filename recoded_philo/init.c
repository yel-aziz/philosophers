/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:52:23 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/20 18:09:40 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_all(philo_life *philo_life, char **av, int ac)
{
    philo_life->number_of_philos = ft_atoi(av[1]);
    philo_life->time_to_die = ft_atoi(av[2]);
    philo_life->time_to_eat = ft_atoi(av[3]);
    philo_life->time_to_sleep = ft_atoi(av[4]);
    if(ac == 6)
    philo_life->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
}