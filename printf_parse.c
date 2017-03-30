#include "./printf.h"

t_print	*parse_flags(t_print *p)
{
	if (!p || !p->buf)
		return (NULL);
	while (is_flag(p->buf[p->i]))
	{
		if (p->buf[p->i] == ' ' && p->f_sign != '+')
			p->f_sign = ' ';
		else if (p->buf[p->i] == '+')
			p->f_sign = '+';
		else if (p->buf[p->i] == '-')
			p->f_left = 1;
		else if (p->buf[p->i] == '#')
			p->f_alt = 1;
		else if (p->buf[p->i] == '0' && !p->f_left)
			p->f_pad = '0';
		++(p->i);
	}
	return (p);
}

t_print	*parse_width(t_print *p)
{
	if (!p || !p->buf)
		return (NULL);
	if (ft_isdigit(p->buf[p->i]) || p->buf[p->i] == '*')
	{
		if (p->buf[p->i] == '*')
		{
			p->width = va_arg(p->ap, uintmax_t);
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

t_print	*parse_precision(t_print *p)
{
	if (!p || !p->buf)
		return (NULL);
	if (!(p->buf[p->i] == '.'))
		return (p);
	++(p->i);
	if (ft_isdigit(p->buf[p->i]))
	{
		p->precision = ft_atoi(&p->buf[p->i]);
		p->i += ft_countplaces(ft_atoi(&p->buf[p->i]), 10);
	}
	else if (p->buf[p->i] == '*')
	{
		p->precision = va_arg(p->ap, uintmax_t);
		++(p->i);
	}
	else
		p->precision = 0;
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

t_print	*parse_conversion(t_print *p)
{
	char	conversions[] = {'s','S','p','d','D','i','o','O','u','U','x','X','c','C','%','\0'};

	if (match_any_char(conversions, p->buf[p->i]))
	{
		if (p->buf[p->i] == 's' || p->buf[p->i] == 'S')
			dispatch_string(p);
		else if (p->buf[p->i] == 'd' || p->buf[p->i] == 'i'|| p->buf[p->i] == 'D')
			dispatch_decimal(p);
		else if (p->buf[p->i] == 'x' || p->buf[p->i] == 'X')
			fmt_hex(p, !!(p->buf[p->i] == 'X'));
		else if (p->buf[p->i] == 'p')
			dispatch_pointer(p);
		else if (p->buf[p->i] == 'o' || p->buf[p->i] == 'O')
			dispatch_oct(p);
		else if (p->buf[p->i] == 'c' || p->buf[p->i] == 'C')
			dispatch_char(p);
		else if (p->buf[p->i] == 'u' || p->buf[p->i] == 'U')
			dispatch_unsigned(p);
		else if (p->buf[p->i] == '%')
			fmt_percent(p);
		p->conversion = p->buf[p->i];
		++(p->i);
	}
	return (p);
}

t_print	*parse_percent(t_print *p)
{
	char		*percent;

	if ((percent = ft_strchr(&p->buf[p->i], '%')))
		{
			if (percent[1] == '%')
			{
				p->r = ft_strwfjoin(p, &p->buf[p->i], percent - &p->buf[p->i]);
				p->i += percent - &p->buf[p->i];
				++percent;
			}
			else
			{
				p->r = ft_strwfjoin(p, &p->buf[p->i], percent - &p->buf[p->i]);
				p->i += percent - &p->buf[p->i];
			}
			++p->i;
		}
	else
	{
			p->r = ft_strwfjoin(p, &p->buf[p->i], -1);
			p->i += ft_strlen(&p->buf[p->i]);
	}
	return (p);
}
