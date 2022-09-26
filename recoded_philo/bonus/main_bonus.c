/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:57:59 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/26 15:10:32 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

unsigned long long	timeSeter(void)
{
	unsigned long long	fractions;
	unsigned long long	sec;
	unsigned long long	mSec;
	struct timeval	clock;

	sec = 0;
	mSec = 0;
	gettimeofday(&clock, NULL);
	sec = (clock.tv_sec * 1000);
	mSec = (clock.tv_usec / 1000);
	fractions = sec + mSec;
	return (fractions);
}

void ft_routine(t_philos *pp)
{
    pthread_t th;
    //pp->lastmeal = 0;

    //usleep(500);

    // pp->lastmeal = timeSeter() - pp->starOf;
    pthread_create(&th, NULL,&checkdeath,pp);
    while (1)
    {
        sem_wait(pp->forks);
        ft_printer(pp,"has take a fork");
        sem_wait(pp->forks);
        ft_printer(pp,"has take a fork");
        ft_printer(pp, "is eating");
        
        pp->lastmeal = timeSeter();
        usleep(1000 * pp->life.timeToEat);
        ft_printer(pp, "is sleeping");
        sem_post(pp->forks);
        sem_post(pp->forks);
        usleep(1000 * pp->life.timeToSleep);
        // usleep(100);
    }
    return;
}

int main(int ac, char **av)
{
    t_philos philo_id;
    t_routine rot;
    int i;
    
    i = 0;
    if(init_bonus(av, ac, &rot) == 1)
        return (1);
    sem_unlink("forks");
    sem_unlink("printer");
    philo_id.forks = sem_open("forks", O_CREAT, 0700, rot.numbPhilo);
    philo_id.printer = sem_open("printer",  O_CREAT, 0700,1);
    philo_id.pids = malloc(sizeof(pid_t) * rot.numbPhilo);
    //if ()
     i = 0;
    while (i < rot.numbPhilo)
{
        philo_id.pids[i] = fork();
        if (philo_id.pids[i] == -1)
            exit(1);
        if (philo_id.pids[i] == 0)
        {
            philo_id.lastmeal = timeSeter();
            philo_id.philoID = i + 1;
            philo_id.starOf = timeSeter();
            philo_id.life = rot;
            ft_routine(&philo_id);
        }
        usleep(200);
        i++;
    }

    i = 0;
    int exit_status = 0;
    while (i < rot.numbPhilo)
    {
        waitpid(philo_id.pids[i++], &exit_status, 0);
        if (exit_status == 256){
            printf("someone died\n");
            exit (0);
        }
    }
}