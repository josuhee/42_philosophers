/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 00:08:20 by sujo              #+#    #+#             */
/*   Updated: 2021/12/30 08:34:18 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int init_info(t_info *info, int *num, int size)
{
	int idx;

	info->total = num[0];
	info->die = num[1];
	info->eat = num[2];
	info->sleep = num[3];
	if (size == 5)
		info->must_eat = num[4];
	info->get_fork = malloc(sizeof(int) * info->total);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->total);
	info->philo = malloc(sizeof(t_philo) * info->total);
	if (!info->get_fork || !info->forks || !info->philo)
		return (1);
	idx = -1;
	info->start_time = get_time();
	while (++idx < info->total)
	{
		info->get_fork[idx] = 0;
		info->philo[idx].num = idx + 1;
		info->philo[idx].left = idx;
		info->philo[idx].right = (idx + info->total - 1) % info->total;
		info->philo[idx].eat_cnt = 0;
		info->philo[idx].last_eat_time = 0;
		info->philo[idx].info = info;
	}
	return (0);
}

// 모니터랑 최대 먹는 횟수 용 모니터는 기본 join 으로
// 나머지 철학자들은 detach

static void *philo_action(void *philo_)
{
	t_philo *philo;

	philo = (void *)philo_;
	while (1)
	{
		//fort
		//eat
		//unfort
		//think
	}
}

int philo(int *num, int size)
{
	t_info info;

	memset(info, 0, sizeof(info));
	if (init_info(&info, num, size))
		return (1);//error 처리 용 함수 만들까?
}