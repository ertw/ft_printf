#include "printf.h"

static void	ft_putnstr(char *str, size_t n)
{
	while (*str && n--)
		ft_putchar(*str++);
}

t_print	*parse_percent(t_print *p)
{
	char	*percent;

	percent = NULL;
	if ((percent = ft_strchr(p->buf, '%')))
	{
		if (*(percent + 1) == '%')
		{
			percent++;
			p->out = ft_strnjoin(&p->out, p->buf, percent - p->buf);
//			ft_putnstr(p->buf, percent - p->buf);
			p->buf += percent - p->buf;
		}
		else
		{
			p->out = ft_strnjoin(&p->out, p->buf, percent - p->buf);
//			ft_putnstr(p->buf, percent - p->buf);
			p->buf += percent - p->buf;
		}
	}
	if (percent)
		++(p->buf);
	else
	{
		p->out = ft_strnjoin(&p->out, p->buf, ft_strlen(p->buf));
//		ft_putstr(p->buf);
		p->buf += ft_strlen(p->buf);
	}
	return (p);
}
