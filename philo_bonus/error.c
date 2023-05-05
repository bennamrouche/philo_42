/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:02:35 by ebennamr          #+#    #+#             */
/*   Updated: 2023/05/05 16:43:23 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fatal_error(char *err)
{
	int	len;

	if (err != NULL)
	{
		len = ft_strlen(err);
		write(2, err, len);
	}
	exit(1);
}

void	protec_errr(int val, char *err)
{
	if (val != 0)
	{
		if (err != NULL)
			perror(err);
		exit(1);
	}
}

void	protec_errr_pt(void *val, char *err)
{
	if (val == NULL)
	{
		if (err != NULL)
			perror(err);
		exit(1);
	}
}
