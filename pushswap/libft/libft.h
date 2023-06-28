/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:50:04 by tkulket           #+#    #+#             */
/*   Updated: 2023/05/29 15:58:50 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <stddef.h>
# include <string.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>

/*		Libft			*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
char	*ft_itoa(int n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

/*		Get_next_line		*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

//utils.c
size_t	ft_strnlen(char *str);
int		ft_find_newline(char *str);
void	*ft_strncpy(char *dst, char *src, int len);
char	*ft_strndup(char *str, int len);
char	*ft_strnjoin(char *dst, char *src);

/*		Printf				*/
int		ft_printf(const char *str, ...);
int		ft_format(char *tmp, va_list args);

//Utility
int		ft_print_s(va_list args, int len);
int		ft_print_d(va_list args, int len);
int		ft_print_u(va_list args, int len);
int		ft_print_p(va_list args, int len);
int		ft_print_x(va_list args, int len);
int		ft_print_upperx(va_list args, int len);

//extra
int		ft_putstr(char *s);
int		ft_putchar(char c);
char	*ft_utoa(unsigned int n);
char	*ft_htoa(unsigned int n);
char	*ft_address(unsigned long n);
char	*ft_toupper_h(char *str);

#endif
