#include "printf.h"
#include <stdio.h>

t_print	*parse_percent(t_print *p)
{
	char	*percent;
	size_t	len;

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
		if (p->buf[p->i] == ' ')
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

t_print	*fmt_digit(t_print *p)
{
	intmax_t	tmpd;
	char	lengths[][3] = {"hh","h","ll","l","j","z","\0"};
	if (!p || !p->buf)
		return (NULL);
	tmpd = va_arg(p->ap, intmax_t);
	if (p->length == -1)
		ft_strnjoin(&p->out, ft_itoa(tmpd), ft_countplaces(tmpd, 10));
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
	char	lengths[][3] = {"hh","h","ll","l","j","z","\0"};
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
			return (p);
		}
		++i;
	}
	return (p);
}

t_print	*init(const char * buf)
{
	t_print	*p;

	if (!buf)
		return (NULL);
	p = ft_memalloc(sizeof(*p));
	p->i = 0;
	p->out = NULL;
	p->buf = ft_strdup(buf);
	p->f_plus = '\0';
	p->f_left = 0;
	p->f_alt = 0;
	p->f_pad = ' ';
	p->width = -1;
	p->precision = -1;
	p->length = -1;
	p->conversion = -1;
	return (p);
}

void	print_struct(t_print *p)
{
	ft_putendl("____");
	ft_putstr("out: ");
	ft_putendl(p->out);
	ft_putstr("buf: ");
	ft_putendl(p->buf);
	ft_putstr("ind: ");
	ft_putnbr(p->i);
	ft_putchar('\n');
	ft_putstr("flg: ");
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
	ft_putstr("wid: ");
	ft_putnbr(p->width);
	ft_putchar('\n');
	ft_putstr("pre: ");
	ft_putnbr(p->precision);
	ft_putchar('\n');
	ft_putstr("len: ");
	ft_putnbr(p->length);
	ft_putchar('\n');
	ft_putstr("cnv: ");
	ft_putnbr(p->conversion);
	ft_putchar('\n');
}

int     ft_printf(const char *format, ...)
{
	t_print	*p;
	int	len;

	p = init(format);
	va_start(p->ap, format);
	while (p->buf[p->i])
		parse_conversion(parse_length(parse_precision(parse_width(parse_flags(parse_percent(p))))));
	va_end(p->ap);
	ft_putstrc(p->out, 200, 20, 20);
	len = ft_strlen(p->out) - 1;
	print_struct(p);
	ft_putstr("ret: ");
	ft_putnbr(len);
	ft_putchar('\n');
	ft_strdel(&p->buf);
	ft_strdel(&p->out);
	free(p);
	p = NULL;
	return (len);
}

int		main(void)
{
	const char	formatstring[] = "d1: %d d2: %d\n";
	int		number = 1000L;
	char		char1 = 'q';
	char		mystring[] = "Hellooooo";
	printf(formatstring, number, number);
	ft_printf(formatstring, number, number);
//	printf(" %-10d \n", number);
//	printf(" %010d \n", number);
//	printf(" %-#10x \n", number);  
//	printf(" %#x \n", number);
}
