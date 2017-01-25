#include "printf.h"

t_print	*parse_conversion(t_print *p)
{
//	char	conversions[][2] = {"s","S","p","d","D","i","o","O","u","U","x","X","c","c"."\0"};
	char	conversions[] = {'s','S','p','d','D','i','o','O','u','U','x','X','c','c','\0'};
	int i = 0;
	while (conversions[i])
	{
		if (conversions[i] == *(p->buf))
		{
			ft_putchar(*p->buf);
			++(p->buf);
			return (p);
		}
		i++;
	}
	return (p);
}
