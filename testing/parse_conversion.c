#include "printf.h"

t_print	*parse_conversion(t_print *p)
{
//	char	conversions[][2] = {"s","S","p","d","D","i","o","O","u","U","x","X","c","c"."\0"};
	char	conversions[] = {'s','S','p','d','D','i','o','O','u','U','x','X','c','c','\0'};
	int i = 0;
	char	*tmps;
	char	tmpd;
	while (conversions[i])
	{
		if (conversions[i] == *(p->buf))
		{
			if (*p->buf == 's')
			{
				tmps = va_arg(p->ap, char *);
				ft_strnjoin(&p->out, tmps, ft_strlen(tmps));
			}
			else if (*p->buf == 'd')
			{
				tmpd = va_arg(p->ap, intmax_t);
				ft_strnjoin(&p->out, ft_itoa(tmpd), ft_countplaces(tmpd, 10));
			}
			else if (*p->buf == 'x')
			{
				tmpd = va_arg(p->ap, intmax_t);
				ft_strnjoin(&p->out, ft_itoa_base(tmpd, 16), ft_countplaces(tmpd, 16));
			}
			else if (*p->buf == 'o')
			{
				tmpd = va_arg(p->ap, intmax_t);
				ft_strnjoin(&p->out, ft_itoa_base(tmpd, 8), ft_countplaces(tmpd, 8));
			}
			++(p->buf);
			return (p);
		}
		i++;
	}
	return (p);
}
