#ifndef	PRINTF_H
# define PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
#endif

typedef struct	s_print
{
	char		*buf;
	size_t		i;
	char		*out;
	va_list		ap;
	size_t		flags;
	int			width;
	int			precision;
	size_t		length;
	char		conversion;
}				t_print;
