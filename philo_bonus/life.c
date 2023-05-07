/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:52:53 by ebennamr          #+#    #+#             */
/*   Updated: 2023/05/06 21:58:47 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philo *philo)
{
	sem_wait(philo->data->forks);
	print_log(philo, TK_FORK);
	sem_wait(philo->data->forks);
	print_log(philo, TK_FORK);
}

static void	eating(t_philo *philo)
{
	print_log(philo, EAT);
	sem_wait(philo->lock);
	philo->lst_eat = get_time_ms();
	philo->num_of_eat++;
	sem_post(philo->lock);
	sleep_ms(philo->data->tm_eat);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

void	*life(void *pt)
{
	t_philo	*philo;

	philo = (t_philo *)pt;
	protec_error(pthread_create(&philo->th_id, NULL, monitor_call, philo),
		"error: thread ");
	if ((philo->index % 2) == 0)
		usleep(500);
	while (1)
	{
		sem_wait(philo->lock);
		sem_post(philo->lock);
		take_forks(philo);
		eating(philo);
		print_log(philo, SLEEP);
		sleep_ms(philo->data->tm_sleep);
		print_log(philo, THINK);
	}
	return (0);
}
