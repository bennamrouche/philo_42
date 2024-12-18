/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:01:04 by ebennamr          #+#    #+#             */
/*   Updated: 2023/05/06 12:46:27 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	getvalue(char *val)
{
	long	num_val;
	char	*tmp;

	tmp = ft_strtrim(val, " \t\r\b\v");
	protec_error_pt(tmp, ERR_OUT);
	if (!is_pos_number(tmp))
		fatal_error(ERR_PS_NUM);
	num_val = ft_atoi(tmp);
	if (num_val <= 0)
		fatal_error(ERR_PS_NUM);
	free(tmp);
	return (num_val);
}

static void	parser(int ac, char **args, t_data *data, int *num_of_philo)
{
	*num_of_philo = getvalue(args[1]);
	data->tm_die = getvalue(args[2]);
	data->tm_eat = getvalue(args[3]);
	data->tm_sleep = getvalue(args[4]);
	if (ac == 6)
		data->num_of_eat = getvalue(args[5]);
	else
		data->num_of_eat = -1;
	data->tm_start = get_time_ms();
}

t_philo	*philo_create(int num, t_data *data)
{
	int						i;
	t_philo					*philo;

	philo = getall_philo(num);
	i = 0;
	while (i < num)
	{
		philo[i].index = i + 1;
		philo[i].data = data;
		philo[i].phlio_fork2 = &philo[(num + i + 1) % num].phlio_fork1;
		philo[i].num_of_eat = 0;
		philo[i].lst_eat = get_time_ms();
		protec_error(pthread_create(&philo[i].th_id, NULL, &life, &philo[i]),
			"error :> thread create");
		pthread_detach(philo[i].th_id);
		i++;
	}
	return (philo);
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		num_of_philo;
	t_philo	*philo;

	if (ac != 5 && ac != 6)
		fatal_error(ERR_ARG);
	data = malloc(sizeof(t_data));
	pthread_mutex_init(&data->mut_print, NULL);
	parser(ac, av, data, &num_of_philo);
	philo = philo_create(num_of_philo, data);
	monitor(philo, num_of_philo, 0, 0);
	return (0);
}
