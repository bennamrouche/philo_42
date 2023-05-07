/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:07:48 by ebennamr          #+#    #+#             */
/*   Updated: 2023/05/06 22:20:07 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	len;

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
	if (str[i] == '+')
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

void	print_log(t_philo *philo, char *log)
{
	long long	time_ms;

	sem_wait(philo->lock);
	time_ms = get_time_ms() - philo->data->tm_start;
	if (philo->data->num_of_eat > 0
		&& philo->data->num_of_eat <= philo->num_of_eat)
		exit(EXIT_MAX_EAT);
	sem_post(philo->lock);
	sem_wait(philo->data->sem_print);
	printf("%lld %lld %s\n", time_ms, philo->index, log);
	if (log[0] == 'd')
		exit(EXIT_DAIED);
	sem_post(philo->data->sem_print);
}

long long	get_time_ms(void)
{
	struct timeval	tm;
	long long		cr_time_ms;

	protec_error(gettimeofday(&tm, NULL), "Time get Error");
	cr_time_ms = (tm.tv_sec * 1000) + (tm.tv_usec / 1000);
	return (cr_time_ms);
}
