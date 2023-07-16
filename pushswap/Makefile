
LOOP	=	1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
#			21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40

# FLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address -static-libasan
FLAGS	=	-Wall -Wextra -Werror -g

LIB		=	-L. -lpushswap \
			-Ilibft -Llibft -lft

NAME  = libpushswap.a

SRC	=		ft_stack.c \
			ft_node_dd.c \
			ft_index_dd.c \
			ft_mergesort_dd.c \
			ft_operate_dd.c \
			ft_swap_dd.c \
			ft_rotate_dd.c \
			ft_reverse_dd.c \
			ft_sortmin_dd.c \
			ft_bubblesort_dd.c \
			ft_bubblecont_dd.c \
			ft_sortmore_dd.c

OBJS := $(SRC:.c=.o)

all: $(NAME)

.c.o:
	gcc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	make -C ./libft
	ar -rcs $(NAME) $(OBJS)
	gcc $(FLAGS) main.c $(LIB) -o push_swap

t:	$(NAME)
	$(eval ARG = $(shell shuf -i 0-1000 -n 5))
	./push_swap $(ARG)
	./push_swap $(ARG) | ./checker_linux $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

v:	$(NAME)
	make re
	make -C ./visualizer re
	$(eval ARG = $(shell shuf -i 0-1000 -n 20))
	./push_swap $(ARG) | ./visualizer/pro_checker $(ARG)
	@echo -n "Instructions: "
	@./push_swap $(ARG) | wc -l

c:
	make re
	bash Pushswap_test_linux.sh 20 20

clean:
	rm -f $(OBJS)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re : fclean all

.PHONY : all clean fclean re
