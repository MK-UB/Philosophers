/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:55:42 by melayoub          #+#    #+#             */
/*   Updated: 2023/06/19 14:14:39 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_list	*philo;

	if (!ft_checker(ac, av))
		return (0);
	philo = ft_lst_maker(av);
	ft_init(philo);
	ft_threader(philo);
	check_death(philo);
	return (0);
}
