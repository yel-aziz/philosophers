/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-aziz <yel-aziz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:45:03 by yel-aziz          #+#    #+#             */
/*   Updated: 2022/05/09 21:59:32 by yel-aziz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_rot
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
	int	philos_full;
}t_routine;

typedef struct s_philosopher
{
	int					id;
	pthread_mutex_t		*mtx;
	t_routine			*rot;
	unsigned long		start_of;
	pthread_mutex_t		*pr;
	unsigned long		n;
	unsigned long		last_meal;
}t_philosopher;

int				ft_atoi(const char *str);
void			ft_checking(int c, int *tab);
void			ft_sharing(int *tab, t_routine *rt);
int				ft_parcing(char **av, int ac, t_routine *va);
void			ft_is_dead(t_routine *va);
unsigned long	time_stamp(void);
unsigned long	realy_time(t_philosopher *va);
void			printing(t_philosopher *ph, unsigned long i, int id, char *str);
void			ft_destroy(pthread_mutex_t *mtx,
					t_routine *va, t_philosopher *philos);
void			ft_eating( t_philosopher	*philo);
int				ft_proc(t_routine *va, t_philosopher *philos,
					pthread_mutex_t *mtx);
void			ft_init(t_philosopher *philos, t_routine *va,
					pthread_mutex_t *mtx);

#endif