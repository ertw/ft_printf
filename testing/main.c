#include "printf.h"

t_print	*parse_percent(t_print *p)
{
	char	*percent;
	size_t	len;

	if ((percent = ft_strchr(&p->buf[p->i], '%')))
		{
			if (percent[1] == '%')
			{
				++percent;
//				ft_putstr(ft_strndup(&p->buf[p->i], percent - &p->buf[p->i]));
				ft_strnjoin(&p->out, &p->buf[p->i], percent - &p->buf[p->i]);
				p->i += percent - &p->buf[p->i];
			}
			else
			{
//				ft_putstr(ft_strndup(&p->buf[p->i], percent - &p->buf[p->i]));
				ft_strnjoin(&p->out, &p->buf[p->i], percent - &p->buf[p->i]);
				p->i += percent - &p->buf[p->i];
			}
			++(p->i);
		}
	else
	{
			ft_strnjoin(&p->out, &p->buf[p->i], ft_strlen(&p->buf[p->i]));
			p->i += ft_strlen(&p->buf[p->i]);
//			ft_putstr(&p->buf[p->i]);
	}
	return (p);
}

t_print	*init(char * buf)
{
	t_print	*p;

	if (!buf)
		return (NULL);
	p = ft_memalloc(sizeof(p));
	p->i = 0;
	p->out = NULL;
	p->buf = ft_strdup(buf);
	return (p);
}

int		main(void)
{
	t_print	*p;

	p = init("abc");
	parse_percent(p);
	ft_putstr(p->out);
	ft_putnbr(p->i);
	ft_putchar('\n');
	p = init("abc%");
	parse_percent(p);
	ft_putstr(p->out);
	ft_putnbr(p->i);
	ft_putchar('\n');
	p = init("abc%%");
	parse_percent(p);
	ft_putstr(p->out);
	ft_putnbr(p->i);
	ft_putchar('\n');
	return (0);
}
