/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:02:35 by ebennamr          #+#    #+#             */
/*   Updated: 2023/05/06 13:56:46 by ebennamr         ###   ########.fr       */
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

void	protec_error(int val, char *err)
{
	if (val != 0)
	{
		if (err != NULL)
			perror(err);
		exit(1);
	}
}

void	protec_error_pt(void *val, char *err)
{
	if (val == NULL)
	{
		if (err != NULL)
			perror(err);
		exit(1);
	}
}

void	sem_protec(sem_t *val)
{
	if (val == SEM_FAILED)
		fatal_error("error : semaphore error");
}
