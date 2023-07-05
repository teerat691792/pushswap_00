



FLAGS	=	-Wall -Wextra -Werror -g -fsanitize=address

LIB		=	-L. -lpushswap \
			-Ilibft -Llibft -lft

NAME  = libpushswap.a

SRC	= 		ft_pushswap.c \
			ft_node.c \
			ft_operate.c \
			ft_mergesort.c \
			ft_sort_a.c \
			ft_sortmore.c \
			ft_show.c
#			ft_stack.c

OBJS := $(SRC:.c=.o)

all: $(NAME)

.c.o:
	gcc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	make -C ./libft
	ar -rcs $(NAME) $(OBJS)
	gcc $(FLAGS) ft_main.c $(LIB) -o push_swap

t:	$(NAME)
		$(eval ARG = $(shell shuf -i 0-100 -n 8))
		./push_swap $(ARG)

tt:
		for number in 1 2 3 4 ; do echo $$number && make t; done


2:	$(NAME)
		$(eval ARG = $(shell shuf -i 0-100 -n 2))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

3:	$(NAME)
		$(eval ARG = $(shell shuf -i 0-100 -n 3))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

4:	$(NAME)
		$(eval ARG = $(shell shuf -i 0-100 -n 4))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

5:	$(NAME)
		$(eval ARG = $(shell shuf -i 0-100 -n 5))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

6:	$(NAME)
		$(eval ARG = $(shell shuf -i 0-100 -n 6))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

7:	$(NAME)
		$(eval ARG = $(shell shuf -i 0-100 -n 7))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

8:	$(NAME)
		$(eval ARG = $(shell shuf -i 0-100 -n 8))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

9:	$(NAME)
		$(eval ARG = $(shell shuf -i 0-100 -n 9))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

10:	$(NAME)
		$(eval ARG = $(shell shuf -i 0-100 -n 10))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

20:	$(NAME)
		$(eval ARG = $(shell shuf -i 0-100 -n 20))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

50:	$(NAME)
		$(eval ARG = $(shell shuf -i 0-100 -n 50))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l


100:	$(NAME)
		$(eval ARG = $(shell shuf -i 0-1000 -n 100))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

500:	$(NAME)
		$(eval ARG = $(shell shuf -i 0-1000 -n 500))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

1000:	$(NAME)
		$(eval ARG = $(shell shuf -i 0-1000 -n 1000))
		./push_swap $(ARG) | ./checker_linux $(ARG)
		@echo -n "Instructions: "
		@./push_swap $(ARG) | wc -l

clean:
	rm -f $(OBJS)
#	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
#	make fclean -C ./libft

re : fclean all

.PHONY : all clean fclean re
