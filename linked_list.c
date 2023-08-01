/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:55:57 by melayoub          #+#    #+#             */
/*   Updated: 2023/06/18 18:43:01 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_list	*ft_lstnew(int index_id, t_data *data)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
	{
		printf("allocation error \n");
		return (NULL);
	}
	ptr->index_id = index_id;
	ptr->last_meal = 0;
	ptr->number_of_meals = 0;
	ptr->data = data;
	return (ptr);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst)
	{
		*lst = new;
		(*lst)->next = *lst;
		return ;
	}
	tmp = *lst;
	while (tmp->next && tmp->next != *lst)
		tmp = tmp->next;
	tmp->next = new;
	new->next = *lst;
}

t_list	*ft_lst_maker(char **av)
{
	t_list	*lst;
	t_data	*data;
	int		n;
	int		index;
	t_list	*new_philosopher;

	data = malloc(sizeof(t_data));
	if (!data)
		return (alloc_err(data, 0), NULL);
	ft_set_up(av, &data);
	index = 0;
	lst = ft_lstnew(++index, data);
	if (!lst)
		return (alloc_err(data, 1), NULL);
	ft_lstadd_back(&lst, lst);
	n = 1;
	while (n < data->number_of_philos)
	{
		new_philosopher = ft_lstnew(++index, data);
		if (!lst)
			return (alloc_err(data, 1), NULL);
		ft_lstadd_back(&lst, new_philosopher);
		n++;
	}
	return (lst);
}
