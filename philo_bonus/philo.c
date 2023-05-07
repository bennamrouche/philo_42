/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:01:04 by ebennamr          #+#    #+#             */
/*   Updated: 2023/05/06 22:22:48 by ebennamr         ###   ########.fr       */
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
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_FORKS);
	data->forks = sem_open(SEM_FORKS, O_CREAT | O_RDWR, 0644, *num_of_philo);
	sem_protec(data->forks);
	data->sem_print = sem_open(SEM_PRINT, O_CREAT | O_RDWR, 0644, 1);
	sem_protec(data->sem_print);
}

t_philo	*run(int num, t_data *data)
{
	int						i;
	t_philo					*philo;
	pid_t					pid;

	philo = getall_philo(num);
	i = 0;
	while (i < num)
	{
		philo[i].index = i + 1;
		philo[i].data = data;
		philo[i].num_of_eat = 0;
		philo[i].lst_eat = get_time_ms();
		pid = fork();
		if (pid == 0)
			life(&philo[i]);
		else if (pid == -1)
			protec_error((int)pid, "error : fork fail");
		i++;
	}
	return (philo);
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		num_of_philo;
	t_philo	*philo;
	int		status;

	if (ac != 5 && ac != 6)
		fatal_error(ERR_ARG);
	data = malloc(sizeof(t_data));
	parser(ac, av, data, &num_of_philo);
	philo = run(num_of_philo, data);
	while (waitpid(-1, &status, 0) != -1)
	{
		if (WEXITSTATUS(status) == EXIT_DAIED)
			break ;
	}
	kill(0, SIGKILL);
	return (0);
}
