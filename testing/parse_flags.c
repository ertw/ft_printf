#include "printf.h"

t_print	*parse_flags(t_print *p)
{
	if (!p || !p->buf)
		return (NULL);
	char	flags[] = {'#','0','-',' ','+','\0'};
	int	i = 0;

	while (flags[i])
	{
		if (flags[i] == *p->buf)
		{
			ft_putchar(*p->buf);
			++(p->buf);
			return (p);
		}
		i++;
	}
	return (p);
}
