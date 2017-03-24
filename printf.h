#ifndef	PRINTF_H
# define PRINTF_H
# include "./libft.h"
# include <stdarg.h>
#endif

typedef struct		s_print
{
	int				length;
	char			*buf;
	size_t			i;
	char			*out;
	va_list			ap;
	char			f_sign;
	unsigned short	f_left;
	unsigned short	f_alt;
	char			f_pad;
	unsigned short	base;
	unsigned short	capital;
	char			*l[7][3];
	int				width;
	int				precision;
	int				conversion;
	size_t			r;
}					t_print;

int					ft_strwjoin(t_print *p, const char *new, int len);
int					ft_strwfjoin(t_print *p, const char *new, int len);
