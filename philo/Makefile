# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebennamr <ebennamr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/27 09:36:34 by ebennamr          #+#    #+#              #
#    Updated: 2023/05/06 22:23:49 by ebennamr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----------------== Variable Block ==--------------------#
NAME = philo
CC = cc
CFALS = -Wall -Wextra -Werror -pthread
SRC =  error.c  ft_atoi.c philo.c strtrim.c utils.c utils2.c monitor.c life.c
INCLUDE =  philo.h
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFALS)  $(OBJ) -o $(NAME)
%.o : %.c $(INCLUDE)
	$(CC) $(CFALS) -c $< -o $@

clean :
	rm -rf $(OBJ)
fclean : clean
	rm -rf $(NAME)
re : fclean all

push : fclean
	git add .
	git commit -m "push"
	git push

