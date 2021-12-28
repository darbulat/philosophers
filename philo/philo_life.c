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

void	ft_take_forks(t_philo *philo)
{
	t_common	*data;
	int			right;

	right = ft_get_right_fork(philo);
	data = (t_common *)philo->data;
	pthread_mutex_lock(&philo->priority);
	if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(&philo->fork);
		print_msg(philo->id + 1, "has taken a left fork\n", data);
		pthread_mutex_lock(&data->philos[right].fork);
		print_msg(philo->id + 1, "has taken a right fork\n", data);
	}
	else
	{
		pthread_mutex_lock(&data->philos[right].fork);
		print_msg(philo->id + 1, "has taken a right fork\n", data);
		pthread_mutex_lock(&philo->fork);
		print_msg(philo->id + 1, "has taken a left fork\n", data);
	}
	pthread_mutex_unlock(&data->philos[right].priority);
}

int	ft_eat(t_philo *philo)
{
	t_common		*data;
	unsigned long	time;

	if (!philo)
		return (0);
	data = (t_common *)philo->data;
	print_msg(philo->id + 1, "is eating\n", data);
	philo->status = 1;
	time = get_time(data->start_time);
	philo->last_eat = time;
	while (get_time(data->start_time) - time < data->time_to_eat)
		usleep(300);
	if (data->number_of_times_must_eat != -1)
		philo->eat_times--;
	if (data->number_of_times_must_eat != -1 && philo->eat_times <= 0)
		data->number_of_full_philos++;
	philo->status = 0;
	return (1);
}

void	ft_put_forks(t_philo *philo)
{
	t_common	*data;
	int			right;

	data = (t_common *)philo->data;
	right = ft_get_right_fork(philo);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&data->philos[right].fork);
}

void	ft_sleep(t_philo *philo)
{
	t_common		*data;
	unsigned int	time;

	data = (t_common *)philo->data;
	print_msg(philo->id + 1, "is sleeping\n", data);
	time = get_time(data->start_time);
	while (get_time(data->start_time) - time < data->time_to_sleep)
		usleep(300);
}

void	ft_think(t_philo *philo)
{
	t_common	*data;

	data = (t_common *)philo->data;
	print_msg(philo->id + 1, "is thinking\n", data);
}
