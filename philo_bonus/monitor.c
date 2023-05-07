/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:58:04 by ebennamr          #+#    #+#             */
/*   Updated: 2023/05/06 22:03:10 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor_call(void *arg)
{
	monitor((t_philo *)arg);
	return (0);
}

int	monitor(t_philo *philo)
{
	int		is_max;
	long	is_died;

	while (1)
	{
		is_max = 0;
		is_died = 0;
		sem_wait(philo->lock);
		is_died = get_time_ms() - philo->lst_eat >= philo->data->tm_die;
		is_max = philo->data->num_of_eat < philo->num_of_eat;
		if (philo->data->num_of_eat != -1 && is_max)
		{
			exit(EXIT_MAX_EAT);
		}
		sem_post(philo->lock);
		if (is_died)
			return (print_log(philo, DIED), 0);
		sleep_ms(3);
	}
}
