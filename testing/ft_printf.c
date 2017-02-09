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
	if (p->f_sign)
		ft_putchar(p->f_sign);
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
	ft_putchar(p->f_sign);
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

char	*justify_digit(t_print *p, intmax_t n)
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
	else if (p->f_sign != '\0')
		sign = p->f_sign;
	else if (p->f_pad == '0')
		sign = '0';
	padding = p->width - (len + !!sign);
	padding = padding > 0 ? padding : 0;
	ret = ft_strnew(!!sign + padding + len);
	ft_memset(ret, p->f_pad, !!sign + padding + len);
	if (sign)
		*ret = sign;
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
	p->is_signed = tmpd < 0 ? 1 : 0;
	if (p->length == -1)
		ft_strnjoin(&p->out, justify_digit(p, (int)tmpd), ft_strlen(justify_digit(p, (int)tmpd)));
	else if (ft_strnequ(lengths[p->length], "hh", ft_strlen(lengths[p->length])))
		ft_strnjoin(&p->out, justify_digit(p, (signed char)tmpd), ft_strlen(justify_digit(p, (signed char)tmpd)));
	else if (ft_strnequ(lengths[p->length], "h", ft_strlen(lengths[p->length])))
		ft_strnjoin(&p->out, justify_digit(p, (short)tmpd), ft_strlen(justify_digit(p, (short)tmpd)));
	else if (ft_strnequ(lengths[p->length], "l", ft_strlen(lengths[p->length])))
		ft_strnjoin(&p->out, justify_digit(p, (long)tmpd), ft_strlen(justify_digit(p, (long)tmpd)));
	else if (ft_strnequ(lengths[p->length], "ll", ft_strlen(lengths[p->length])))
		ft_strnjoin(&p->out, justify_digit(p, (long long)tmpd), ft_strlen(justify_digit(p, (long long)tmpd)));
	else if (ft_strnequ(lengths[p->length], "j", ft_strlen(lengths[p->length])))
		ft_strnjoin(&p->out, justify_digit(p, (intmax_t)tmpd), ft_strlen(justify_digit(p, (intmax_t)tmpd)));
	else if (ft_strnequ(lengths[p->length], "z", ft_strlen(lengths[p->length])))
		ft_strnjoin(&p->out, justify_digit(p, (size_t)tmpd), ft_strlen(justify_digit(p, (size_t)tmpd)));
	return (p);
}

int	ft_ucountplaces(uintmax_t n, const size_t base)
{
	int		places;

	if (n == 0)
		return (1);
	places = 0;
	while (n)
	{
		places++;
		n /= base;
	}
	return (places);
}

int	ft_ucp(uintmax_t n, t_print *p)
{
	int		places;
	intmax_t	num;

	num = p->is_signed ? (intmax_t)n : n;
	if (num == 0)
		return (1);
	places = 0;
	while (num)
	{
		places++;
		num /= p->base;
	}
	return (places);
}

char	*ft_uitoabasec(uintmax_t n, size_t base, int precision, size_t capital)
{
	char	*sym;
	int	len;
	int	i;
	char	*ret;

	sym = "0123456789abcdef0123456789ABCDEF";
	sym += 16 * capital;
	len = ft_ucountplaces(n, base);
	i = 0;
	if (!(ret = ft_strnew(len + precision)))
		return (NULL);
	while (n != 0 || (i == 0 && precision != 0) || i < precision)
	{
		ret[i++] = *(sym + (n % base));
		n /= base;
	}
	ft_strrev(ret, ft_strlen(ret));
	return (ret);
}

void	justify_hex(t_print *p, char *digits, size_t capital)
{
	int		padding;
	int		len;
	char	*ret;

	len = ft_strlen(digits);
	padding = p->width - len;
	padding = padding > 0 ? padding : 0;
	ret = ft_strnew(padding + len);
	ft_memset(ret, p->f_pad, padding + len);
	if (p->f_left)
		ft_memcpy(ret, digits, len);
	else
		ft_memcpy(ret + padding, digits, len);
	if (p->f_alt)
		*(ret + 1) = capital ? 'X' : 'x';
	ft_strnjoin(&p->out, ret, len + padding);
	ft_strdel(&ret);
}

t_print	*fmt_hex(t_print *p, size_t capital)
{
	uintmax_t	tmpd;
	int		len;

	if (!p || !p->buf)
		return (NULL);
	tmpd = va_arg(p->ap, uintmax_t);
	if (p->f_alt && tmpd != 0)
	{
		len = ft_countplaces(tmpd, 16);
		if (p->precision <= len)
			p->precision = ++len;
	}
	justify_hex(p, ft_uitoabasec(tmpd, 16, p->precision, capital), capital);
	return (p);
}

void	justify_oct(t_print *p, char *digits)
{
	int		padding;
	int		len;
	char	*ret;

	len = ft_strlen(digits);
	padding = p->width - len;
	padding = padding > 0 ? padding : 0;
	ret = ft_strnew(padding + len);
	ft_memset(ret, p->f_pad, padding + len);
	if (p->f_left)
		ft_memcpy(ret, digits, len);
	else
		ft_memcpy(ret + padding, digits, len);
	ft_strnjoin(&p->out, ret, len + padding);
	ft_strdel(&ret);
}

t_print	*fmt_oct(t_print *p)
{
	uintmax_t	tmpd;
	int		len;

	if (!p || !p->buf)
		return (NULL);
	tmpd = va_arg(p->ap, uintmax_t);
	if (p->f_alt && tmpd != 0)
	{
		len = ft_countplaces(tmpd, 8);
		if (p->precision <= len)
			p->precision = ++len;
	}
	justify_oct(p, ft_uitoabasec(tmpd, 8, p->precision, 0));
	return (p);
}

char	*justify_string(t_print *p, char *str)
{
	int		padding;
	int		len;
	char	*ret;

	len = ft_strlen(str);
	padding = p->width - (len);
	padding = padding > 0 ? padding : 0;
	ret = ft_strnew(padding + len);
	ft_memset(ret, ' ', padding + len);
	if (p->f_left)
		ft_memcpy(ret, str, len);
	else
		ft_memcpy(ret + padding, str, len);
	return (ret);
}

t_print	*fmt_str(t_print *p)
{
	char	*tmps;
	tmps = va_arg(p->ap, char *);
	if (p->width > 0)
		ft_strnjoin(&p->out, justify_string(p, tmps), ft_strlen(justify_string(p, tmps)));
	else
		ft_strnjoin(&p->out, tmps ? tmps : "(null)", ft_strlen(tmps ? tmps : "(null)"));
	return (p);
}

void	justify_uint(t_print *p, char *digits)
{
	int		padding;
	int		len;
	char	*ret;

	len = ft_strlen(digits);
	padding = p->width - len;
	padding = padding > 0 ? padding : 0;
	ret = ft_strnew(padding + len);
	ft_memset(ret, p->f_pad, padding + len);
	if (p->f_left)
		ft_memcpy(ret, digits, len);
	else
		ft_memcpy(ret + padding, digits, len);
	ft_strnjoin(&p->out, ret, len + padding);
	ft_strdel(&ret);
}

t_print	*fmt_uint(t_print *p)
{
	uintmax_t	tmpd;
	tmpd = 0;
	char	lengths[][3] = {"hh","h","ll","l","j","z","\0"};
	if (!p || !p->buf)
		return (NULL);
	tmpd = va_arg(p->ap, uintmax_t);
	if (p->length == -1)
		justify_uint(p, ft_uitoabasec((unsigned int)tmpd, 10, p->precision, 0));
	else if (ft_strnequ(lengths[p->length], "hh", ft_strlen(lengths[p->length])))
		justify_uint(p, ft_uitoabasec((signed char)tmpd, 10, p->precision, 0));
	else if (ft_strnequ(lengths[p->length], "h", ft_strlen(lengths[p->length])))
		justify_uint(p, ft_uitoabasec((short)tmpd, 10, p->precision, 0));
	else if (ft_strnequ(lengths[p->length], "l", ft_strlen(lengths[p->length])))
		justify_uint(p, ft_uitoabasec((long)tmpd, 10, p->precision, 0));
	else if (ft_strnequ(lengths[p->length], "ll", ft_strlen(lengths[p->length])))
		justify_uint(p, ft_uitoabasec((long long)tmpd, 10, p->precision, 0));
	else if (ft_strnequ(lengths[p->length], "j", ft_strlen(lengths[p->length])))
		justify_uint(p, ft_uitoabasec((intmax_t)tmpd, 10, p->precision, 0));
	else if (ft_strnequ(lengths[p->length], "z", ft_strlen(lengths[p->length])))
		justify_uint(p, ft_uitoabasec((size_t)tmpd, 10, p->precision, 0));
	return (p);
}

char	*itoab(uintmax_t n, t_print *p)
{
	char	*sym;
	int	len;
	int	i;
	char	*ret;

	sym = "0123456789abcdef0123456789ABCDEF";
	sym += 16 * p->capital;
	len = ft_ucp(n, p);
	i = 0;
	if (!(ret = ft_strnew(len + p->precision + p->is_signed + 1000)))
		return (NULL);
	while (n != 0 || (i == 0 && p->precision != 0) || i < p->precision)
	{
		ret[i++] = *(sym + (n % p->base));
		n /= p->base;
	}
//	ret[i] = p->is_signed ? '-' : '\0';
	ret[i] = p->f_sign;
	ft_strrev(ret, ft_strlen(ret));
	return (ret);
}

void	justify_dec(t_print *p, char *digits)
{
	int		padding;
	int		len;
	char	*ret;

	len = ft_strlen(digits);
	padding = p->width - len;
	padding = padding > 0 ? padding : 0;
	ret = ft_strnew(padding + len);
	ft_memset(ret, p->f_pad, padding + len);
	if (p->f_left)
		ft_memcpy(ret, digits, len);
	else
		ft_memcpy(ret + padding, digits, len);
	ft_strnjoin(&p->out, ret, len + padding);
	ft_strdel(&ret);
}

uintmax_t	castify(intmax_t n, t_print *p)
{
//	char	lengths[][3] = {"hh","h","ll","l","j","z","\0"};
	if (p->length == 0)
	{
		p->is_signed = ((signed char)n < 0 ? 1 : 0);
		p->f_sign = p->is_signed ? '-' : p->f_sign;
		return ((signed char)n < 0 ? -(signed char)n : (unsigned char)n);
	}
	if (p->length == 1)
	{
		p->is_signed = ((short)n < 0 ? 1 : 0);
		p->f_sign = p->is_signed ? '-' : p->f_sign;
		return ((short)n < 0 ? -(short)n : (unsigned short)n);
	}
	if (p->length == 3)
	{
		p->is_signed = ((long)n < 0 ? 1 : 0);
		p->f_sign = p->is_signed ? '-' : p->f_sign;
		return ((long)n < 0 ? -(long)n : (long long)n);
	}
	if (p->length == 2)
	{
		p->is_signed = ((long long)n < 0 ? 1 : 0);
		p->f_sign = p->is_signed ? '-' : p->f_sign;
		return ((long long)n < 0 ? -(long long)n : (unsigned long long)n);
	}
	if (p->length == 4)
	{
		p->is_signed = ((intmax_t)n < 0 ? 1 : 0);
		p->f_sign = p->is_signed ? '-' : p->f_sign;
		return ((intmax_t)n < 0 ? -(intmax_t)n : (uintmax_t)n);
	}
	if (p->length == 5)
	{
		return ((size_t)n);
	}
	else
	{
		p->is_signed = ((int)n < 0 ? 1 : 0);
		p->f_sign = p->is_signed ? '-' : p->f_sign;
		return ((int)n < 0 ? -(int)n : (unsigned int)n);
	}
}

t_print	*fmt_dec(t_print *p)
{
	intmax_t	tmpd;
	tmpd = va_arg(p->ap, intmax_t);
	char	lengths[][3] = {"hh","h","ll","l","j","z","\0"};
	if (!p)
		return (NULL);
	if (p->length == -1)
		justify_dec(p, itoab(castify(tmpd, p), p));
	else if (ft_strnequ(lengths[p->length], "hh", ft_strlen(lengths[p->length])))
		justify_dec(p, itoab(castify(tmpd, p), p));
	else if (ft_strnequ(lengths[p->length], "h", ft_strlen(lengths[p->length])))
		justify_dec(p, itoab(tmpd, p));
	else if (ft_strnequ(lengths[p->length], "l", ft_strlen(lengths[p->length])))
		justify_dec(p, itoab(castify(tmpd, p), p));
	else if (ft_strnequ(lengths[p->length], "ll", ft_strlen(lengths[p->length])))
		justify_dec(p, itoab(castify(tmpd, p), p));
	else if (ft_strnequ(lengths[p->length], "j", ft_strlen(lengths[p->length])))
		justify_dec(p, itoab(castify(tmpd, p), p));
	else if (ft_strnequ(lengths[p->length], "z", ft_strlen(lengths[p->length])))
		justify_dec(p, itoab(castify(tmpd, p), p));
	return (p);
}

int	match_any_char(char *str, char c)
{
	if (str && *str)
	{
		if (*str == c)
			return (1);
		return (match_any_char(++str, c));
	}
	return (0);
}

t_print	*parse_conversion(t_print *p)
{
	char	conversions[] = {'s','S','p','d','D','i','o','O','u','U','x','X','c','C','\0'};
	int i;
	char	tmpc;

	i = 0;
	if (match_any_char(conversions, p->buf[p->i]))
	{
		if (p->buf[p->i] == 's')
			fmt_str(p);
		else if (p->buf[p->i] == 'd' || p->buf[p->i] == 'i')
			fmt_dec(p);
		else if (p->buf[p->i] == 'x')
			fmt_hex(p, 0);
		else if (p->buf[p->i] == 'X')
			fmt_hex(p, 1);
		else if (p->buf[p->i] == 'o')
			fmt_oct(p);
		else if (p->buf[p->i] == 'O')
		{
			p->length = 3;
			fmt_oct(p);
		}
		else if (p->buf[p->i] == 'c')
		{
			tmpc = va_arg(p->ap, intmax_t);
			if (tmpc)
				ft_strnjoin(&p->out, &tmpc, 1);
			else
			{
				ft_putchar('\0');
				++p->extraneous_length;
			}
		}
		else if (p->buf[p->i] == 'u')
			fmt_uint(p);
		else if (p->buf[p->i] == 'U')
		{
			p->length = 3;
			fmt_uint(p);
		}
		p->conversion = p->buf[p->i];
		++(p->i);
	}
	return (p);
}

t_print	*p_reset(t_print *p)
{
	p->f_sign = '\0';
	p->f_left = 0;
	p->f_alt = 0;
	p->f_pad = ' ';
	p->is_signed = 0;
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
	p->extraneous_length = 0;
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
	len = p->out ? ft_strlen(p->out) : 0;
	len += p->extraneous_length;
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
