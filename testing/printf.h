#include "../libft/libft.h"

typedef struct	s_print
{
	char	*buf;
	size_t	flags;
	size_t	width;
	size_t	precision;
	size_t	modifier;
	char	conversion;
}		t_print;
