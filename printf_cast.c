#include "./printf.h"

uintmax_t	cast_int(intmax_t n, t_print *p)
{

	p->f_sign = (int)n < 0 ? '-' : p->f_sign;
	return ((int)n < 0 ? -(int)n : (unsigned int)n);
}

uintmax_t	cast_sizet(intmax_t n, t_print *p)
{
	p->f_sign = (intmax_t)n < 0 ? '-' : p->f_sign;
	return ((size_t)n);
}

uintmax_t	cast_intmax(intmax_t n, t_print *p)
{
	p->f_sign = (intmax_t)n < 0 ? '-' : p->f_sign;
	return ((intmax_t)n < 0 ? -(intmax_t)n : (uintmax_t)n);
}

uintmax_t	castify(intmax_t n, t_print *p)
{
	if (p->length == 0)
	{
		p->f_sign = (signed char)n < 0 ? '-' : p->f_sign;
		return ((signed char)n < 0 ? -(signed char)n : (unsigned char)n);
	}
	if (p->length == 1)
	{
		p->f_sign = (short)n < 0 ? '-' : p->f_sign;
		return ((short)n < 0 ? -(short)n : (unsigned short)n);
	}
	if (p->length == 3)
	{
		p->f_sign = (long)n < 0 ? '-' : p->f_sign;
		return ((long)n < 0 ? -(long)n : (long long)n);
	}
	if (p->length == 2)
	{
		p->f_sign = (long long)n < 0 ? '-' : p->f_sign;
		return ((long long)n < 0 ? -(long long)n : (unsigned long long)n);
	}
	if (p->length == 4)
		return (cast_intmax(n, p));
	if (p->length == 5)
		return (cast_sizet(n, p));
	return (cast_int(n, p));
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
t_print	*fmt_hex(t_print *p, size_t capital)
{
	char	*hexn;
	char	*alt;
	hexn = cast_uint(p, capital, 16);
	if (!*hexn && p->precision == 0 && p->width < 1)
	{
		ft_strwfjoin(p, " ", 1);
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
	ft_strdel(&hexn);
	return (p);
}
