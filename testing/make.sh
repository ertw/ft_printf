# gcc -g -Wno-format ../ft_printf.c main.c -L. ../libftprintf.a ; ./a.out | cat -e
# gcc -g -fsanitize=address -Wno-format ../ft_printf.c main.c alloc_wrap.c -L. ../libftprintf.a ; ./a.out
gcc ../ft_printf.c main.c alloc_wrap.c -L. ../libftprintf.a ; ./a.out
