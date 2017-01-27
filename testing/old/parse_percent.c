#include "printf.h"

t_print	*parse_percent(t_print *p)
{
	char	*percent;

	percent = NULL;
	if ((percent = ft_strchr(p->buf + p->pos, '%')))
	{
		if (*(percent + 1) == '%')
		{
			percent++;
			p->out = ft_strnjoin(&p->out, p->buf, percent - p->buf);
//			ft_putnstr(p->buf, percent - p->buf);
			p->buf += percent - p->buf;
			p->pos += percent - p->buf;
		}
		else
		{
			p->out = ft_strnjoin(&p->out, p->buf, percent - p->buf);
//			ft_putnstr(p->buf, percent - p->buf);
			p->buf += percent - p->buf;
			p->pos += percent - p->buf;
		}
	}
	if (percent)
	{
		++(p->buf);
		++(p->pos);
	}
	else
	{
		p->out = ft_strnjoin(&p->out, p->buf, ft_strlen(p->buf));
//		ft_putstr(p->buf);
		p->buf += ft_strlen(p->buf);
		p->pos += ft_strlen(p->buf);
	}
	return (p);
}

int		main(void)
{
	t_print	*p;

	p = ft_memalloc(sizeof(p));
	p->buf = ft_strdup("abc%sdef");
	p->out = NULL;
	p->pos = 0;
	parse_percent(p);
	ft_putnbr(p->pos);
	parse_percent(p);
	ft_putnbr(p->pos);
	ft_putstr(p->out);
	return (0);
}
