/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:47:59 by ebennamr          #+#    #+#             */
/*   Updated: 2023/05/02 18:04:30 by ebennamr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHILO_H
# define _PHILO_H
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
	pthread_mutex_t		*mut_print;
	long				tm_die;
	long				tm_eat;
	long				tm_sleep;
	long				num_of_eat;
	long				tm_start;
} st_data_t;

typedef struct philo_s
{
	pthread_t			th_id;
	long				index;
	st_data_t			*data;
	long				lst_eat;
	long				num_of_eat;
	pthread_mutex_t		phlio_fork1;
	pthread_mutex_t		*phlio_fork2;
	pthread_mutex_t		lock;
}philo_t;
//-----------------

char				*ft_strdup(char *s1);
long				ft_atoi(char *str);
char				*ft_substr(char *str, unsigned int start, size_t len);
int					ft_isdigit(int c);
int					is_pos_number(char *str);
void				print_log(philo_t *philo, char *log);
philo_t				*getall_philo(int num);
long				get_time_ms();
void				ftal_error(char *err);
void				protec_errr_pt(void *val, char *err);
void				protec_errr(int val, char *err);
char				*ft_strtrim(char *s1, char *set);
int					ft_strlen(char *str);
void				sleep_ms(long time);
void				monitor(philo_t *philo, int num);
void				*life(void *pt);

#endif
