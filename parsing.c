/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:58:27 by melayoub          #+#    #+#             */
/*   Updated: 2023/06/20 14:02:25 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
}

void	alloc_err(t_data *data, int flag)
{
	printf("allocation error\n");
	if (flag)
		free(data);
}

long	ft_atoi(char *str)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		return (ft_error(), 0);
	if (str[i] == '+')
		i++;
	if (str[i] <= '0' && str[i] >= '9')
		return (ft_error(), 0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i])
		return (ft_error(), 0);
	return (res);
}

int	ft_check(char **str)
{
	int	i;

	i = 1;
	if (ft_atoi(str[1]) == 0)
		return (0);
	while (str[i])
	{
		if (!ft_atoi(str[i]))
			return (0);
		if (!str[i] || ft_atoi(str[i]) > INT_MAX)
		{
			ft_error();
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_checker(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		printf("Error\n");
		return (0);
	}
	if (!ft_check(av))
		return (0);
	return (1);
}
