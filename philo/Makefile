# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estrong <estrong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 22:07:20 by estrong           #+#    #+#              #
#    Updated: 2022/06/15 22:09:36 by estrong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
FLAGS		=	-Wall -Wextra -Werror
OPTFLAGS	=	-O2

RM			=	rm -rf
AR			=	ar rcs

# ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

NAME 	=	philo
LIB		=	philo.a

HDRS	=	philo.h

FLDR_S	=	srcs/
FLDR_H	=	hdrs/

MAIN_F	=	main.c

SRCS	=	libft_f/ft_atoi.c		libft_f/ft_calloc.c		libft_f/ft_bzero.c			\
			libft_f/ft_strjoin.c	libft_f/ft_strlen.c		libft_f/ft_lstadd_back.c		\
			libft_f/ft_lstnew.c		libft_f/ft_lstlast.c	libft_f/ft_lstclear.c		\
			init.c					parse_input.c			philos_life.c			\
			time.c					write_actions.c			at_exit.c					\

SRC		=	$(addprefix ${FLDR_S},${SRCS})
HDR		=	$(addprefix ${FLDR_H},${HDRS})
OBJS	=	${SRC:%.c=%.o}
MAIN	=	${MAIN_F}

# ------------------------------------------------------------------------------

%.o	:		%.c	${HDR}
			@${CC} ${FLAGS} ${OPTFLAGS} -c -o $@ $<

${NAME}	: 	${OBJS} ${MAIN}
			@${AR} ${LIB} $?
			@${CC} ${FLAGS} ${OPTFLAGS} ${MAIN} ${LIB} -o ${NAME}

all	:		${NAME}

clean	:
			@${RM} ${OBJS} ${OBJS_B} ${LIB} ${LIB_B}

fclean:		clean
			@${RM} ${NAME} ${NAME_B}

re	:		fclean all

.PHONY: re all clean fclean bonus
