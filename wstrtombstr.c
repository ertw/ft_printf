#include "libft.h"

int		wstrtombstr(char *dst, const wchar_t *ws)
{
	char	*tmp;

	tmp = dst;
	while (*ws)
		tmp += ft_wctomb(tmp, *ws++);
	return (0);
}
