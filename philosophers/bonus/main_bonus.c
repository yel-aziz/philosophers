/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:57:59 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/28 17:56:28 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

unsigned long long	timeseter(void)
{
	unsigned long long	fractions;
	unsigned long long	sec;
	unsigned long long	msec;
	struct timeval		clock;

	sec = 0;
	msec = 0;
	gettimeofday(&clock, NULL);
	sec = (clock.tv_sec * 1000);
	msec = (clock.tv_usec / 1000);
	fractions = sec + msec;
	return (fractions);
}

void	ft_routine(t_philos *pp)
{
	pthread_t	th;

	pp->lastmeal = timeseter();
	pp->eacheat = 0;
	pthread_create(&th, NULL, &checkdeath, pp);
	while (1)
	{
		sem_wait(pp->forks);
		ft_printer(pp, "has take a fork");
		sem_wait(pp->forks);
		ft_printer(pp, "has take a fork");
		pp->lastmeal = timeseter();
		pp->neat++;
		ft_printer(pp, "is eating");
		usleep(1000 * pp->life.timetoeat);
		sem_post(pp->forks);
		sem_post(pp->forks);
		if (pp->neat == pp->life.eachphiloeat)
			exit(2);
		ft_printer(pp, "is sleeping");
		usleep(1000 * pp->life.timetosleep);
		ft_printer(pp, "is thinking");
		usleep(500);
	}
	return ;
}

int	unlinksemas(t_routine *rot, t_philos *philo_id, int ac, char **av)
{
	if (init_bonus(av, ac, rot) == 1)
		return (1);
	sem_unlink("forks");
	sem_unlink("printer");
	philo_id->forks = sem_open("forks", O_CREAT, 0700, rot->numbphilo);
	philo_id->printer = sem_open("printer", O_CREAT, 0700, 1);
	philo_id->pids = malloc(sizeof(pid_t) * rot->numbphilo);
	return (0);
}

int	exitstatus(t_routine rot, t_philos philo_id)
{
	int	exit_status;
	int	i;

	exit_status = 0;
	i = 0;
	while (i < rot.numbphilo)
	{
		wait(&exit_status);
		if (WEXITSTATUS(exit_status) == 1)
		{
			i = 0;
			while (i < philo_id.life.numbphilo)
			{
				kill(philo_id.pids[i++], SIGKILL);
			}
			sem_unlink("forks");
			sem_unlink("printer");
			exit (0);
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_philos	philo_id;
	t_routine	rot;
	int			i;

	unlinksemas(&rot, &philo_id, ac, av);
	i = 0;
	while (i < rot.numbphilo)
	{
		philo_id.pids[i] = fork();
		if (philo_id.pids[i] == -1)
			exit(1);
		else if (philo_id.pids[i] == 0)
		{
			philo_id.philoid = i + 1;
			philo_id.starof = timeseter();
			philo_id.life = rot;
			philo_id.neat = 0;
			ft_routine(&philo_id);
			exit(0);
		}
		i++;
	}
	exitstatus(rot, philo_id);
	return (0);
}
