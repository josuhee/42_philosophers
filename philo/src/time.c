/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 07:49:36 by sujo              #+#    #+#             */
/*   Updated: 2022/01/01 04:16:53 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long get_time(void)
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	vsleep(int time)
{
	long long finish_time;

	finish_time = time + get_time();
	while (finish_time > get_time())
	{
		usleep(100);
	}
}