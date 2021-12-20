/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:28:06 by sujo              #+#    #+#             */
/*   Updated: 2021/12/19 22:42:25 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int ft_atoi(char* str) {
	int result, positive;

	result = 0;
	positive = 1;
	while (( 9 <= *str && *str <= 13) || *str == ' ') 
		str++;
	if (*str == '+' || *str == '-') {
		if (*str == '-')
			positive = -1;
		str++;
	}
	while ('0' <= *str && *str <= '9') {
		result *= 10;
		result += (*str - '0') * positive;
		str++;
	}
	return (result);
}


int main(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
	{
		printf("\033[31m[Error] Please enter 4 and 5 numbers.\033[0m\n");
	}
	else
	{
		printf("complete\n");
	}
	return (0);
}
