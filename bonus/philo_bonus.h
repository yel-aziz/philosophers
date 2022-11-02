/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:01:19 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/09/28 16:38:36 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <stddef.h>
# include <fcntl.h>       
# include <sys/stat.h> 
# include <signal.h>

typedef struct s_routine
{
	int	numbphilo;
	int	timetodie;
	int	timetosleep;
	int	timetoeat;
	int	eachphiloeat;
}	t_routine;

typedef struct s_philo
{
	pid_t				*pids;
	sem_t				*forks;
	sem_t				*printer;
	t_routine			life;
	int					philoid;
	unsigned long long	lastmeal;
	unsigned long long	starof;
	int					eacheat;
	int					neat;
}	t_philos;

int					init_bonus(char **av, int ac, t_routine *rot);
int					ft_atoi(const char *str);
void				ft_routine(t_philos *pp);
unsigned long long	timeseter(void);
void				ft_printer(t_philos *ph, char *str);
void				*checkdeath(void *p);

#endif