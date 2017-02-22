#include <stdio.h>
#include "../printf.h"
#include <limits.h>

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
	intmax_t	my_num;
	int		o1;
	int		o2;
	o1 = ft_printf("%ls", L"Á±≥\n");
	o2 = printf("%ls", L"Á±≥\n");
	printf("ret1: %d\nret2: %d\n", o1, o2);
}
