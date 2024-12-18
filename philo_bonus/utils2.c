/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:47:23 by ebennamr          #+#    #+#             */
/*   Updated: 2023/05/06 21:05:09 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

char	*ft_strjoin(char *string1, char *string2)
{
	int		len;
	int		count;
	char	*pt;

	if (!string1 || !string2)
		return (0);
	len = ft_strlen(string1) + ft_strlen(string2);
	count = 0;
	pt = malloc(len + 1);
	protec_error_pt(pt, ERR_OUT);
	if (!pt)
		return (0);
	while (string1[count])
	{
		*(pt++) = string1[count];
		count++;
	}
	count = 0;
	while (string2[count])
	{
		*(pt++) = string2[count];
		count++;
	}
	*pt = '\0';
	return (pt - len);
}

t_philo	*getall_philo(int num)
{
	t_philo		*philo;
	int			i;
	char		*lock_name;
	char		*tmp;

	i = 0;
	philo = malloc(num * sizeof(t_philo));
	protec_error_pt(philo, ERR_OUT);
	while (i < num)
	{
		tmp = ft_itoa(i + 1);
		lock_name = ft_strjoin(SEM_LOCK, tmp);
		free(tmp);
		sem_unlink(lock_name);
		philo[i].lock = sem_open(lock_name, O_CREAT | O_RDWR, 0644, 1);
		free(lock_name);
		sem_protec(philo[i].lock);
			i++;
	}
	return (philo);
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
