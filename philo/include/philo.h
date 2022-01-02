/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 00:38:05 by sujo              #+#    #+#             */
/*   Updated: 2022/01/02 02:25:58 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define FORK 1
# define EAT 2
# define SLEEP 3
# define THINK 4
# define DIED 5
# define FULL 6

typedef struct s_philo
{
	pthread_t thread;
	int num;
	int left;
	int right;
	int eat_cnt;
	long long last_eat_time;
	struct s_info *info;
}t_philo;

typedef struct s_info
{
	int total;
	int die;
	int eat;
	int sleep;
	int must_eat;
	int is_die;
	int is_must_eat;
	int done;
	long long start_time;
	t_philo *philo;
	pthread_t t_eat;
	pthread_t t_monitor;
	pthread_mutex_t *forks;
	pthread_mutex_t m_write;
}t_info;

int philo(int *num, int size);

//time
long long get_time(void);
void	vsleep(int time);

//init
int init_info(t_info *info, int *num, int size);
void init_philo(t_info *info);

//print
void philo_status_prnt(t_philo *philo, int status);

//action
void get_fork(t_philo *philo);
void eat(t_philo *philo);
void unfork(t_philo *philo);
void go_sleep(t_philo *philo);
void think(t_philo *philo);

//monitor
void *must_eat_monitor(void *info_);
void *monitor(void *info_);

//free
void free_mutex(t_info *info);

#endif
