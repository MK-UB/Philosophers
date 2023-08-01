# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melayoub <melayoub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 12:27:23 by melayoub          #+#    #+#              #
#    Updated: 2023/06/19 14:11:58 by melayoub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC	= cc

FLAGS = -Wall -Wextra -Werror 

SRC= parsing.c linked_list.c init.c threading.c main.c 
HEAD = philo.h
OBJ= $(SRC:.c=.o)

all: $(NAME)

%.o: %.c $(HEAD)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean: 
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
