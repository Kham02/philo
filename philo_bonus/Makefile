CC			=	cc
#-Wall -Wextra -Werror
FLAGS		=	-Wall -Wextra -Werror
#FLAGS_MLX	=	-framework OpenGL -framework AppKit
OPTFLAGS	=	-O2
#BON_FLG0	=	-D BONUS=0
#BON_FLG1	=	-D BONUS=1

RM			=	rm -rf
AR			=	ar rcs

# ------------------------------------------------------------------------------

NAME 	=	philo
NAME_B 	=	philo_bonus
LIB		=	philo.a
LIB_B	=	philo_bonus.a

HDRS	=	philo_bonus.h
#HDRS_B	=

FLDR_S	=	srcs/
FLDR_H	=	hdrs/

FLDR_SB	=	srcs/
FLDR_HB	=	hdrs/

MAIN_F	=	main.c
MAIN_FB	=	main_bonus.c

SRCS	=	libft_f/ft_atoi.c		libft_f/ft_calloc.c		libft_f/ft_bzero.c			\
			libft_f/ft_strjoin.c		libft_f/ft_strlen.c		libft_f/ft_lstadd_back.c		\
			libft_f/ft_lstnew.c		libft_f/ft_lstlast.c		libft_f/ft_lstclear.c		\
			libft_f/ft_lstsize.c															\
			parse_input.c			init.c					write_actions.c				\
			philos_life.c		time.c										\


#$(addprefix mand/, )
SRC		=	$(addprefix ${FLDR_S},${SRCS})
HDR		=	$(addprefix ${FLDR_H},${HDRS})
OBJS	=	${SRCS:%.c=%.o}
MAIN	=	${MAIN_F}

$(addprefix bonus/, )
SRC_B	=	$(addprefix ${FLDR_SB},${SRCS_B})
HDR_B	=	$(addprefix ${FLDR_HB},${HDRS})
OBJS_B	=	${SRCS:%.c=%.o}
MAIN_B	=	${MAIN_FB}

# ------------------------------------------------------------------------------

READY	=	Philo is ready
READY_B	=	Philo_bonus is ready
SWEPT	=	Directory was cleaned
_GREEN	=	\e[32m
_YELLOW	=	\e[33m
_CYAN	=	\e[0;36m
_PURPLE	=	\e[0;35m
_END	=	\e[0m

# ------------------------------------------------------------------------------

%.o:		${SRCS} ${HDRS}
			@${CC} ${FLAGS} -c $< -o $@
# %.o:		%.c	${HDR}
# 			@${CC} ${FLAGS} ${OPTFLAGS} -c -o $@ $<


${NAME}: 	${OBJS} ${MAIN}
			@${AR} ${LIB} $?
			@${CC} ${FLAGS} ${OPTFLAGS} ${MAIN} ${LIB} -o ${NAME_B}
#			@${MAKE} clean
			@printf "${_CYAN}${READY}${_END}\n"


all:		${NAME}

clean:
			@${RM} ${OBJS} ${OBJS_B} ${LIB} ${LIB_B}
			@printf "${_PURPLE}${SWEPT}${_END}\n"

fclean:		clean
			@${RM} ${NAME} ${NAME_B}

re:			fclean all

bonus:		${OBJS_B} ${MAIN_B}
			@${AR} ${LIB_B} $?
			@${CC} ${FLAGS} ${OPTFLAGS} ${MAIN_B} ${LIB_B} -o ${NAME_B}
#			@${MAKE} clean
			@printf "${_CYAN}${READY_B}${_END}\n"


# ------------------------------------------------------------------------------



# ------------------------------------------------------------------------------

.PHONY: re all clean fclean bonus