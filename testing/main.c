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
//	o1 = ft_printf("%hhd\n", -129);
//	o2 = printf("%hhd\n", -129);
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
	ft_printf("%s %s\n", "Hello!", "word");
	ft_printf("%d\n", 123);
	ft_printf("%c\n", 123);
	ft_printf("Test 1|%x|\n", 0);
    printf("Test 1|%x|\n\n", 0);

    ft_printf("Test 2|%X|\n", 0);
    printf("Test 2|%X|\n\n", 0);

    ft_printf("Test 3|%x|\n", -42);
    printf("Test 3|%x|\n\n", -42);

    ft_printf("Test 4|%X|\n", -42);
    printf("Test 4|%X|\n\n", -42);

    ft_printf("Test 5|%x|\n", 4294967296);
    printf("Test 5|%x|\n\n", 4294967296);

    ft_printf("Test 6|%X|\n", 4294967296);
    printf("Test 6|%X|\n\n", 4294967296);

    char *test = "testingtesting123";
    ft_printf("Test 7|%x|\n", test);
    printf("Test 7|%x|\n\n", test);

    ft_printf("Test 8|%10x|\n", 42);
    printf("Test 8|%10x|\n\n", 42);

    ft_printf("Test 9|%-10x|\n", 42);
    printf("Test 9|%-10x|\n\n", 42);

    ft_printf("Test 10|%jx|\n", 4294967296);
    printf("Test 10|%jx|\n\n", 4294967296);

    ft_printf("Test 11|%jx|\n", -4294967296);
    printf("Test 11|%jx|\n\n", -4294967296);

    ft_printf("Test 12|%jx|\n", -4294967297);
    printf("Test 12|%jx|\n\n", -4294967297);

    ft_printf("Test 13|%#x|\n", 0);
    printf("Test 13|%#x|\n\n", 0);

    ft_printf("Test 14|%#8x|\n", 42);
    printf("Test 14|%#8x|\n\n", 42);

    ft_printf("Test 15|%#08x|\n", 42);
    printf("Test 15|%#08x|\n\n", 42);

    ft_printf("Test 16|%#-08x|\n", 42);
    printf("Test 16|%#-08x|\n\n", 42);

    ft_printf("Test 17|@moulitest: %#.x %#.0x|\n", 0, 0);
    printf("Test 17|@moulitest: %#.x %#.0x|\n\n", 0, 0);

    ft_printf("Test 18|@moulitest: %.x %.0x|\n", 0, 0);
    printf("Test 18|@moulitest: %.x %.0x|\n\n", 0, 0);

    ft_printf("Test 19|@moulitest: %5.x %5.0x|\n", 0, 0);
    printf("Test 19|@moulitest: %5.x %5.0x|\n\n", 0, 0);
}
