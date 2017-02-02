#include "printf.h"
#include <stdio.h>

//typedef struct	s_print
//{
//	int		length;
//	char		*buf;
//	size_t		i;
//	char		*out;
//	va_list		ap;
//	char		*flags;
//	int			width;
//	int			precision;
//	int		conversion;
//	char		*conversions;
//}				t_print;

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

char	*ft_uitoa(intmax_t n, int len)
{
	char	*anum;

	anum = ft_strnew(len);
	if (!anum)
		return (NULL);
	n *= n < 0 ? -1 : 1;
	if (n == 0)
		*anum++ = '0';
	while (n)
	{
		*anum++ = n % 10 + '0';
		n /= 10;
	}
	ft_strrev(anum - len, len);
	return (anum - len);
}

char	*justify(intmax_t n, int w, size_t plus, char pad_char)
{
	size_t	len;
	char	sign;
	int	padding;
	int	padding2;
	char	*str;
	char	*num;

	len = ft_countplaces(n, 10);
	sign = '\0';
	if (n < 0)
		sign = '-';
	else if (plus)
		sign = '+';
	padding = w - len - !!sign;
	if (padding < 0)
		padding = 0;
	padding2 = padding;
	str = ft_strnew(len + padding + !!sign);
	if (sign)
		*str++ = sign;
	while (padding > 0)
	{
		*str++ = pad_char;
		--padding;
	}
	str -= (padding2 + !!sign);
	if (pad_char == ' ' && sign)
		ft_strrev(str, (w - len > 0 ? w - len : 0));
	num = ft_uitoa(n, len);
	ft_strnjoin(&str, num, len);
	ft_strdel(&num);
	return (str);
}


char	*justify2(intmax_t n, int w, size_t plus, size_t left, size_t space, char pad_char)
{
	size_t	len;
	char	sign;
	int	adj_w;
	char	*num;
	char	*padding;
	char	*ret;

	ret = NULL;
	len = ft_countplaces(n, 10);
	sign = '\0';
	if (n < 0)
		sign = '-';
	else if (plus)
		sign = '+';
	else if (space)
		sign = ' ';
	adj_w = w - (len + !!sign);
	num = ft_uitoa(n, len);
	padding = ft_strnew(adj_w + !!sign);
	ft_memset(padding, left ? ' ' : pad_char, adj_w + !!sign);
	if (left)
	{
		if (sign)
			ft_strnjoin(&ret, &sign, 1);
		ft_strnjoin(&ret, num, len);
		ft_strnjoin(&ret, padding, adj_w);
	}
	else
	{
		ft_strnjoin(&ret, padding, adj_w);
		ft_strnjoin(&ret, &sign, 1);
		if (sign && pad_char == '0')
			ft_strrev(ret, adj_w + 1);
		ft_strnjoin(&ret, num, len);
	}
	return (ret);
}

//char	*justify(intmax_t n, int w, size_t plus, char pad_char)

int	main(void)
{
	t_print *p;

	p = init("Hello");
	p->width = 10;
	p->f_pad = '0';

	printf("%s\n", justify2(42, 9, 1, 1, 0, ' '));
	printf("%s\n", justify2(42, 9, 0, 1, 0, ' '));
	printf("%s\n", justify2(42, 9, 1, 1, 0, '0'));
	printf("%s\n", justify2(42, 9, 0, 1, 0, '0'));
	printf("%s\n", justify2(-42, 9, 1, 1, 0, ' '));
	printf("%s\n", justify2(-42, 9, 0, 1, 0, ' '));
	printf("%s\n", justify2(-42, 9, 1, 1, 0, '0'));
	printf("%s\n", justify2(-42, 9, 0, 1, 0, '0'));
	printf("%s\n", justify2(42, 9, 1, 0, 0, ' '));
	printf("%s\n", justify2(42, 9, 0, 0, 0, ' '));
	printf("%s\n", justify2(42, 9, 1, 0, 0, '0'));
	printf("%s\n", justify2(42, 9, 0, 0, 0, '0'));
	printf("%s\n", justify2(-42, 9, 1, 0, 0, ' '));
	printf("%s\n", justify2(-42, 9, 0, 0, 0, ' '));
	printf("%s\n", justify2(-42, 9, 1, 0, 0, '0'));
	printf("%s\n", justify2(-42, 9, 0, 0, 0, '0'));
	ft_putendl("---");
	printf("%s\n", justify2(42, 9, 1, 1, 1, ' '));
	printf("%s\n", justify2(42, 9, 0, 1, 1, ' '));
	printf("%s\n", justify2(42, 9, 1, 1, 1, '0'));
	printf("%s\n", justify2(42, 9, 0, 1, 1, '0'));
	printf("%s\n", justify2(-42, 9, 1, 1, 1, ' '));
	printf("%s\n", justify2(-42, 9, 0, 1, 1, ' '));
	printf("%s\n", justify2(-42, 9, 1, 1, 1, '0'));
	printf("%s\n", justify2(-42, 9, 0, 1, 1, '0'));
	printf("%s\n", justify2(42, 9, 1, 0, 1, ' '));
	printf("%s\n", justify2(42, 9, 0, 0, 1, ' '));
	printf("%s\n", justify2(42, 9, 1, 0, 1, '0'));
	printf("%s\n", justify2(42, 9, 0, 0, 1, '0'));
	printf("%s\n", justify2(-42, 9, 1, 0, 1, ' '));
	printf("%s\n", justify2(-42, 9, 0, 0, 1, ' '));
	printf("%s\n", justify2(-42, 9, 1, 0, 1, '0'));
	printf("%s\n", justify2(-42, 9, 0, 0, 1, '0'));
//	field(p, 100);
//	ft_putchar('\'');
//	ft_putstr(p->out);
//	ft_putendl("'");
//	// minimum field width
//	// pad left with zeros
//	// left adjust on field boundry (pad right with spaces)
//	// space for plus
//	// sign for plus
//	printf("'%+010d'\n", 100);
//	ft_putchar('\'');
//	ft_putstr(ft_itoa_fmt(100, 7, 1));
//	ft_putchar('\'');
//	ft_putchar('\n');
//	ft_putchar('\'');
//	ft_putstr(ft_itoa_fmt(-100, 7, 0));
//	ft_putchar('\'');
//	ft_putchar('\n');
}
