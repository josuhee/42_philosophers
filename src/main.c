/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 14:51:28 by sujo              #+#    #+#             */
/*   Updated: 2021/09/06 15:12:27 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *t_function(void *data)
{
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();

	char *thread_name = (char *)data;
	int i = 0;

	while (i < 3)
	{
		printf("[%s] pid : %u, tid : %x -- %d\n", thread_name, (unsigned int) pid, (unsigned int)tid, i);
		i++;
		sleep(1);
	}
}

int main(int argc, char *argv[])
{
	pthread_t p_thread[2];
	int thr_id;
	int status;
	char p1[] = "thread_1";
	char p2[] = "thread_2";
	char pM[] = "thread_M";

	sleep(1);

	thr_id = pthread_create(&p_thread[0], NULL, t_function, (void *)p1);
	thr_id = pthread_create(&p_thread[1], NULL, t_function, (void *)p2);

	t_function((void *)pM);

	pthread_join(p_thread[0], (void **)&status);
	pthread_join(p_thread[1], (void **)&status);
	return (0);
}
