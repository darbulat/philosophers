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

void	create_philo(t_philo *philo, int i, t_common *data)
{
	philo->id = i;
	philo->eat_times = data->number_of_times_must_eat;
	philo->data = (void *)data;
	philo->last_eat = 0;
	philo->status = 0;
	pthread_mutex_init(&philo->fork, NULL);
	pthread_mutex_init(&philo->priority, NULL);
}

int	ft_print_error_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (-1);
}

int	ft_validate_argv(char **argv)
{
	int	arg;

	if (ft_arrlen(argv) < 5 || ft_arrlen(argv) > 6)
		return (ft_print_error_msg("Argument error\n"));
	while (*(++argv))
	{
		arg = ft_atoi_positive(*argv);
		if (arg <= 0)
			return (ft_print_error_msg("Argument error\n"));
	}
	return (0);
}

int	ft_init_philos(char **argv, t_common *data)
{
	int	i;

	data->number_of_philosophers = ft_atoi_positive(argv[1]);
	data->time_to_die = ft_atoi_positive(argv[2]);
	data->time_to_eat = ft_atoi_positive(argv[3]);
	data->time_to_sleep = ft_atoi_positive(argv[4]);
	data->die = 0;
	printf("%s %s %s %s\n", argv[1], argv[2], argv[3], argv[4]);
	if (argv[5])
		data->number_of_times_must_eat = ft_atoi_positive(argv[5]);
	else
		data->number_of_times_must_eat = -1;
	data->philos = malloc(data->number_of_philosophers * sizeof(t_philo));
	if (!data->philos)
		return (ft_print_error_msg("Malloc error\n"));
	i = 0;
	while (i++ != data->number_of_philosophers)
		create_philo(&data->philos[i - 1], i - 1, data);
	pthread_mutex_init(&data->print, NULL);
	data->start_time = get_time(0);
	return (0);
}
