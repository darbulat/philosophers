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

void	*run_philo(void *arg)
{
	t_philo			*philo;
	t_common		*data;

	if (!arg)
		return (NULL);
	philo = (t_philo *)arg;
	data = (t_common *)philo->data;
	if (data->number_of_philosophers == 1)
		philo_is_dying(data);
	else
	{
		while (1)
		{
			ft_take_forks(philo);
			if (!ft_eat(philo))
				break ;
			ft_put_forks(philo);
			ft_sleep(philo);
			ft_think(philo);
		}
	}
	return (NULL);
}

int	run_philos(t_common *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				run_philo, (void *)&data->philos[i]))
			return (1);
		i++;
		usleep(5);
	}
	return (0);
}

void	clear_treads(t_common *data)
{
	int	i;

	i = -1;
	while (++i < data->number_of_philosophers)
		pthread_detach(data->philos[i].thread);
	i = -1;
	while (++i < data->number_of_philosophers)
	{
		pthread_mutex_destroy(&data->philos[i].priority);
		pthread_mutex_destroy(&data->philos[i].fork);
	}
	pthread_mutex_destroy(&data->print);
	free(data->philos);
}

int	main(int argc, char **argv)
{
	t_common	data;

	(void)argc;
	if (ft_validate_argv(argv) == -1)
		return (0);
	if (ft_init_philos(argv, &data) == -1)
		return (0);
	run_philos(&data);
	pthread_create(&data.tread, NULL, ft_observer, &data);
	pthread_join(data.tread, NULL);
	clear_treads(&data);
	return (0);
}
