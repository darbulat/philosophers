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
	int			left;
	int			right;

	left = philo->id;
	right = ft_get_right_fork(philo);
	data = (t_common *)philo->data;
	if (philo->id % 2)
	{
		pthread_mutex_lock(&data->philos[left].fork);
		print_msg(philo->id + 1, "has taken a left fork\n", data);
		pthread_mutex_lock(&data->philos[right].fork);
		print_msg(philo->id + 1, "has taken a right fork\n", data);
	}
	else
	{
		pthread_mutex_lock(&data->philos[right].fork);
		print_msg(philo->id + 1, "has taken a right fork\n", data);
		pthread_mutex_lock(&data->philos[left].fork);
		print_msg(philo->id + 1, "has taken a left fork\n", data);
	}
}

int	ft_eat(t_philo *philo)
{
	t_common	*data;

	if (!philo)
		return (0);
	data = (t_common *)philo->data;
	print_msg(philo->id + 1, "is eating\n", data);
	philo->last_eat = get_time(data->start_time);
	while (get_time(data->start_time) < philo->last_eat + data->time_to_eat)
		usleep(300);
	if (data->number_of_times_must_eat != -1)
		philo->eat_times--;
	return (1);
}

void	ft_put_forks(t_philo *philo)
{
	t_common	*data;
	int			left;
	int			right;

	data = (t_common *)philo->data;
	left = philo->id;
	right = ft_get_right_fork(philo);
	pthread_mutex_unlock(&data->philos[left].fork);
	pthread_mutex_unlock(&data->philos[right].fork);
}

void	ft_sleep(t_philo *philo)
{
	t_common	*data;

	data = (t_common *)philo->data;
	print_msg(philo->id + 1, "is sleeping\n", data);
	while (get_time(data->start_time)
		< data->time_to_sleep + philo->last_eat + data->time_to_eat)
		usleep(300);
}

void	ft_think(t_philo *philo)
{
	t_common	*data;

	data = (t_common *)philo->data;
	print_msg(philo->id + 1, "is thinking\n", data);
}
