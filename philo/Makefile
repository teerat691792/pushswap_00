
# FLAG = -Wall -Werror -Wextra -g -pthread
FLAG = -Wall -Werror -Wextra -g -pthread -fsanitize=address -static-libasan

LIB		=	-L. -lphilo

NAME  = libphilo.a

SRC	= 	ft_philo.c \
		ft_operatephilo.c \
		ft_startphilo.c

OBJS := $(SRC:.c=.o)

all: $(NAME)

.c.o:
	gcc $(FLAG) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
#	make -C ./libft
	ar -rcs $(NAME) $(OBJS)
# 	gcc $(FLAGS) ft_main.c $(LIB) -o push_swap
	gcc $(FLAG) main.c $(LIB) -o philo

t:
	make -s re
	./philo 5 600 200 300 4

clean:
	rm -f $(OBJS)
#	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
#	make fclean -C ./libft

re : fclean all

.PHONY : all clean fclean re
