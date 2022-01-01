/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 23:33:53 by sujo              #+#    #+#             */
/*   Updated: 2022/01/01 00:53:02 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo_status_prnt(t_philo *philo, int status)
{
	long long now_time;

	pthread_mutex_lock(&philo->info->m_write);
	now_time = get_time() - philo->info->start_time;
	if (status == DIED)
	{
		printf("%llu\t%d died\n", now_time, philo->num);
		return ;
	}
	if (status == FORK)
		printf("%llu\t%d has taken a fork\n", now_time, philo->num);
	if (status == EAT)
		printf("%llu\t%d is eating\n", now_time, philo->num);
	if (status == SLEEP)
		printf("%llu\t%d is sleeping\n", now_time, philo->num);
	if (status == THINK)
		printf("%llu\t%d is thinking\n", now_time, philo->num);
	pthread_mutex_unlock(&philo->info->m_write);
}