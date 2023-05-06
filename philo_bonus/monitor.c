/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:58:04 by ebennamr          #+#    #+#             */
/*   Updated: 2023/05/06 11:26:21 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	monitor(t_philo *philo, int i, int eat_max)
{
	int		is_max;
	long	is_died;

	while (1)
	{
		eat_max = 0;
		i = 0;
		is_max = 0;
		is_died = 0;
		while (1)
		{
			sem_wait(philo->lock);
			is_died = get_time_ms() - philo->lst_eat >= philo->data->tm_die;
			is_max = philo[i].data->num_of_eat <= philo->num_of_eat;
			sem_post(philo[i].lock);
			if (is_died)
				return (print_log(&philo[i], DIED), 0);
			if (philo->data->num_of_eat != -1 && is_max)
				exit(0);
			i++;
		}
		usleep(1000);
	}
}
