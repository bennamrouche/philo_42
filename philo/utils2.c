/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:47:23 by ebennamr          #+#    #+#             */
/*   Updated: 2023/05/02 17:49:30 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

philo_t	*getall_philo(int num)
{
	philo_t		*all;
	int			i;

	i = 0;
	all = malloc(num * sizeof(philo_t));
	protec_errr_pt(all, ERR_OUT);
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
	usleep(1000 * time);
}
