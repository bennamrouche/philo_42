/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:01:04 by ebennamr          #+#    #+#             */
/*   Updated: 2023/05/02 18:21:11 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	getvlaue(char *val)
{
	long	num_val;
	char	*tmp;

	tmp = ft_strtrim(val, " \t\r\b\v");
	protec_errr_pt(tmp, ERR_OUT);
	if (!is_pos_number(tmp))
		ftal_error(ERR_PS_NUM);
	num_val = ft_atoi(tmp);
	if (num_val <= 0 )
		ftal_error(ERR_PS_NUM);
	free(tmp);
	return (num_val);
}

static void	 parser(int ac, char **args, st_data_t *data, int *num_of_philo)
{
	*num_of_philo = getvlaue(args[1]);
	data->tm_die = getvlaue(args[2]);
	data->tm_eat = getvlaue(args[3]);
	data->tm_sleep = getvlaue(args[4]);
	if (ac == 6)
		data->num_of_eat = getvlaue(args[5]);
	else
		data->num_of_eat = -1;
	data->tm_start = get_time_ms();
}

philo_t	*philo_create(int num, st_data_t *data)
{
	int						i;
	philo_t					*philo;

	philo = getall_philo(num);

	i = 0;
	while (i < num)
	{
		philo[i].index = i + 1;
		philo[i].data = data;
		philo[i].lst_eat = get_time_ms();
		philo[i].phlio_fork2 = &philo[ (num + i + 1) % num].phlio_fork1;
		philo[i].num_of_eat = 0;
		protec_errr(pthread_create(&philo[i].th_id, NULL,  &life,  &philo[i]), "thread create error");
		//pthread_detach(philo[i].th_id);
		i++;
	}
	return (philo);
}

int	main(int ac, char **av)
{
	st_data_t data;
	int num_of_philo;
	philo_t	*philo;
	if (ac != 5 && ac != 6)
		ftal_error(ERR_ARG);
		data.mut_print = malloc(sizeof(pthread_mutex_t));
		protec_errr_pt(data.mut_print, ERR_OUT);
		pthread_mutex_init(data.mut_print, NULL);
		parser(ac, av, &data, &num_of_philo);
		philo = philo_create(num_of_philo, &data);
		monitor(philo, num_of_philo);
		return (0);
}
