/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:03:02 by ebennamr          #+#    #+#             */
/*   Updated: 2023/05/05 17:05:52 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	getnumlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char	*pt;
	int		i;

	i = getnumlen(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	pt = (char *)malloc(sizeof(char) * (i + 1));
	protec_errr_pt(pt, ERR_OUT);
	if (!pt)
		return (0);
	if (n < 0)
	{
		n *= -1;
		*pt = '-';
	}
	*(pt + i) = '\0';
	i--;
	while (n > 9)
	{
		*(pt + i) = (n % 10) + '0';
		i--;
		n /= 10;
	}
	*(pt + i) = n + '0';
	return (pt);
}
