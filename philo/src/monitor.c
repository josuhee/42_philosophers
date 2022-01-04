/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 00:43:03 by sujo              #+#    #+#             */
/*   Updated: 2022/01/04 15:40:11 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*must_eat_monitor(void *info_)
{
	int		idx;
	t_info	*info;

	info = (t_info *)info_;
	idx = -1;
	while (++idx < info->total)
	{
		while (info->philo[idx].eat_cnt <= info->must_eat)
		{
			if (info->is_die)
				return (NULL);
		}
	}
	info->is_must_eat = 1;
	philo_status_prnt(&info->philo[0], FULL);
	return (NULL);
}

void	*monitor(void *info_)
{
	int		idx;
	t_info	*info;

	info = (t_info *)info_;
	while (1)
	{
		idx = -1;
		while (++idx < info->total)
		{
			if (info->is_must_eat)
				return (NULL);
			if (info->die < get_time() - info->philo[idx].last_eat_time)
			{
				info->is_die = 1;
				philo_status_prnt(&info->philo[idx], DIED);
				return (NULL);
			}
		}
		usleep(100);
	}
}
