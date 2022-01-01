/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 00:08:20 by sujo              #+#    #+#             */
/*   Updated: 2022/01/01 00:41:41 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 모니터랑 최대 먹는 횟수 용 모니터는 기본 join 으로
// 나머지 철학자들은 detach

static void *philo_action(void *philo_)
{
	t_philo *philo;

	philo = (void *)philo_;
	while (1)
	{
		fort(philo);
		eat(philo);
		unfork(philo);
		go_sleep(philo);
		think(philo);
	}
	return (NULL);
}

int philo(int *num, int size)
{
	t_info info;

	memset(info, 0, sizeof(info));
	if (init_info(&info, num, size))
		return (1);//error 처리 용 함수 만들까?
	init_philo(&info);
}