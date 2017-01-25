#include "printf.h"

static int	is_precision(char c)
{
	if (c == '.')
		return (1);
	return (0);
}

t_print	*parse_precision(t_print *p)
{
	if (is_precision(*p->buf))
	{
		if (ft_isdigit(p->buf[1]))
		{
			ft_putnbr(ft_atoi(++p->buf));
			p->buf += ft_countplaces(ft_atoi(p->buf), 10);
		}
		else
			ft_putchar(*p->buf++);
	}
	return (p);
}
