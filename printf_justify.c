#include "./printf.h"

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
	p->r = ft_strwfjoin(p, ret, len + padding);
	ft_strdel(&ret);
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
	p->r = ft_strwfjoin(p, ret, len + padding);
	ft_strdel(&ret);
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
	p->r = ft_strwfjoin(p, ret, len + padding);
	ft_strdel(&ret);
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
	p->r = ft_strwfjoin(p, ret, len + padding);
	ft_strdel(&ret);
}


