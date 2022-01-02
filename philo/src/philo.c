/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 00:08:20 by sujo              #+#    #+#             */
/*   Updated: 2022/01/02 19:43:52 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 모니터랑 최대 먹는 횟수 용 모니터는 기본 join 으로
// 나머지 철학자들은 detach

static void *philo_action(void *philo_)
{
	t_philo *philo;

	philo = (void *)philo_;
	while (!philo->info->is_die && !philo->info->is_must_eat)
	{
		get_fork(philo);
		eat(philo);
		unfork(philo);
		go_sleep(philo);
		think(philo);
	}
	return (NULL);
}

static int start_monitor(t_info *info)
{
	if (pthread_create(&info->t_monitor, NULL, monitor, (void *)info) != 0)
		return (1);
	if (info->must_eat != 0)
		if (pthread_create(&info->t_eat, NULL, must_eat_monitor, (void *)info))
			return (1);
	return (0);
}

static int start_philo(t_info *info)
{
	int idx;

	idx = -1;
	while (++idx < info->total)
	{
		if (pthread_create(&info->philo[idx].thread, NULL, philo_action, (void *)&info->philo[idx]) != 0)
			return (1);
		pthread_detach(info->philo[idx].thread);
		usleep(100);
	}
	return (0);
}

int philo(int *num, int size)
{
	int status;
	t_info info;

	memset(&info, 0, sizeof(info));
	if (init_info(&info, num, size))
		return (1);//error 처리 용 함수 만들까?
	init_philo(&info);
	if (start_monitor(&info))
		return (1); // pthread create error
	if (start_philo(&info))
		return (1);
	pthread_join(info.t_monitor, (void *)&status);
	if (info.must_eat != 0)
		pthread_join(info.t_eat, (void *)&status);
	free_mutex(&info);
	return (0);
}
