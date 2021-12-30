/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 07:42:23 by sujo              #+#    #+#             */
/*   Updated: 2021/12/30 08:56:50 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void fork(t_philo *philo)
{
	if (philo->info->is_die || philo->info->is_must_eat)
		return ;
	pthread_mutex_lock(&philo->info->forks[philo->left]);
	// print get fork
	pthread_mutex_lock(&philo->info->forks[philo->right]);
	// print get fork
}

void eat(t_philo *philo)
{
	if (philo->info->is_die || philo->info->is_must_eat)
		return ;
}

void unfork(t_philo *philo)
{
	if (philo->info->is_die || philo->info->is_must_eat)
		return ;
	pthread_mutex_unlock(&philo->info->forks[philo->left]);
	pthread_mutex_unlock(&philo->info->forks[philo->right]);
}