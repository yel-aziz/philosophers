/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:57:59 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/25 15:27:23 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

unsigned long	timeSeter(void)
{
	unsigned long	fractions;
	unsigned long	sec;
	unsigned long	mSec;
	struct timeval	clock;

	sec = 0;
	mSec = 0;
	gettimeofday(&clock, NULL);
	sec = (clock.tv_sec * 1000);
	mSec = (clock.tv_usec / 1000);
	fractions = sec + mSec;
	return (fractions);
}

void ft_routine(t_philos *philos)
{
    while (1)
    {
        sem_wait(philos->sForsks);
        printf("%d has take afork\n",philos->philoID);
        sem_wait(philos->sForsks);
        printf("%d has take afork\n",philos->philoID);
        sem_post(philos->sForsks);
        sem_post(philos->sForsks);
        printf("%d is sleeping\n",philos->philoID);
        usleep(1000 * 200 );
        
    }
    return;
}

int main(int ac, char **av)
{
    t_philos *philo_id;
    t_routine phRot;
    int i;
    
    i = -1;
    if(init_bonus(av, ac, &phRot) == 1)
        return (1);
    philo_id = malloc(sizeof(t_philos));
    //if ()
    sem_unlink("/forks");
    sem_unlink("/printer");
    philo_id->sForsks = sem_open("forks", O_CREAT,phRot.numbPhilo);
    philo_id->pSema = sem_open("printer", O_CREAT, 1);
    philo_id->pids = malloc(sizeof(pid_t) * phRot.numbPhilo);
    //if ()
    while (++i < phRot.numbPhilo)
    {
        philo_id->pids[i] = fork();
        if (philo_id->pids[i] == -1)
            ;//error_message;
        if ( philo_id->pids[i] == 0)
        {
            philo_id->philoID = i + 1;
            philo_id->starOf = timeSeter();
            philo_id->life = &phRot;
            ft_routine(philo_id);
        }
    }
    i = 0;
    while (i < phRot.numbPhilo)
    {
        waitpid(philo_id->pids[i++],0,0);
    }
    
  //  procInit(&philo_id, &phRot);
    
    
    
    
}