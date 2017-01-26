#include <stdio.h>
#include <stdarg.h>
#include "printf.h"

int	sum(int n, ...)
{
	int	val;
	va_list	ap;
	int	i;

	val = 0;
	i = 0;
	va_start(ap, n);
	while (i++ < n)
	{
		val += va_arg(ap, int);
	}
	va_end(ap);
	return (val);
}

char	*ft_filter(char arr[][3], char *match, size_t len)
{
	size_t	i;
i = 0;
	while (i < len)
	{
		if (ft_strcmp(arr[i], match) == 0)
			return (arr[i]);
		i++;
	}
	return (NULL);
}

int		flags;

#define	F_NONE 0
#define	F_ALTFORM 1
#define	F_PADWITHZEROS 2
#define	F_LEFTJUSTIFY 4
#define	F_SPACEFORPOSITIVES 8
#define	F_PLUSFORPOSITIVES 6

#define	M_NONE 0
#define	M_SHORT 1
#define	M_LONG 2
#define	M_L 3
#define	M_J 4
#define	M_Z 5

//sSpdDioOuUxXcC

t_print	*parse_flags(t_print *p);
t_print	*parse_width(t_print *p);
t_print	*parse_precision(t_print *p);
t_print	*parse_percent(t_print *p);
t_print	*parse_length(t_print *p);
t_print	*parse_conversion(t_print *p);

int	ft_parse(t_print *p)
{
	if (!p || !p->buf)
		return (0);
	while (*p->buf)
		parse_conversion(parse_length(parse_precision(parse_width(parse_flags(parse_percent(p))))));
	return (0);
}
int	ft_printf(const char *format, ...)
{
	t_print	*p;

	p = ft_memalloc(sizeof(p));
	p->buf = ft_strdup(format);
	p->out = NULL;
	va_start(p->ap, format);
	ft_parse(p);
	va_end(p->ap);
	ft_putstr(p->out);
	return (0);
}

int	main(void)
{
	ft_printf("str: %s\nnum: %d\n", "aaa", 111);
	ft_printf("hex: %x\noct: %o\n", 100, 100);
//	p->flags = NULL;
//	printf("%d\n", sum(4, 1, 2, 3, 2));
//	printf ("Characters: %c %c \n", 'a', 65);
//	printf ("Decimals: %d %ld\n", 1977, 65000L);
//	printf ("Preceding with blanks: %10d \n", 1977);
//	printf ("Preceding with zeros : %010d \n", 1977);
//	printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
//	printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
//	printf ("Width trick: %*d \n", 5, 10);
//	printf ("%s \n", "A string");
//	char	flags[][3] = {"#","0","-"," ","+"};
//	char	flags[][1] = {'#','0','-',' ','+'};
//	ft_parse(p);
//	ft_putstr2((char**)flags);
//	printf("%s\n", ft_filter(flags, " ", 5));
//	ft_putchar('\n');
//	ft_parse("aaa%bbb");
//	ft_putchar('\n');
//	ft_parse("aaabbb");
//	ft_putchar('\n');
//	printf("% 10.1d\n", 21);
	return (0);
}
