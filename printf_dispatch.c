#include "./printf.h"

void	dispatch_string(t_print *p)
{
	if ((p->buf[p->i] == 'S' && MB_CUR_MAX > 1) || (p->buf[p->i] = 's' && p->length == 3))
		fmt_wstr(p);
	else
		fmt_str(p);
}

void	dispatch_decimal(t_print *p)
{
	p->length = (p->buf[p->i] == 'D' ? 3 : p->length);
	fmt_dec(p);
}

void	dispatch_pointer(t_print *p)
{
	p->length = 3;
	fmt_ptr(p);
}

void	dispatch_oct(t_print *p)
{
	p->length = (p->buf[p->i] == 'O' ? 3 : p->length);
	fmt_oct(p);
}

void	dispatch_char(t_print *p)
{
	if (p->buf[p->i] == 'C' && MB_CUR_MAX > 1)
		fmt_wchar(p);
	else
		fmt_char(p);
}

void	dispatch_unsigned(t_print *p)
{
	p->length = (p->buf[p->i] == 'U' ? 3 : p->length);
	fmt_uint(p);
}
