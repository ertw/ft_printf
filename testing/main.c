#include <stdio.h>
#include "../printf.h"
#include <limits.h>
#include <locale.h>

int		main(void)
{
	setlocale(LC_ALL, "");
	const char	formatstring[] = " %lu\n";
	char		number = -42;
	int		number2 = 0;
	char		char1 = 0;
	intmax_t	my_num;
	int		o1;
	int		o2;
//	wchar_t		my_wchar = L'q';
	wchar_t		my_wchar = L'Á';
	char		*my_str;

//	my_str = ft_strnew(9);
//	ft_putnbr(wctomb(my_str, my_wchar));
//	printf("%d\n", my_wchar);
//	o1 = ft_printf("%5C\n", my_wchar);
//	o2 = printf("%5C\n", my_wchar);
	o1 = ft_printf("{%3c}\n", 0);
	o2 = printf("{%3c}\n", 0);
//	o1 = ft_printf("%S\n", L"Á±≥");
//	o2 = printf("%S\n", L"Á±≥");
	printf("ret1: %d\nret2: %d\n", o1, o2);
//	ft_putnbr(write(1, &my_str, 2));
//	write(1, my_str, sizeof(my_str) / sizeof(my_wchar));
}
