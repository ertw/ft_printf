#include <stdio.h>
#include "../printf.h"
#include <limits.h>
#include <locale.h>

int		ft_wctomb(char *s, wchar_t wchar);
int		wstrbytelen(const wchar_t *ws);
int		wstrtombstr(char *dst, const wchar_t *ws);

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
//	wchar_t		*my_wstr = L"≥q";
	wchar_t		*my_wstr = NULL;
	char		*my_str = "Hello";
	wchar_t wz [3] = L"@@";

//	my_str = ft_strnew(9);
//	ft_putnbr(wctomb(my_str, my_wchar));
//	printf("%d\n", my_wchar);
//	o1 = ft_printf("%5C\n", my_wchar);
//	o2 = printf("%5C\n", my_wchar);
	o1 = ft_printf("{%d}\n", number);
	o1 = ft_printf("{%s}\n", my_str);
	o1 = ft_printf("{%S}\n", my_wstr);
	o1 = ft_printf("{%C}\n", my_wchar);
//	o2 = printf("{%d}\n", number);
//	my_str = ft_strnew(wstrbytelen(my_wstr));
//	wstrtombstr(my_str, my_wstr);
//	printf("%s\n", my_str);
//	o1 = ft_printf("%ls\n", wz);
//	o2 = printf("%ls\n", wz);
//	o2 = printf("%ls\n", L"❀ ≥ ☭ test text 	Æ 漢");
//	printf("%d\n", wstrbytelen(L"≥"));
//	ft_putnbr(write(1, &my_str, 2));
//	write(1, my_str, sizeof(my_str) / sizeof(my_wchar));
//	printf("ret1: %d\nret2: %d\n", o1, o2);
}
