#include "printf.h"

static int	is_width(char c)
{
	if (c == '*' || ft_isdigit(c))
		return (1);
	return (0);
}

t_print	*parse_width(t_print *p)
{
	if (is_width(*p->buf))
	{
		if (p->buf[p->pos] == '*')
			ft_putchar(*p->buf++);
		else
		{
			p->width = ft_atoi(p->buf);
//			ft_putnbr(ft_atoi(p->buf));
			p->buf += ft_countplaces(ft_atoi(p->buf), 10);
			p->pos += ft_countplaces(ft_atoi(p->buf), 10);
		}
	}
	return (p);
}
