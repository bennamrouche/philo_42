/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:58:04 by ebennamr          #+#    #+#             */
/*   Updated: 2023/05/04 17:00:50 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	monitor(t_philo *philo, int num, int i, int eat_max)
{
	int		is_max;
	long	is_died;

	while (1)
	{
		eat_max = 0;
		i = 0;
		is_max = 0;
		is_died = 0;
		while (i < num)
		{
			pthread_mutex_lock(&philo[i].lock);
			is_died = get_time_ms() - philo[i].lst_eat >= philo->data->tm_die;
			is_max = philo[i].data->num_of_eat <= philo[i].num_of_eat;
			pthread_mutex_unlock(&philo[i].lock);
			if (is_died)
				return (print_log(&philo[i], DIED), 0);
			if (is_max)
				eat_max ++;
			i++;
		}
		if (philo->data->num_of_eat != -1 && eat_max == num)
			return (0);
		usleep(50);
	}
}
