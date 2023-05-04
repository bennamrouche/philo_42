/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:52:53 by ebennamr          #+#    #+#             */
/*   Updated: 2023/05/04 17:00:03 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->phlio_fork1);
	print_log(philo, TK_FORK);
	pthread_mutex_lock(philo->phlio_fork2);
	print_log(philo, TK_FORK);
}

static void	eating(t_philo *philo)
{
	print_log(philo, EAT);
	pthread_mutex_lock(&philo->lock);
	philo->lst_eat = get_time_ms();
	philo->num_of_eat++;
	pthread_mutex_unlock(&philo->lock);
	sleep_ms(philo->data->tm_eat);
	pthread_mutex_unlock(&philo->phlio_fork1);
	pthread_mutex_unlock(philo->phlio_fork2);
}

void	*life(void *pt)
{
	t_philo	*philo;

	philo = (t_philo *)pt;
	if ((philo->index % 2) == 0)
		usleep(1000);
	while (1)
	{
		take_forks(philo);
		eating(philo);
		print_log(philo, SLEEP);
		sleep_ms(philo->data->tm_sleep);
		print_log(philo, THINK);
	}
	return (0);
}
