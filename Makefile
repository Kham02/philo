NAME	=	philo

OBJ		=	philo.c

srcs	=	$(patsubstr %.c %.o $(OBJ))

HEADER = philo.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY	:	all clean fclean re

all	:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
		$(MAKE) -C ./Libft
		$(CC) $(FLAGS) $(OBJ) Libft/libft.a -o $(NAME)

%.o	: %.c $(HEADER)
		$(CC) $(FLAGS) -c $< -o $@

clean	:
	@make clean -C Libft
	rm -rf $(SRCS)

fclean	:
	@make fclean -C Libft
	rm -rf $(NAME)

re	:
	fclean all