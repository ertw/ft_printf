#include "./libft.h"

size_t	ft_wstrlen(const wchar_t *ws)
{
	size_t	i;

	i = 0;
	while (*ws++)
		i++;
	return (i);
}
