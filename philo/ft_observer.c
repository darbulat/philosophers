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

int	ft_observe_philo(t_philo *philo, int *eat_flag)
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
	if (philo->eat_times > 0)
	{
		*eat_flag = 0;
		return (2);
	}
	return (0);
}

void	*ft_observer(void *arg)
{
	int			i;
	int			eat_flag;
	int			status;
	t_common	*data;

	data = (t_common *)arg;
	while (1)
	{
		i = 0;
		eat_flag = data->number_of_times_must_eat;
		while (i < data->number_of_philosophers)
		{
			status = ft_observe_philo(&data->philos[i], &eat_flag);
			if (status == 1)
				return (NULL);
			else
				i++;
		}
		if (eat_flag > 0)
			return (NULL);
	}
}
