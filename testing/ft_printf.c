#include "printf.h"

void	print_struct(t_print *p)
{
	ft_putendl("____");
	ft_putstr("out:        ");
	ft_putendl(p->out);
	ft_putstr("buf:        ");
	ft_putendl(p->buf);
	ft_putstr("index:      ");
	ft_putnbr(p->i);
	ft_putchar('\n');
	ft_putstr("flags:      ");
	ft_putchar('\'');
	if (p->f_plus)
		ft_putchar(p->f_plus);
	if (p->f_left)
		ft_putchar('-');
	if (p->f_alt)
		ft_putchar('#');
	if (p->f_pad == '0')
		ft_putchar('0');
//	p->flags
//		? ft_putendl(p->flags)
//		: ft_putendl("<>");
	ft_putchar('\'');
	ft_putchar('\n');
	ft_putstr("width:      ");
	ft_putnbr(p->width);
	ft_putchar('\n');
	ft_putstr("precision:  ");
	ft_putnbr(p->precision);
	ft_putchar('\n');
	ft_putstr("length:     ");
	ft_putnbr(p->length);
	ft_putchar('\n');
	ft_putstr("conversion: ");
	ft_putnbr(p->conversion);
	ft_putchar('\n');
	ft_putstr("plus:       ");
	ft_putchar(p->f_plus);
	ft_putchar('\n');
	ft_putstr("left:       ");
	ft_putnbr(p->f_left);
	ft_putchar('\n');
	ft_putstr("alt:        ");
	ft_putnbr(p->f_alt);
	ft_putchar('\n');
	ft_putstr("pad ch:     ");
	ft_putchar(p->f_pad);
	ft_putchar('\n');
}

t_print	*parse_percent(t_print *p)
{
	char	*percent;

	if ((percent = ft_strchr(&p->buf[p->i], '%')))
		{
			if (percent[1] == '%')
			{
				++percent;
				ft_strnjoin(&p->out, &p->buf[p->i], percent - &p->buf[p->i]);
				p->i += percent - &p->buf[p->i];
			}
			else
			{
				ft_strnjoin(&p->out, &p->buf[p->i], percent - &p->buf[p->i]);
				p->i += percent - &p->buf[p->i];
			}
			++(p->i);
		}
	else
	{
			ft_strnjoin(&p->out, &p->buf[p->i], ft_strlen(&p->buf[p->i]));
			p->i += ft_strlen(&p->buf[p->i]);
	}
	return (p);
}

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

t_print	*parse_flags(t_print *p)
{
	if (!p || !p->buf)
		return (NULL);
	while (is_flag(p->buf[p->i]))
	{
		if (p->buf[p->i] == ' ' && p->f_plus != '+')
			p->f_plus = ' ';
		else if (p->buf[p->i] == '+')
			p->f_plus = '+';
		else if (p->buf[p->i] == '-')
			p->f_left = 1;
		else if (p->buf[p->i] == '#')
			p->f_alt = 1;
		else if (p->buf[p->i] == '0')
			p->f_pad = '0';
//		ft_strnjoin(&p->flags, &p->buf[p->i], 1);
		++(p->i);
	}
	return (p);
}

int	is_width(char c)
{
	if (c == '*' || ft_isdigit(c))
		return (1);
	return (0);
}

t_print	*parse_width(t_print *p)
{
	if (!p || !p->buf)
		return (NULL);
	if (is_width(p->buf[p->i]))
	{
		if (p->buf[p->i] == '*')
		{
			p->width = -1;
			++(p->i);
		}
		else
		{
			p->width = ft_atoi(&p->buf[p->i]);
			p->i += ft_countplaces(ft_atoi(&p->buf[p->i]), 10);
		}
	}
	return (p);
}

int	is_precision(char c)
{
	if (c == '.')
		return (1);
	return (0);
}

t_print	*parse_precision(t_print *p)
{
	if (!p || !p->buf)
		return (NULL);
	if (!is_precision(p->buf[p->i]))
		return (p);
	++(p->i);
	if (ft_isdigit(p->buf[p->i]))
	{
		p->precision = ft_atoi(&p->buf[p->i]);
		p->i += ft_countplaces(ft_atoi(&p->buf[p->i]), 10);
	}
	else if (p->buf[p->i] == '*')
	{
		p->precision = -1;
		++(p->i);
	}
	if (p->precision > 0)
		p->f_pad = ' ';
	return (p);
}

t_print	*parse_length(t_print *p)
{
	char	lengths[][3] = {"hh","h","ll","l","j","z","\0"};
	size_t	i;

	i = 0;
	while (*lengths[i])
	{
		if (ft_strnequ(lengths[i], &p->buf[p->i], ft_strlen(lengths[i])))
		{
			p->length = i;
			p->i += ft_strlen(lengths[i]);
		}
		i++;
	}
	return (p);
}

char	*ft_uitoa(intmax_t n, int len, int precision)
{
	char	*anum;
	char	*ptr;

	precision -= len;
	precision = precision > 0 ? precision : 0;
	if (!(anum = ft_strnew(len + precision)))
		return (NULL);
	ptr = anum;
	n *= n < 0 ? -1 : 1;
	if (n == 0)
		*anum++ = '0';
	while (n)
	{
		*anum++ = n % 10 + '0';
		n /= 10;
	}
	while (precision--)
		*anum++ = '0';
	ft_strrev(ptr, ft_strlen(ptr));
	return (ptr);
}

char	*justify(t_print *p, int n)
{
	char	sign;
	int		padding;
	int		len;
	char	*ret;
	char	*number;

	number = ft_uitoa(n, ft_countplaces(n, 10), p->precision);
	len = ft_strlen(number);
	sign = '\0';
	if (n < 0)
		sign = '-';
	else if (p->f_plus != '\0')
		sign = p->f_plus;
	else if (p->f_pad == '0')
		sign = '0';
	padding = p->width - (len + !!sign);
	padding = padding > 0 ? padding : 0;
	ret = ft_strnew(!!sign + padding + len);
	ft_memset(ret, p->f_pad, !!sign + padding + len);
	if (sign)
		*ret = sign;
//	ft_putstrc(ft_itoa(padding), 255, 0, 0);
//	ft_putstrc(number, 0, 255, 0);
	if (p->f_left)
	{
		ft_memset(ret + !!sign + len, ' ', padding);
		ft_memcpy(ret + !!sign, number, len);
	}
	else
	{
		if (p->f_pad == ' ')
			ft_strrev(ret, !!sign + padding);
		ft_memcpy(ret + !!sign + padding, number, len);
	}
	ft_strdel(&number);
	return (ret);
}

t_print	*fmt_digit(t_print *p)
{
	intmax_t	tmpd;
	char	lengths[][3] = {"hh","h","ll","l","j","z","\0"};
	if (!p || !p->buf)
		return (NULL);
	tmpd = va_arg(p->ap, intmax_t);
	if (p->length == -1)
		ft_strnjoin(&p->out, justify(p, tmpd), ft_strlen(justify(p, tmpd)));
	else if (ft_strnequ(lengths[p->length], "hh", ft_strlen(lengths[p->length])))
		ft_strnjoin(&p->out, ft_itoa((signed char)tmpd), ft_countplaces(tmpd, 10));
	else if (ft_strnequ(lengths[p->length], "h", ft_strlen(lengths[p->length])))
		ft_strnjoin(&p->out, ft_itoa((short)tmpd), ft_countplaces(tmpd, 10));
	else if (ft_strnequ(lengths[p->length], "l", ft_strlen(lengths[p->length])))
		ft_strnjoin(&p->out, ft_itoa((long)tmpd), ft_countplaces(tmpd, 10));
	else if (ft_strnequ(lengths[p->length], "ll", ft_strlen(lengths[p->length])))
		ft_strnjoin(&p->out, ft_itoa((long long)tmpd), ft_countplaces(tmpd, 10));
	else if (ft_strnequ(lengths[p->length], "j", ft_strlen(lengths[p->length])))
		ft_strnjoin(&p->out, ft_itoa((intmax_t)tmpd), ft_countplaces(tmpd, 10));
	else if (ft_strnequ(lengths[p->length], "z", ft_strlen(lengths[p->length])))
		ft_strnjoin(&p->out, ft_itoa((size_t)tmpd), ft_countplaces(tmpd, 10));
	return (p);
}

t_print	*parse_conversion(t_print *p)
{
	char	conversions[] = {'s','S','p','d','D','i','o','O','u','U','x','X','c','C','\0'};
//	char	lengths[][3] = {"hh","h","ll","l","j","z","\0"};
	int i;
	char	*tmps;
	char	tmpc;
	intmax_t	tmpd;

	i = 0;
	while (conversions[i])
	{
		if (conversions[i] == p->buf[p->i])
		{
			if (conversions[i] == 's')
			{
			//	tmps = va_arg(p->ap, char *);
				tmps = "hello";
				ft_putendl("here");
				ft_strnjoin(&p->out, tmps, ft_strlen(tmps));
			}
			else if (conversions[i] == 'd' || conversions[i] == 'i')
				fmt_digit(p);
			else if (conversions[i] == 'x')
			{
				tmpd = va_arg(p->ap, intmax_t);
				ft_strnjoin(&p->out, ft_itoa_base(tmpd, 16), ft_countplaces(tmpd, 16));
			}
			else if (conversions[i] == 'o')
			{
				tmpd = va_arg(p->ap, intmax_t);
				ft_strnjoin(&p->out, ft_itoa_base(tmpd, 8), ft_countplaces(tmpd, 8));
			}
			else if (conversions[i] == 'c')
			{
				tmpc = va_arg(p->ap, intmax_t);
				ft_strnjoin(&p->out, &tmpc, 1);
			}
			p->conversion = i;
			++(p->i);
//			print_struct(p);
			return (p);
		}
		++i;
	}
	return (p);
}

t_print	*p_reset(t_print *p)
{
	p->f_plus = '\0';
	p->f_left = 0;
	p->f_alt = 0;
	p->f_pad = ' ';
	p->is_signed = -1;
	p->width = -1;
	p->precision = -1;
	p->length = -1;
	p->conversion = -1;
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
//	ft_putstrc(p->out, 200, 20, 20);
	ft_putstr(p->out);
	len = ft_strlen(p->out);
//	print_struct(p);
//	ft_putstr("ret:        ");
//	ft_putnbr(len);
//	ft_putchar('\n');
	ft_strdel(&p->buf);
	ft_strdel(&p->out);
	free(p);
	p = NULL;
	return (len);
}
