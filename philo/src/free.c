/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 02:01:09 by sujo              #+#    #+#             */
/*   Updated: 2022/01/02 02:03:27 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void free_mutex(t_info *info)
{
	int idx;

	idx = -1;
	while (++idx < info->total)
	{
		pthread_mutex_destroy(&info->forks[idx]);
	}
	pthread_mutex_destroy(&info->m_write);
}