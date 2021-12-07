/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 21:36:48 by                   #+#    #+#             */
/*   Updated: 2021/10/14 16:55:14 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	unsigned long	last_eat;
	long			eat_times;
	pthread_t		thread;
	pthread_mutex_t	fork;
	void			*data;
}					t_philo;

typedef struct s_common
{
	int					number_of_philosophers;
	long unsigned int	time_to_die;
	long unsigned int	time_to_eat;
	long unsigned int	time_to_sleep;
	int					number_of_times_must_eat;
	pthread_mutex_t		print;
	time_t				start_time;
	t_philo				*philos;
	pthread_t			tread;
}				t_common;

int				ft_arrlen(char **arr);
int				ft_init_philos(char **argv, t_common *data);
int				ft_validate_argv(char **argv);
int				ft_atoi_positive(const char *str);
int				ft_isdigit(int c);
int				ft_is_space(char ch);
void			ft_putstr_fd(char *s, int fd);
unsigned long	get_time(unsigned long start_time);
void			print_msg(int id, char *msg, t_common *data);
int				ft_get_right_fork(t_philo *philo);
int				ft_eat(t_philo *philo);
void			ft_put_forks(t_philo *philo);
void			ft_sleep(t_philo *philo);
void			ft_think(t_philo *philo);
void			ft_take_forks(t_philo *philo);
void			philo_is_dying(t_common *data);

#endif
