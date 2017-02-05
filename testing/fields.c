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

char	*justify3(intmax_t n, int w, size_t plus, size_t left, size_t space, char pad_char, t_print *p)
{
	if (plus)
		p->f_plus = '+';
	else if (space)
		p->f_plus = ' ';
	else
		p->f_plus = '\0';
	p->f_left = left;
	p->f_pad =pad_char;
	p->width = w;

	char	sign;
	int		padding;
	int		len;
	char	*ret;
	char	*number;

	padding = p->width - (len + !!sign);
	padding = padding > 0 ? padding : 0;
	if (n < 0)
		sign = '-';
	else if (p->f_plus != '\0')
		sign = p->f_plus;
	else if (p->f_pad == '0')
		sign = '0';
	number = ft_uitoa(n, ft_countplaces(n, 10), p->precision);
	len = ft_strlen(number);
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


//char	*justify(intmax_t n, int w, size_t plus, char pad_char)


int	main(void)
{
	t_print *p;

	p = init("Hello");
	p->width = 5;
	p->precision = 5;

	printf("%s\n", justify3(42, 9, 1, 1, 0, ' ', p));
	printf("%s\n", justify3(42, 9, 0, 1, 0, ' ', p));
	printf("%s\n", justify3(42, 9, 1, 1, 0, '0', p));
	printf("%s\n", justify3(42, 9, 0, 1, 0, '0', p));
	printf("%s\n", justify3(-42, 9, 1, 1, 0, ' ', p));
	printf("%s\n", justify3(-42, 9, 0, 1, 0, ' ', p));
	printf("%s\n", justify3(-42, 9, 1, 1, 0, '0', p));
	printf("%s\n", justify3(-42, 9, 0, 1, 0, '0', p));
	printf("%s\n", justify3(42, 9, 1, 0, 0, ' ', p));
	printf("%s\n", justify3(42, 9, 0, 0, 0, ' ', p));
	printf("%s\n", justify3(42, 9, 1, 0, 0, '0', p));
	printf("%s\n", justify3(42, 9, 0, 0, 0, '0', p));
	printf("%s\n", justify3(-42, 9, 1, 0, 0, ' ', p));
	printf("%s\n", justify3(-42, 9, 0, 0, 0, ' ', p));
	printf("%s\n", justify3(-42, 9, 1, 0, 0, '0', p));
	printf("%s\n", justify3(-42, 9, 0, 0, 0, '0', p));
	ft_putendl("---");
	printf("%s\n", justify3(42, 9, 1, 1, 1, ' ', p));
	printf("%s\n", justify3(42, 9, 0, 1, 1, ' ', p));
	printf("%s\n", justify3(42, 9, 1, 1, 1, '0', p));
	printf("%s\n", justify3(42, 9, 0, 1, 1, '0', p));
	printf("%s\n", justify3(-42, 9, 1, 1, 1, ' ', p));
	printf("%s\n", justify3(-42, 9, 0, 1, 1, ' ', p));
	printf("%s\n", justify3(-42, 9, 1, 1, 1, '0', p));
	printf("%s\n", justify3(-42, 9, 0, 1, 1, '0', p));
	printf("%s\n", justify3(42, 9, 1, 0, 1, ' ', p));
	printf("%s\n", justify3(42, 9, 0, 0, 1, ' ', p));
	printf("%s\n", justify3(42, 9, 1, 0, 1, '0', p));
	printf("%s\n", justify3(42, 9, 0, 0, 1, '0', p));
	printf("%s\n", justify3(-42, 9, 1, 0, 1, ' ', p));
	printf("%s\n", justify3(-42, 9, 0, 0, 1, ' ', p));
	printf("%s\n", justify3(-42, 9, 1, 0, 1, '0', p));
	printf("%s\n", justify3(-42, 9, 0, 0, 1, '0', p));


	printf("%+05d\n", 42);
	printf("%010.5d\n", -42);
	printf("% -.5d\n", 42);
	printf("% 04d\n", 42);
	printf("% 04.4d\n", 42);
	ft_putendl(ft_uitoa(42, 2, 5));
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
//	000-123
//	   -123
//	   -003
}


//char	*justify(intmax_t n, int w, size_t plus, char pad_char)

