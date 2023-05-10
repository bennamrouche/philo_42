/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:02:35 by ebennamr          #+#    #+#             */
/*   Updated: 2023/05/10 18:22:57 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <semaphore.h>

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

void	protec_error(int val, char *err)
{
	if (val != 0)
	{
		if (err != NULL)
			printf("ERROR: %s", err);
		exit(1);
	}
}

void	protec_error_pt(void *val, char *err)
{
	if (val == NULL)
	{
		if (err != NULL)
			printf("ERROR: %s", err);
		exit(1);
	}
}

void	t(sem_t *val)
{
	if (val == SEM_FAILED)
	{
		printf("semaphore error : ");
		exit(1);
	}
}
