/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:59:53 by melayoub          #+#    #+#             */
/*   Updated: 2023/06/19 14:24:49 by melayoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo_data
{
	pthread_mutex_t	print;
	int				number_of_philos;
	int				time_to_sleep;
	int				time_to_eat;
	int				time_to_die;
	int				must_eat;
	long			time_start;
	int				count;
}				t_data;

typedef struct s_philosopher
{
	int						index_id;
	long					last_meal;
	int						number_of_meals;
	t_data					*data;
	pthread_mutex_t			fork;
	struct s_philosopher	*next;
	pthread_t				thread;
}				t_list;

void	ft_error(void);
long	ft_atoi(char *str);
int		ft_check(char **str);
int		ft_checker(int ac, char **av);
void	ft_set_up(char **av, t_data **data);
t_list	*ft_lstnew(int index_id, t_data *data);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lst_maker(char **av);
void	ft_init(t_list *lst);
long	get_time(void);
long	timestamp(t_list *philo);
void	ft_usleep(long time);
void	ft_threader(t_list *philo);
void	*routine(void *content);
void	check_death(t_list *philo);
void	alloc_err(t_data *data, int flag);

#endif
