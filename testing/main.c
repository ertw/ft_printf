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
	const char	formatstring[] = "%lld\n";
	long long		number = 9223372036854775807;
	int		number2 = 42;
	char		char1 = 0;
	char		*mystring = "Stringly";
	intmax_t	my_num;
//	capture(1, -42);
//	my_num = (intmax_t)number;
//	printf("%d", my_num);
	printf(formatstring, number);
	ft_printf(formatstring, number);
//	ft_putnbr(printf(formatstring, number));
//	ft_putnbr(ft_printf(formatstring, number));
//	printf(" %-10d \n", number);
//	printf(" %010d \n", number);
//	printf(" %-#10x \n", number);  
//	printf(" %#x \n", number);
}
