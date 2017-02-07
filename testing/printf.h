#ifndef	PRINTF_H
# define PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
#endif

typedef struct	s_print
{
	int		length;
	char		*buf;
	size_t		i;
	char		*out;
	va_list		ap;
//	char		*flags;
	char		f_plus;
	size_t		f_left;
	size_t		f_alt;
	char		f_pad;
	size_t			is_signed;
	int			width;
	int			precision;
	int		conversion;
	size_t		extraneous_length;
}				t_print;
