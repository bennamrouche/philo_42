/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:47:23 by ebennamr          #+#    #+#             */
/*   Updated: 2023/05/07 13:32:40 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*getall_philo(int num)
{
	t_philo		*all;
	int			i;

	i = 0;
	all = malloc(num * sizeof(t_philo));
	protec_error_pt(all, ERR_OUT);
	while (i < num)
	{
		pthread_mutex_init(&all[i].phlio_fork1, NULL);
		pthread_mutex_init(&all[i].lock, NULL);
			i++;
	}
	return (all);
}

char	*ft_strdup(char *s1)
{
	return ((ft_substr(s1, 0, ft_strlen(s1))));
}

void	sleep_ms(long time)
{
	unsigned long long	start;

	time *= 1000;
	start = get_time_us();
	while (start + time > get_time_us())
		usleep(100);
}

unsigned long long	get_time_us(void)
{
	struct timeval		tm;
	unsigned long long	cr_time_ms;

	protec_error(gettimeofday(&tm, NULL), "Time get Error");
	cr_time_ms = (tm.tv_sec * 1000 * 1000) + (tm.tv_usec);
	return (cr_time_ms);
}
