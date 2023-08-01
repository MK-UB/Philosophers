/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:10:25 by melayoub          #+#    #+#             */
/*   Updated: 2023/06/19 14:25:11 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_set_up(char **av, t_data **data)
{
	if (!*data)
		return (alloc_err(*data, 0));
	if (ft_atoi(av[1]) > 0 && ft_atoi(av[2]) > 0 && ft_atoi(av[3]) > 0
		&& ft_atoi(av[4]) > 0)
	{
		(*data)->number_of_philos = ft_atoi(av[1]);
		(*data)->time_to_die = ft_atoi(av[2]);
		(*data)->time_to_eat = ft_atoi(av[3]);
		(*data)->time_to_sleep = ft_atoi(av[4]);
	}
	else
	{
		printf("Error");
		return ;
	}
	if (av[5])
		(*data)->must_eat = ft_atoi(av[5]);
	else
		(*data)->must_eat = -1;
	(*data)->count = 0;
}

void	ft_init(t_list *lst)
{
	int	i;

	i = 0;
	while (lst->data->number_of_philos > i)
	{
		if (pthread_mutex_init(&lst->fork, NULL) != 0)
			return ;
		i++;
		lst = lst->next;
	}
	if (pthread_mutex_init(&lst->data->print, NULL))
		return ;
}

long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long	timestamp(t_list *philo)
{
	long	time_spent;

	time_spent = get_time() - philo->data->time_start;
	return (time_spent);
}

void	ft_usleep(long time)
{
	long	start;

	start = get_time();
	while (get_time() < start + time)
		usleep(100);
}
