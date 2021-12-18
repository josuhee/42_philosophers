/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:28:06 by sujo              #+#    #+#             */
/*   Updated: 2021/12/18 01:40:26 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
	{
		printf("\033[31m[Error] Please enter 4 and 5 arguments.\033[0m\n");
	}
	else
	{
		printf("complete\n");
	}
	return (0);
}
