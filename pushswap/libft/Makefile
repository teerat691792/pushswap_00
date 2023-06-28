# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkulket <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/28 19:20:13 by tkulket           #+#    #+#              #
#    Updated: 2023/05/29 15:47:14 by tkulket          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS	= -Wall -Wextra -Werror -g

NAME  = libft.a

LIBFT	= 		ft_memset.c ft_bzero.c ft_memcpy.c\
				ft_memmove.c ft_memchr.c ft_memcmp.c\
				ft_strlen.c ft_isalpha.c ft_isdigit.c\
				ft_isalnum.c ft_isascii.c ft_isprint.c\
				ft_toupper.c ft_tolower.c ft_strchr.c\
				ft_strrchr.c ft_strncmp.c ft_strlcpy.c\
				ft_strlcat.c ft_strnstr.c ft_atoi.c\
				ft_calloc.c ft_strdup.c ft_substr.c\
				ft_strjoin.c ft_strtrim.c ft_split.c\
				ft_itoa.c ft_strmapi.c ft_striteri.c\
				ft_putchar_fd.c ft_putstr_fd.c\
				ft_putendl_fd.c ft_putnbr_fd.c\
				ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
				ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
				ft_lstclear.c ft_lstiter.c ft_lstmap.c\
				\
				\
				get_next_line.c get_next_line_utils.c\
				\
				\
				ft_printf.c ft_utils.c\
				ft_address.c ft_htoa.c ft_putchar.c\
				ft_putstr.c ft_toupper_h.c ft_utoa.c


OBJS := $(LIBFT:.c=.o)

all: $(NAME)

.c.o:
	gcc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all bonus clean fclean re
