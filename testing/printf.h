#include "../libft/libft.h"

typedef struct	s_print
{
	char	*buf;
	char	*out;
	size_t	flags;
	size_t	width;
	size_t	precision;
	size_t	length;
	char	conversion;
}		t_print;
