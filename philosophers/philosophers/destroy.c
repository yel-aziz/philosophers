/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:51:03 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/05/10 14:13:51 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	ft_destroy(pthread_mutex_t *mtx, t_routine *va, t_philosopher *philos)
{
	int	i;

	i = 0;
	while (i <= va->number_of_philosophers)
	{
		pthread_mutex_destroy(&mtx[i]);
		i++;
	}
	free(mtx);
	free(philos);
}
