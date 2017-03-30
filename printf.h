#ifndef	PRINTF_H
# define PRINTF_H
# include "./libft.h"
# include <stdarg.h>
#endif

typedef struct		s_print
{
	int				length;
	char			*buf;
	size_t			i;
	char			*out;
	va_list			ap;
	char			f_sign;
	unsigned short	f_left;
	unsigned short	f_alt;
	char			f_pad;
	unsigned short	base;
	unsigned short	capital;
	char			*l[7][3];
	int				width;
	int				precision;
	int				conversion;
	size_t			r;
}					t_print;

int					ft_strwjoin(t_print *p, const char *new, int len);
int					ft_strwfjoin(t_print *p, const char *new, int len);
int	match_any_char(char *str, char c);
void	dispatch_string(t_print *p);
void	dispatch_decimal(t_print *p);
void	dispatch_pointer(t_print *p);
void	dispatch_oct(t_print *p);
void	dispatch_char(t_print *p);
void	dispatch_unsigned(t_print *p);
int	is_flag(char c);
t_print	*fmt_str(t_print *p);
t_print	*fmt_wstr(t_print *p);
t_print	*fmt_hex(t_print *p, size_t capital);
t_print	*fmt_percent(t_print *p);
t_print	*fmt_char(t_print *p);
t_print	*fmt_wchar(t_print *p);
t_print	*fmt_uint(t_print *p);
t_print	*fmt_dec(t_print *p);
t_print	*fmt_ptr(t_print *p);
t_print	*fmt_oct(t_print *p);
void	justify_hex(t_print *p, char *digits, size_t capital);
void	justify_oct(t_print *p, char *digits);
char	*justify_string(t_print *p, char *str);
char	*justify_char(t_print *p, char c);
void	justify_uint(t_print *p, char *digits);
void	justify_dec(t_print *p, char *digits);
char	*ft_uitoabasec(uintmax_t n, size_t base, int precision, size_t capital);
uintmax_t	castify(intmax_t n, t_print *p);
t_print	*parse_conversion(t_print *p);
t_print	*parse_length(t_print *p);
t_print	*parse_precision(t_print *p);
t_print	*parse_width(t_print *p);
t_print	*parse_flags(t_print *p);
t_print	*parse_percent(t_print *p);
char	*cast_uint(t_print *p, unsigned short capital, unsigned short base);
