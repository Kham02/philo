# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estrong <estrong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 15:20:15 by estrong           #+#    #+#              #
#    Updated: 2022/04/22 17:24:41 by estrong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

OBJ		=	philo.c	init.c	end.c	stream.c

srcs	=	$(patsubstr %.c %.o $(OBJ))

HEADER = philo.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY	:	all clean fclean re

all	:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o	: %.c $(HEADER)
		$(CC) $(FLAGS) -c $< -o $@

clean	:
	rm -rf $(SRCS)

fclean	:
	rm -rf $(NAME)

re	:
	fclean all