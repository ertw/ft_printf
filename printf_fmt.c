#include "./printf.h"

t_print	*fmt_char(t_print *p)
{
	char	tmpc;
	int	width;
	char	*str;

	width = (p->width > 1 ? p->width : 1);
	tmpc = va_arg(p->ap, intmax_t);
	str = justify_char(p, tmpc);
	p->r = ft_strwfjoin(p, str, tmpc ? -1 : width);
	ft_strdel(&str);
	return (p);
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
		p->r = ft_strwfjoin(p, str, -1);
	else
		p->r = ft_strwfjoin(p, tmps ? mbstr : "(null)", -1);
	if (tmps)
	{
		ft_strdel(&mbstr);
		ft_strdel(&str);
	}
	return (p);
}

t_print	*fmt_percent(t_print *p)
{
	if (p->precision == 0)
		p->precision = 1;
	p->r = ft_strwfjoin(p, justify_string(p, "%"), -1);
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
	p->r = ft_strwfjoin(p, str, tmpwc ? -1 : width);
	ft_strdel(&str);
	ft_strdel(&mbstr);
	return (p);
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

t_print	*fmt_dec(t_print *p)
{
	intmax_t	tmpd;
	char		*tmp;

	tmpd = va_arg(p->ap, intmax_t);
	if (!p)
		return (NULL);
	else
	{
		tmp = ft_uitoabasec(castify(tmpd, p), 10, p->precision, 0);
		justify_dec(p, tmp);
		ft_strdel(&tmp);
	}
	return (p);
}

t_print	*fmt_str(t_print *p)
{
	char	*tmps;
	char	*str;

	tmps = va_arg(p->ap, char *);
	if (tmps)
		str = justify_string(p, tmps);
	if (tmps && (p->width > 0 || p->precision != -1))
		p->r = ft_strwfjoin(p, str, -1);
	else
		p->r = ft_strwfjoin(p, tmps ? tmps : "(null)", -1);
	if (tmps)
		ft_strdel(&str);
	return (p);
}

t_print	*fmt_ptr(t_print *p)
{
	char	*hexn;
	char	*alt;
	hexn = cast_uint(p, 0, 16);
	alt = ft_strdup("0x");
	ft_strnjoin(&alt, hexn, ft_strlen(hexn));
	justify_hex(p, alt, 0);
	ft_strdel(&hexn);
	ft_strdel(&alt);
	return (p);
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
