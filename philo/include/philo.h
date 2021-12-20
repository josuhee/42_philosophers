/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 00:38:05 by sujo              #+#    #+#             */
/*   Updated: 2021/12/20 09:26:12 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define ERR "error"

typedef struct s_philo
{
	pthread_t thread;
	int left;
	int right;
	long long last_eat_time;
}t_philo;

typedef struct s_info
{
	int total;
	int die;
	int eat;
	int sleep;
	int must_eat;
	int is_die;
	int *get_fork;
	t_philo *philo;
	pthread_mutex_t *forks;
}t_info;

long long get_time(void);
void	vsleep(long long time);

#endif
