#include "printf.h"

static void	ft_putnstr(char *str, size_t n)
{
	while (*str && n--)
		ft_putchar(*str++);
}

t_print	*parse_length(t_print *p)
{
	char	lengths[][3] = {"hh","h","ll","l","j","z","\0"};
	int i = 0;

	while (*lengths[i])
	{
		if (ft_strnequ(lengths[i], p->buf, ft_strlen(lengths[i])))
		{
			ft_putnstr(p->buf, ft_strlen(lengths[i]));
			p->buf += ft_strlen(lengths[i]);
			return (p);
		}
		i++;
	}
	return (p);
}
