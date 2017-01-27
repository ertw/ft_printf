#ifndef	PRINTF_H
# define PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
#endif

typedef struct	s_print
{
	char		*buf;
	char		*out;
	va_list		ap;
	size_t		flags;
	size_t		width;
	size_t		precision;
	size_t		length;
	char		conversion;
}				t_print;
