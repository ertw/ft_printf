#include <stdio.h>
#include "../printf.h"

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
	const char	formatstring[] = " %lu\n";
	char		number = -42;
	int		number2 = 0;
	char		char1 = 0;
	char		*mystring = ft_strdup("Stringly");
	intmax_t	my_num;
	ft_printf("%.0%\n");
	printf("%.0%\n");
	printf("%.0%\n");
	printf("%.3s\n", mystring);
}
