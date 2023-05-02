/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:52:53 by ebennamr          #+#    #+#             */
/*   Updated: 2023/05/02 18:47:13 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(philo_t *philo)
{
	pthread_mutex_lock(&philo->phlio_fork1);
	print_log(philo, TK_FORK);
	pthread_mutex_lock(philo->phlio_fork2);
	print_log(philo, TK_FORK);
}

static void eating(philo_t *philo)
{
	print_log(philo, EAT);
	pthread_mutex_lock(&philo->lock);
	philo->lst_eat = get_time_ms();
	pthread_mutex_unlock(&philo->lock);
	sleep_ms(philo->data->tm_eat);
	pthread_mutex_lock(&philo->lock);
	philo->num_of_eat++;
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_unlock(&philo->phlio_fork1);
	pthread_mutex_unlock(philo->phlio_fork2);
}

void	*life(void *pt)
{
	philo_t *philo;
	int index;
	pthread_mutex_lock(&philo->lock);
	index = philo->index;
	pthread_mutex_unlock(&philo->lock);
	philo = (philo_t *)pt;
	if ((index % 2) == 1)
		sleep_ms(1);
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
