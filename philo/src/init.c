/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 23:51:45 by sujo              #+#    #+#             */
/*   Updated: 2022/01/01 05:28:39 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_info(t_info *info, int *num, int size)
{
	int idx;

	info->total = num[0];
	info->die = num[1];
	info->eat = num[2];
	info->sleep = num[3];
	if (size == 5)
		info->must_eat = num[4];
	info->forks = malloc(sizeof(pthread_mutex_t) * info->total);
	info->philo = malloc(sizeof(t_philo) * info->total);
	if (!info->forks || !info->philo)
		return (1);
	idx = -1;
	while (++idx < info->total)
		pthread_mutex_init(&info->forks[idx], NULL);
	pthread_mutex_init(&info->m_write, NULL);
	return (0);
}

void init_philo(t_info *info)
{
	int idx;

	idx = -1;
	info->start_time = get_time();
	while (++idx < info->total)
	{
		info->philo[idx].num = idx + 1;
		info->philo[idx].left = idx;
		info->philo[idx].right = (idx + info->total - 1) % info->total;
		info->philo[idx].eat_cnt = 0;
		info->philo[idx].last_eat_time = info->start_time;
		info->philo[idx].info = info;
	}
	//printf("left %d\n", info->philo[0].left);
	//printf("right %d\n", info->philo[0].right);
}