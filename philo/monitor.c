/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 15:58:04 by ebennamr          #+#    #+#             */
/*   Updated: 2023/05/02 18:25:35 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitor(philo_t *philo, int num)
{
	int	eat_max;
	int	i;
	while (1)
	{
		eat_max = 0;
		i = 0;
		while (i < num)
		{
			pthread_mutex_lock(&philo[i].lock);
			if ((get_time_ms() -  philo[i].lst_eat) > philo->data->tm_die)
			{
				print_log(philo, DIED);
				return;
			}
			if (philo[i].data->num_of_eat == philo->num_of_eat)
				eat_max ++;
			pthread_mutex_unlock(&philo[i].lock);
			i++;

		}
		usleep(40 / num);
		if (eat_max == num)
			return ;
	}

}
