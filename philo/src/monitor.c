/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 00:43:03 by sujo              #+#    #+#             */
/*   Updated: 2022/01/01 00:43:48 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *must_eat_monitor(void *info_)
{
	int idx;
	t_info *info;

	info = (t_info *)info_;
	idx = -1;
	while (++idx < info->total)
	{
		while (info->philo[idx].eat_cnt != info->must_eat);
	}
	info->is_must_eat = 1;
	// must eat complete
	return (NULL);
}

void *monitor(void *info_)
{
	int idx;
	t_info *info;

	info = (t_info *)info_;
	while (1)
	{
		idx = -1;
		while (++idx < info->total)
		{
			if (info->die >= get_time() - info->philo[idx].last_eat_time)
			{
				info->is_die = 1;
				printf("%d is die.\n");
				return (NULL);
			}
		}
		usleep(100);
	}
}
