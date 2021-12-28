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

int	ft_observe_philo(t_philo *philo)
{
	t_common	*data;

	data = (t_common *)philo->data;
	if (get_time(data->start_time) - philo->last_eat
		> data->time_to_die && !philo->status)
	{
		print_msg(philo->id + 1, "died\n", data);
		data->die = 1;
		return (1);
	}
	return (0);
}

void	*ft_observer(void *arg)
{
	int			i;
	int			status;
	t_common	*data;

	data = (t_common *)arg;
	while (1)
	{
		i = 0;
		while (i < data->number_of_philosophers)
		{
			status = ft_observe_philo(&data->philos[i]);
			if (status == 1)
				return (NULL);
			else
				i++;
		}
		if (data->number_of_full_philos >= data->number_of_philosophers)
		{
			data->die = 1;
			return (NULL);
		}
	}
}
