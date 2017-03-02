#include "printf.h"

int		ft_wctomb(char *s, wchar_t wchar)
{
	char	*tmp;

	tmp = s;
	if (wchar <= 0x007F)
	{
		*tmp = wchar;
		return (1);
	}
	else if (wchar <= 0x07FF)
	{
		*tmp++ = (wchar >> 6) + 0xC0;
		*tmp = (wchar & 0x3F) + 0x80;
		return (2);
	}
	else if (wchar <= 0xFFFF)
	{
		*tmp++ = (wchar >> 12) + 0xE0;
		*tmp++ = ((wchar >> 6) & 0x3F) + 0x80;
		*tmp++ = (wchar & 0x3F) + 0x80;
		return (3);
	}
	else if (wchar <= 0x10FFFF)
	{
		*tmp++ = (wchar >> 18) + 0xF0;
		*tmp++ = ((wchar >> 12) + 0xE0) + 0x80;
		*tmp++ = ((wchar >> 6) & 0x3F) + 0x80;
		*tmp++ = (wchar & 0x3F) + 0x80;
		return (4);
	}
	return (-1);
}

int		wstrbytelen(const wchar_t *ws)
{
	int	i;

	i = 0;
	while (*ws)
	{
		if (*ws <= 0x007F)
			i++;
		else if (*ws <= 0x07FF)
			i += 2;
		else if (*ws <= 0xFFFF)
			i += 3;
		else if (*ws <= 0x10FFFF)
			i += 4;
		ws++;
	}
	return (i);
}

int		wstrtombstr(char *dst, const wchar_t *ws)
{
	char	*tmp;

	tmp = dst;
	while (*ws)
	{
		tmp += ft_wctomb(tmp, *ws);
		ws++;
	}
	return (0);
}

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
	char		*percent;

	if ((percent = ft_strchr(&p->buf[p->i], '%')))
		{
			if (percent[1] == '%')
			{
				p->r = ft_strwjoin(p, &p->buf[p->i], percent - &p->buf[p->i]);
				p->i += percent - &p->buf[p->i];
				++percent;
			}
			else
			{
				p->r = ft_strwjoin(p, &p->buf[p->i], percent - &p->buf[p->i]);
				p->i += percent - &p->buf[p->i];
			}
			++p->i;
		}
	else
	{
			p->r = ft_strwjoin(p, &p->buf[p->i], -1);
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
		p->precision = -1;
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
	if (!(ret = ft_strnew(len + (precision == -1 ? 0 : precision))))
		return (NULL);
	while (n != 0 || (i == 0 && precision != 0) || i < precision)
	{
		ret[i++] = *(sym + (n % base));
		n /= base;
	}
	ft_strrev(ret, ft_strlen(ret));
	return (ret);
}

char	*cast_uint(t_print *p, unsigned short capital, unsigned short base)
{
	uintmax_t	tmpd;
	char	lengths[][3] = {"hh","h","ll","l","j","z","\0"};
	tmpd = va_arg(p->ap, uintmax_t);
	if (p->length == -1)
		return (ft_uitoabasec((unsigned int)tmpd, base, p->precision, capital));
	else if (ft_strnequ(lengths[p->length], "h", ft_strlen(lengths[p->length])))
		return (ft_uitoabasec((unsigned short)tmpd, base, p->precision, capital));
	else if (ft_strnequ(lengths[p->length], "hh", ft_strlen(lengths[p->length])))
		return (ft_uitoabasec((unsigned char)tmpd, base, p->precision, capital));
	else if (ft_strnequ(lengths[p->length], "l", ft_strlen(lengths[p->length])))
		return (ft_uitoabasec((unsigned long)tmpd, base, p->precision, capital));
	else if (ft_strnequ(lengths[p->length], "ll", ft_strlen(lengths[p->length])))
		return (ft_uitoabasec((unsigned long long)tmpd, base, p->precision, capital));
	else if (ft_strnequ(lengths[p->length], "j", ft_strlen(lengths[p->length])))
		return (ft_uitoabasec((uintmax_t)tmpd, base, p->precision, capital));
	else if (ft_strnequ(lengths[p->length], "z", ft_strlen(lengths[p->length])))
		return (ft_uitoabasec((size_t)tmpd, base, p->precision, capital));
	else
		return (ft_uitoabasec((uintmax_t)tmpd, base, p->precision, capital));
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
		ft_memcpy(ret + (p->f_left || p->f_pad == '0' ? 0 : padding) + 1, capital ? "X" : "x", 1);
	p->r = ft_strwjoin(p, ret, len + padding);
	ft_strdel(&ret);
}

t_print	*fmt_hex(t_print *p, size_t capital)
{
	char	*hexn;
	char	*alt;
	hexn = cast_uint(p, capital, 16);
	if (!*hexn && p->precision == 0 && p->width < 1)
	{
		ft_strwjoin(p, " ", 1);
		return (p);
	}
	if (p->f_alt && p->f_pad != '0')
	{
		alt = capital ? ft_strdup("0X") : ft_strdup("0x");
		ft_strnjoin(&alt, hexn, ft_strlen(hexn));
	}
	justify_hex(p, p->f_alt && *hexn != '0' && p->f_pad != '0' ? alt : hexn, capital);
	ft_strdel(&hexn);
	if (p->f_alt && p->f_pad != '0')
		ft_strdel(&alt);
	return (p);
}

t_print	*fmt_ptr(t_print *p)
{
	char	*hexn;
	char	*alt;
	hexn = cast_uint(p, 0, 16);
//	if (!*hexn && p->precision == 0 && p->width < 1)
//	{
//		ft_strwjoin(p, " ", 1);
//		return (p);
//	}
	alt = ft_strdup("0x");
	ft_strnjoin(&alt, hexn, ft_strlen(hexn));
	justify_hex(p, alt, 0);
	ft_strdel(&hexn);
	ft_strdel(&alt);
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
	p->r = ft_strwjoin(p, ret, len + padding);
	ft_strdel(&ret);
}

t_print	*fmt_oct(t_print *p)
{
	char	*octn;
	char	*alt;

	octn = cast_uint(p, 0, 8);
	if (p->f_alt && *octn != '0')
	{
		alt = ft_strdup("0");
		ft_strnjoin(&alt, octn, ft_strlen(octn));
		justify_oct(p, alt);
		ft_strdel(&alt);
	}
	else
		justify_oct(p, octn);
	ft_strdel(&octn);
	return (p);
}

char	*justify_string(t_print *p, char *str)
{
	int		padding;
	int		len;
	char	*ret;

	len = ft_strlen(str);
	len = len < p->precision || p->precision < 0 ? len : p->precision;
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
	char	*str;

	tmps = va_arg(p->ap, char *);
	if (tmps)
		str = justify_string(p, tmps);
	if (tmps && (p->width > 0 || p->precision != -1))
		p->r = ft_strwjoin(p, str, -1);
	else
		p->r = ft_strwjoin(p, tmps ? tmps : "(null)", -1);
	if (tmps)
		ft_strdel(&str);
	return (p);
}

size_t	ft_wstrlen(const wchar_t *ws)
{
	size_t	i;

	i = 0;
	while (*ws++)
		i++;
	return (i);
}

t_print	*fmt_wstr(t_print *p)
{
	wchar_t	*tmps;
	char	*mbstr;
	char	*str;

	tmps = va_arg(p->ap, wchar_t *);
	if (tmps)
	{
		mbstr = ft_strnew(wstrbytelen(tmps));
		wstrtombstr(mbstr, tmps);
		str = justify_string(p, mbstr);
	}
	if (tmps && (p->width > 0 || p->precision != -1))
		p->r = ft_strwjoin(p, str, -1);
	else
		p->r = ft_strwjoin(p, tmps ? mbstr : "(null)", -1);
	if (tmps)
		ft_strdel(&str);
	return (p);
}

t_print	*fmt_percent(t_print *p)
{
	if (p->precision == 0)
		p->precision = 1;
	p->r = ft_strwjoin(p, justify_string(p, "%"), -1);
	return (p);
}

char	*justify_char(t_print *p, char c)
{
	int		padding;
	char	*ret;

	padding = p->width - 1;
	padding = padding > 0 ? padding : 0;
	ret = ft_strnew(padding + 1);
	ft_memset(ret, ' ', padding + 1);
	if (p->f_left)
		ft_memcpy(ret, &c, 1);
	else
		ft_memcpy(ret + padding, &c, 1);
	return (ret);
}

t_print	*fmt_char(t_print *p)
{
	char	tmpc;
	int	width;
	char	*str;

	width = (p->width > 1 ? p->width : 1);
	tmpc = va_arg(p->ap, intmax_t);
	str = justify_char(p, tmpc);
	p->r = ft_strwjoin(p, str, tmpc ? -1 : width);
	ft_strdel(&str);
	return (p);
}

t_print	*fmt_wchar(t_print *p)
{
	wchar_t	tmpwc;
	char	*mbstr;
	int	width;
	char	*str;

	mbstr = ft_strnew(4);
	width = (p->width > 1 ? p->width : 1);
	tmpwc = va_arg(p->ap, intmax_t);
	ft_wctomb(mbstr, tmpwc);
	str = justify_string(p, mbstr);
	p->r = ft_strwjoin(p, str, tmpwc ? -1 : width);
	ft_strdel(&str);
	ft_strdel(&mbstr);
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
	p->r = ft_strwjoin(p, ret, len + padding);
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
	else if (ft_strnequ(lengths[p->length], "h", ft_strlen(lengths[p->length])))
		justify_uint(p, ft_uitoabasec((unsigned short)tmpd, 10, p->precision, 0));
	else if (ft_strnequ(lengths[p->length], "hh", ft_strlen(lengths[p->length])))
		justify_uint(p, ft_uitoabasec((unsigned char)tmpd, 10, p->precision, 0));
	else if (ft_strnequ(lengths[p->length], "l", ft_strlen(lengths[p->length])))
		justify_uint(p, ft_uitoabasec((unsigned long)tmpd, 10, p->precision, 0));
	else if (ft_strnequ(lengths[p->length], "ll", ft_strlen(lengths[p->length])))
		justify_uint(p, ft_uitoabasec((unsigned long long)tmpd, 10, p->precision, 0));
	else if (ft_strnequ(lengths[p->length], "j", ft_strlen(lengths[p->length])))
		justify_uint(p, ft_uitoabasec((uintmax_t)tmpd, 10, p->precision, 0));
	else if (ft_strnequ(lengths[p->length], "z", ft_strlen(lengths[p->length])))
		justify_uint(p, ft_uitoabasec((size_t)tmpd, 10, p->precision, 0));
	return (p);
}

void	justify_dec(t_print *p, char *digits)
{
	int		padding;
	int		len;
	char	*ret;

	len = ft_strlen(digits);
	padding = p->width - len;
	padding = padding > 0 ? padding : !!p->f_sign;
	ret = ft_strnew(padding + len);
	ft_memset(ret, p->f_pad, padding + len);
	if (p->f_sign)
		*ret = p->f_sign;
	if (p->f_left)
		ft_memcpy(p->f_sign ? ret + 1 : ret, digits, len);
	else
	{
		ft_memcpy(ret + padding, digits, len);
		if (p->f_pad == ' ')
			ft_strrev(ret, padding);
	}
	p->r = ft_strwjoin(p, ret, len + padding);
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
		p->is_signed = ((intmax_t)n < 0 ? 1 : 0);
		p->f_sign = p->is_signed ? '-' : p->f_sign;
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
	char	*tmp;

	if (!p)
		return (NULL);
	if (p->length == -1)
	{
		tmp = ft_uitoabasec(castify(tmpd, p), 10, p->precision, 0);
		justify_dec(p, tmp);
		ft_strdel(&tmp);
	}
	else if (ft_strnequ(lengths[p->length], "hh", ft_strlen(lengths[p->length])))
		justify_dec(p, ft_uitoabasec(castify(tmpd, p), 10, p->precision, 0));
	else if (ft_strnequ(lengths[p->length], "h", ft_strlen(lengths[p->length])))
		justify_dec(p, ft_uitoabasec(castify(tmpd, p), 10, p->precision, 0));
	else if (ft_strnequ(lengths[p->length], "l", ft_strlen(lengths[p->length])))
		justify_dec(p, ft_uitoabasec(castify(tmpd, p), 10, p->precision, 0));
	else if (ft_strnequ(lengths[p->length], "ll", ft_strlen(lengths[p->length])))
		justify_dec(p, ft_uitoabasec(castify(tmpd, p), 10, p->precision, 0));
	else if (ft_strnequ(lengths[p->length], "j", ft_strlen(lengths[p->length])))
		justify_dec(p, ft_uitoabasec(castify(tmpd, p), 10, p->precision, 0));
	else if (ft_strnequ(lengths[p->length], "z", ft_strlen(lengths[p->length])))
		justify_dec(p, ft_uitoabasec(castify(tmpd, p), 10, p->precision, 0));
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
	char	conversions[] = {'s','S','p','d','D','i','o','O','u','U','x','X','c','C','%','\0'};
	int i;

	i = 0;
	if (match_any_char(conversions, p->buf[p->i]))
	{
		if (p->buf[p->i] == 's')
			fmt_str(p);
		else if (p->buf[p->i] == 'S')
		{
			if (MB_CUR_MAX > 1)
				fmt_wstr(p);
			else
				fmt_str(p);
		}
		else if (p->buf[p->i] == 'd' || p->buf[p->i] == 'i'|| p->buf[p->i] == 'D')
		{
			p->length = (p->buf[p->i] == 'D' ? 3 : p->length);
			fmt_dec(p);
		}
		else if (p->buf[p->i] == 'x')
			fmt_hex(p, 0);
		else if (p->buf[p->i] == 'p')
		{
//			p->f_alt = 1;
			p->length = 3;
			fmt_ptr(p);
		}
		else if (p->buf[p->i] == 'X')
			fmt_hex(p, 1);
		else if (p->buf[p->i] == 'o' || p->buf[p->i] == 'O')
		{
			p->length = (p->buf[p->i] == 'O' ? 3 : p->length);
			fmt_oct(p);
		}
		else if (p->buf[p->i] == 'c')
			fmt_char(p);
		else if (p->buf[p->i] == 'C')
			if (MB_CUR_MAX > 1)
				fmt_wchar(p);
			else
				fmt_char(p);
		else if (p->buf[p->i] == 'u' || p->buf[p->i] == 'U')
		{
			p->length = (p->buf[p->i] == 'U' ? 3 : p->length);
			fmt_uint(p);
		}
		else if (p->buf[p->i] == '%')
			fmt_percent(p);
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
//	ft_putstrc(p->out, 200, 20, 20);
	len = p->r;
	write(1, p->out, len);
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
