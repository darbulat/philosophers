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

int	ft_atoi_positive(const char *str)
{
	int	x;
	int	minus;

	x = 0;
	minus = -1;
	while (ft_is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			minus = 1;
	while (*str)
	{
		if (ft_isdigit(*str))
			x = x * 10 - (*str++ - '0');
		else
			return (-1);
	}
	return (x * minus);
}
