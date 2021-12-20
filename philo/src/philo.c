/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 00:08:20 by sujo              #+#    #+#             */
/*   Updated: 2021/12/20 09:26:56 by sujo             ###   ########.fr       */
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
	while (++idx < info->total)
	{
		info->get_fork[idx] = 0;
		info->philo[idx].left = idx;
		info->philo[idx].right = (idx + info->total - 1) % info->total;
	}
	return (0);
}

static void *monitor(void *info_)
{
	int idx;
	t_info *info;

	info = (t_info *)info_;
	while (1)
	{
		idx = -1;
		while (++idx < info->total)
		{
			if (info->is_die)
				return (NULL);
		}
	}
}

int philo(int *num, int size)
{
	t_info info;

	memset(info, 0, sizeof(info));
	if (init_info(&info, num, size))
		return (1);
}