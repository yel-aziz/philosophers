/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 00:30:37 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/04/25 00:32:36 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void fork(thread *va)
{
    if(va->id == 1)
    {
       pthread_mutex_lock(&va->mtx[va->id]);
       pthread_mutex_lock(&va->mtx[va->id + 1]);
    }
    
       
}

