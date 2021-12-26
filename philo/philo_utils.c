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

#include "philo.h"

unsigned long	get_time(unsigned long start_time)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000) - start_time);
}

void	print_msg(int id, char *msg, t_common *data)
{
	if (data && data->print.__data.__spins == 0)
	{
		pthread_mutex_lock(&data->print);
		if (data->die == 0)
			printf("%lu	%d	%s", get_time(data->start_time), id, msg);
		pthread_mutex_unlock(&data->print);
	}
}

int	ft_get_right_fork(t_philo *philo)
{
	t_common	*data;
	int			right;

	data = (t_common *)philo->data;
	if (philo->id == data->number_of_philosophers - 1)
		right = 0;
	else
		right = philo->id + 1;
	return (right);
}

void	philo_is_dying(t_common *data)
{
	pthread_mutex_lock(&data->philos[0].fork);
	print_msg(1, "has taken a fork\n", data);
	usleep(data->time_to_die);
}
