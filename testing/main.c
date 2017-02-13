#include "../libft/libft.h"
#include <stdio.h>
#include "printf.h"

//void	capture(unsigned short n, ...)
//{
//	va_list		ap;
//	intmax_t	num;
//	va_start(ap, n);
//	num = va_arg(ap, intmax_t);
//	num = castify(num);
//	va_end(ap);
//	printf("%d\n", num);
//}

int		main(void)
{
	const char	formatstring[] = " %.5s\n";
	char		number = 0;
	int		number2 = 0;
	char		char1 = 0;
	char		*mystring = ft_strdup("Stringly");
	intmax_t	my_num;
	printf("%O%O%O%O%O\n", 1, 100, 999, 42, 999988888);
	ft_printf("%O%O%O%O%O\n", 1, 100, 999, 42, 999988888);
//	capture(1, -42);
//	my_num = (intmax_t)number;
//	printf("%d", my_num);
//	ft_putnbr(ft_strwjoin(&mystring, mystring, -1));
//	ft_putnbr(printf(formatstring, mystring));
//	ft_putnbr(ft_printf(formatstring, mystring));
//	ft_putnbr(printf(formatstring, number));
//	ft_putnbr(ft_printf(formatstring, number));
//	printf(" %-10d \n", number);
//	printf(" %010d \n", number);
//	printf(" %-#10x \n", number);  
//	printf(" %#x \n", number);
}
