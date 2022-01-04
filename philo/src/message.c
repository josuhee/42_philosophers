/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 23:33:53 by sujo              #+#    #+#             */
/*   Updated: 2022/01/04 16:25:03 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	rainbow(void)
{
	int		rain[7];
	int		idx;
	char	*str;

	idx = -1;
	while (++idx < 7)
		rain[idx] = 31 + idx;
	rain[6] = 30;
	str = "All Philosophers ate spaghetti full.\n";
	idx = 0;
	while (str[idx])
	{
		printf("\033[107m\033[%dm%c\033[0m", rain[idx % 7], str[idx]);
		idx++;
	}
}

void	philo_status_prnt(t_philo *philo, int status)
{
	long long	now_time;

	pthread_mutex_lock(&philo->info->m_write);
	if (philo->info->done == 0)
	{
		now_time = get_time() - philo->info->start_time;
		if (status == DIED || status == FULL)
		{
			if (status == DIED)
				printf("\033[31m%llu\t%d died\n\033[0m", now_time, philo->num);
			if (status == FULL)
				rainbow();
			philo->info->done = 1;
		}
		if (status == FORK)
			printf("\033[32m%llu\t%d has taken a fork\n\033[0m", \
			now_time, philo->num);
		if (status == EAT)
			printf("\033[35m%llu\t%d is eating\n\033[0m", now_time, philo->num);
		if (status == SLEEP)
			printf("\033[36m%llu\t%d is sleeping\n\033[0m", now_time, philo->num);
		if (status == THINK)
			printf("%llu\t%d is thinking\n", now_time, philo->num);
	}
	pthread_mutex_unlock(&philo->info->m_write);
}

int	err(void)
{
	printf("\033[31mError !!!\033[0m");
	return (1);
}
