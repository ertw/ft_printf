#include "printf.h"

int	is_flag(char c)
{
	char	flags[] = {'#','0','-',' ','+','\0'};
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == c)
			return (1);
		++i;
	}
	return (0);
}

t_print	*p_reset(t_print *p)
{
	p->f_sign = '\0';
	p->f_left = 0;
	p->f_alt = 0;
	p->f_pad = ' ';
	p->width = -1;
	p->precision = -1;
	p->length = -1;
	p->conversion = -1;
	p->base = 10;
	p->capital = 0;
	return (p);
}

t_print	*p_init(const char * buf)
{
	t_print	*p;

	if (!buf)
		return (NULL);
	p = ft_memalloc(sizeof(*p));
	p->buf = ft_strdup(buf);
	p->out = NULL;
	p->i = 0;
	p->r = 0;
	return (p_reset(p));
}

int     ft_printf(const char *format, ...)
{
	t_print	*p;
	int	len;

	p = p_init(format);
	va_start(p->ap, format);
	while (p->buf[p->i])
	{
		p_reset(p);
		parse_conversion(parse_length(parse_precision(parse_width(parse_flags(parse_percent(p))))));
	}
	va_end(p->ap);
	len = p->r;
	write(1, p->out, len);
	ft_strdel(&p->buf);
	ft_strdel(&p->out);
	free(p);
	p = NULL;
	return (len);
}
