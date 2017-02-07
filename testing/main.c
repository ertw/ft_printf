#include "../libft/libft.h"
#include <stdio.h>

int		main(void)
{
	const char	formatstring[] = "%.0d\n";
	int		number = 0;
	int		number2 = 42;
	char		char1 = 0;
	char		*mystring = "Stringly";
	printf(formatstring, number);
	ft_printf(formatstring, number);
//	ft_putnbr(printf(formatstring, number));
//	ft_putnbr(ft_printf(formatstring, number));
//	printf(" %-10d \n", number);
//	printf(" %010d \n", number);
//	printf(" %-#10x \n", number);  
//	printf(" %#x \n", number);
}
