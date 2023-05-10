/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:47:59 by ebennamr          #+#    #+#             */
/*   Updated: 2023/05/06 12:46:27 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>
# include <string.h>
# define ERR_OUT "malloc fail"
# define ERR_PS_NUM "Positve number required"
# define ERR_ARG "Invalid arg number"
# define TK_FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"

typedef struct data_s
{
	pthread_mutex_t		mut_print;
	long				tm_die;
	long				tm_eat;
	long				tm_sleep;
	long				num_of_eat;
	long				tm_start;
}	t_data;

typedef struct philo_s
{
	pthread_t				th_id;
	long long				index;
	t_data					*data;
	long long				lst_eat;
	long long				num_of_eat;
	pthread_mutex_t			phlio_fork1;
	pthread_mutex_t			*phlio_fork2;
	pthread_mutex_t			lock;
}t_philo;
//-----------------

char				*ft_strdup(char *s1);
long				ft_atoi(char *str);
char				*ft_substr(char *str, unsigned int start, size_t len);
int					ft_isdigit(int c);
int					is_pos_number(char *str);
void				print_log(t_philo *philo, char *log);
t_philo				*getall_philo(int num);
long long			get_time_ms(void);
void				fatal_error(char *err);
void				protec_error_pt(void *val, char *err);
void				protec_error(int val, char *err);
char				*ft_strtrim(char *s1, char *set);
int					ft_strlen(char *str);
void				sleep_ms(long time);
int					monitor(t_philo *philo, int num, int i, int eat_max);
void				*life(void *pt);
unsigned			long long	get_time_us(void);
#endif
