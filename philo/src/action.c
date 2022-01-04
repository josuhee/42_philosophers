/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 07:42:23 by sujo              #+#    #+#             */
/*   Updated: 2022/01/04 14:23:31 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_fork(t_philo *philo)
{
	if (philo->info->is_die || philo->info->is_must_eat)
		return ;
	pthread_mutex_lock(&philo->info->forks[philo->left]);
	philo_status_prnt(philo, FORK);
	pthread_mutex_lock(&philo->info->forks[philo->right]);
	philo_status_prnt(philo, FORK);
}

void	eat(t_philo *philo)
{
	if (philo->info->is_die || philo->info->is_must_eat)
		return ;
	philo_status_prnt(philo, EAT);
	vsleep(philo->info->eat);
	philo->eat_cnt = philo->eat_cnt + 1;
	philo->last_eat_time = get_time();
}

void	unfork(t_philo *philo)
{
	if (philo->info->is_die || philo->info->is_must_eat)
		return ;
	pthread_mutex_unlock(&philo->info->forks[philo->left]);
	pthread_mutex_unlock(&philo->info->forks[philo->right]);
}

void	go_sleep(t_philo *philo)
{
	if (philo->info->is_die || philo->info->is_must_eat)
		return ;
	philo_status_prnt(philo, SLEEP);
	vsleep(philo->info->sleep);
}

void	think(t_philo *philo)
{
	if (philo->info->is_die || philo->info->is_must_eat)
		return ;
	philo_status_prnt(philo, THINK);
}
