/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujo <sujo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 01:28:06 by sujo              #+#    #+#             */
/*   Updated: 2021/12/20 00:05:30 by sujo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int ft_atoi(char* str)
{
	unsigned int result;

	result = 0;
	while ('0' <= *str && *str <= '9')
	{
		result *= 10;
		result += (*str - '0');
		str++;
	}
	if (result > 2147483647)
		result = 0;
	return (result);
}

static int check_ft_atoi(char *argv[], int *num, int size)
{
	int idx;

	idx = -1;
	while (++idx < size)
		num[idx] = ft_atoi(argv[idx + 1]);
	idx = -1;
	while (++idx < size)
		if (num[idx] == 0)
			return (1);
	return (0);
}

static int check_number_util(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

static int check_number(int argc, char *argv[])
{
	int idx;

	idx = 0;
	while (++idx < argc)
	{
		if (check_number_util(argv[idx]))
			return (1);
	}
	return (0);
}

int main(int argc, char *argv[])
{
	int *num;

	if (argc < 5 || argc > 6 || check_number(argc, argv))
	{
		printf("\033[31m[Error] Please enter 4 and 5 numbers.\033[0m\n");
	}
	else
	{
		num = malloc(sizeof(int) * (argc - 1));
		if (num == 0)
			printf("\033[31m[Error] Fail allocation\033[0m\n");
		else
		{
			if (check_ft_atoi(argv, num, argc - 1))
				printf("\033[31m[Error] Please enter the right number.\033[0m\n");
			else
			{
				printf("complete\n");
			}
		}
		free(num);
	}
	return (0);
}
