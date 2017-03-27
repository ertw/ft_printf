/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 09:07:03 by ewilliam          #+#    #+#             */
/*   Updated: 2017/01/17 14:57:58 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdint.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_vec
{
	size_t			len;
	size_t			size;
	char			*str;
}					t_vec;

int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isspace(char c);
int					ft_isascii(int c);
void				ft_striter(char *s, void (*f)(char *));
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_mempmove(void *dst, const void *src, size_t len);
void				ft_putchar(char c);
void				ft_putstr(const char *s);
void				ft_putstrc(const char *s, int r, int g, int b);
void				ft_putstr2(char **s);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strncpy(char *dst, const char *src, size_t len);
void				ft_strclr(char*s);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strmap(const char *s1, char (*f)(char));
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *ltl, size_t len);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_stpcpy(char *dst, const char *src);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbrhex(int n, int len);
char				*ft_itoa(int n);
char				*ft_itoa_base(int n, const size_t base);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_strdel(char **as);
unsigned int		ft_abs(int n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnjoin(char **old, const char *new, size_t len);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
unsigned int		ft_wordcount(const char *s, const char c, unsigned int ct);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void(*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void(*f)(t_list *elem));
int					ft_countplaces(int n, const size_t base);
void				ft_strrev(char *s, int len);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_atoi(const char *str);
int					ft_isprint(int c);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
int					ft_chrcmp(const char c1, const char c2);
int					ft_strevery(char *ar, int (*f)(char c));
int					ft_strevery2(char **ar, int (*f)(char c));
int					ft_strevery2i(char **ar, int (*f)(char c, int x, int y));
int					ft_streveryi(char *ar, int (*f)(char c, int index));
char				*ft_strndup(const char *s1, size_t len);
int					ft_printf(const char *format, ...);
int					ft_wctomb(char *s, wchar_t wchar);
int					wstrtombstr(char *dst, const wchar_t *ws);
int					wstrbytelen(const wchar_t *ws);
#endif
