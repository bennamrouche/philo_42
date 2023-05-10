/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:22:05 by ebennamr          #+#    #+#             */
/*   Updated: 2023/05/06 12:33:40 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	result( char *str, int i, int sg)
{
	size_t	nb;

	nb = 0;
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 + (((int)str[i]) - 48);
		i++;
	}
	if (nb > 9223372036854775807 && sg == 1)
		return (-1);
	else if (nb > 9223372036854775807 && sg == -1)
		return (0);
	return (nb * sg);
}

long	ft_atoi(char *str)
{
	long	i;
	long	sg;

	sg = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sg = -1;
		i++;
	}
	return (result(str, i, sg));
}
