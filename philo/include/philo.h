/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 00:38:05 by sujo              #+#    #+#             */
/*   Updated: 2021/12/30 08:30:48 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

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
	int *get_fork;
	long long start_time;
	t_philo *philo;
	pthread_mutex_t *forks;
}t_info;

long long get_time(void);
void	vsleep(long long time);

#endif
