/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:07:48 by ebennamr          #+#    #+#             */
/*   Updated: 2023/05/02 18:42:13 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str != '\0')
	{
		str++;
		len++;
	}
	return (len);
}

int	ft_isdigit(int c)
{

	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	is_pos_number(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if(str[i] == '+')
	i++;
	if (str[i] == '\0')
		return (false);
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (false);
			i++;
	}
	return (true);
}

void	print_log(philo_t *philo, char *log)
{
	int index;

	pthread_mutex_lock(&philo->lock);
		index = philo->index;
	pthread_mutex_unlock(&philo->lock);
	long time_ms = get_time_ms() - philo->data->tm_start;
	pthread_mutex_lock(philo->data->mut_print);
	printf("%ld %ld %s\n",time_ms, philo->index,log);
	pthread_mutex_unlock(philo->data->mut_print);
}

long	get_time_ms()
{
	struct timeval tm;
	long cr_time_ms;
	protec_errr(gettimeofday(&tm, NULL), "Time get Error");
	cr_time_ms = (tm.tv_sec * 1000) + (tm.tv_usec / 1000);
	return (cr_time_ms);
}
