/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:48:00 by melayoub          #+#    #+#             */
/*   Updated: 2023/06/20 17:12:32 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_threader(t_list *philo)
{
	int	i;

	philo->data->time_start = get_time();
	i = 0;
	while (i < philo->data->number_of_philos)
	{
		philo->last_meal = get_time();
		if (pthread_create(&philo->thread, NULL, routine, philo))
			return ;
		if (pthread_detach(philo->thread))
			return ;
		philo = philo->next;
		i++;
	}
}

void	ft_print(long time, int index_id, char *str, t_list *philo)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%ld	%d	%s\n", time, index_id, str);
	pthread_mutex_unlock(&philo->data->print);
}

void	ft_locker(t_list *philo)
{
	pthread_mutex_lock(&philo->fork);
	ft_print(timestamp(philo), philo->index_id, "has taken a fork", philo);
	pthread_mutex_lock(&philo->next->fork);
	ft_print(timestamp(philo), philo->index_id, "has taken a fork", philo);
	ft_print(timestamp(philo), philo->index_id, "is eating", philo);
	pthread_mutex_lock(&philo->data->print);
}

void	*routine(void *content)
{
	t_list	*philo;

	philo = (t_list *)content;
	if (philo->index_id % 2)
	{
		ft_usleep (4);
	}
	while (1)
	{
		ft_locker(philo);
		philo->last_meal = get_time();
		philo->number_of_meals += 1;
		if (philo->number_of_meals == philo->data->must_eat)
			philo->data->count++;
		pthread_mutex_unlock(&philo->data->print);
		ft_usleep(philo->data->time_to_eat);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		ft_print(timestamp(philo), philo->index_id, "is sleeping", philo);
		ft_usleep(philo->data->time_to_sleep);
		ft_print(timestamp(philo), philo->index_id, "is thinking", philo);
	}
	return (NULL);
}

void	check_death(t_list *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->data->print);
		if (get_time() - philo->last_meal > philo->data->time_to_die)
		{
			printf("%ld	%d	died\n", timestamp(philo), philo->index_id);
			return ;
		}
		if (philo->data->count == philo->data->number_of_philos)
			return ;
		pthread_mutex_unlock(&philo->data->print);
		usleep(100);
		philo = philo->next;
	}
}
