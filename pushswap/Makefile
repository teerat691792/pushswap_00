



FLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address

LIB		=	-L. -lpushswap \
			-Ilibft -Llibft -lft

NAME  = libpushswap.a

SRC	= 		ft_pushswap.c \
			ft_node.c

OBJS := $(SRC:.c=.o)

all: $(NAME)

.c.o:
	gcc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	make -C ./libft
	ar -rcs $(NAME) $(OBJS)
	gcc $(FLAGS) ft_main.c $(LIB) -o push_swap

t:
	gcc $(FLAGS) ft_main.c $(LIB) -o push_swap

clean:
	rm -f $(OBJS)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re : fclean all

.PHONY : all clean fclean re
