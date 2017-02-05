#include "../libft/libft.h"
#include <stdio.h>

int		main(void)
{
	const char	formatstring[] = "d1: %- 10.5d d2: %10.6d\n";
	int		number = 1000;
	char		char1 = 'q';
	char		mystring[] = "Hellooooo";
	printf(formatstring, number, number);
	ft_printf(formatstring, number, number);
//	printf(" %-10d \n", number);
//	printf(" %010d \n", number);
//	printf(" %-#10x \n", number);  
//	printf(" %#x \n", number);
}
