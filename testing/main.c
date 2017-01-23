#include <stdio.h>
#include <stdarg.h>
#include "../libft/libft.h"

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
typedef struct	s_print
{
	char	*buf;
	size_t	flags;
	size_t	width;
	size_t	precision;
	size_t	modifier;
	char	conversion;
}		t_print;

typedef	void	(*fnctptr)(void);

int	is_flag(char c)
{
	char	flags[][3] = {"#","0","-"," ","+"};
	if (ft_filter(flags, &c, 5) != NULL)
//	if (c == '#' || c == '0' || c == '-' || c == ' ' || c == '+')
		return (1);
	return (0);
}

int	is_width(char c)
{
	if (c == '*' || ft_isdigit(c))
		return (1);
	return (0);
}

int	is_precision(char c)
{
	if (c == '.')
		return (1);
	return (0);
}

int	is_length(char c)
{
	char	lengths[][3] = {"hh","h","ll","l","j","z"};
	if (ft_filter(lengths, &c, 6) != NULL)
		return (1);
	return (0);
}

int	is_conversion(char c)
{
	char	conversions[][3] = {"s","S","p","d","D","i","o","O","u","U","x","X","c","c"};
	if (ft_filter(conversions, &c, 14) != NULL)
		return (1);
	return (0);
}

char	*parse_flags(char *str)
{
	while (is_flag(*str))
	{
		ft_putchar(*str++);
	}
	return (str);
}

char	*parse_width(char *str)
{
	if (is_width(*str))
	{
		if (*str == '*')
			ft_putchar(*str++);
		else
		{
			ft_putnbr(ft_atoi(str));
			str += ft_countplaces(ft_atoi(str), 10);
		}
	}
	return (str);
}

char	*parse_precision(char *str)
{
	if (is_precision(*str))
	{
		if (ft_isdigit(str[1]))
		{
			ft_putnbr(ft_atoi(++str));
			str += ft_countplaces(ft_atoi(str), 10);
		}
		else
			ft_putchar(*str++);
	}
	return (str);
}

char	*parse_length(char *str)
{
	
	return (str);
}

void	ft_putnstr(char *str, size_t n)
{
	while (*str && n--)
		ft_putchar(*str++);
}

char	*parse_grape(char *str)
{
	char	*grape;

	grape = NULL;
	if ((grape = ft_strchr(str, '%')))
	{
		if (*(grape + 1) == '%')
		{
			grape++;
			ft_putnstr(str, grape - str);
		}
		else
			ft_putnstr(str, grape - str);
	}
	return (grape ? ++grape : str);
}

int	ft_parse(char *str)
{
	t_print	p;

	p.flags = F_NONE;
	p.buf = NULL;

	if (!str)
		return (0);
//	ft_putendl(parse_grape(str));
	ft_putstr(parse_length(parse_precision(parse_width(parse_flags(parse_grape(str))))));
	return (0);
}

void (*strfunctions[64])(char *);

int	main(void)
{
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
	ft_parse("aaa%# 111.999ljbbb");
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
