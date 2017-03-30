#include "./printf.h"

int	ft_ucountplaces(uintmax_t n, const size_t base)
{
	int		places;

	if (n == 0)
		return (1);
	places = 0;
	while (n)
	{
		places++;
		n /= base;
	}
	return (places);
}

char	*ft_uitoabasec(uintmax_t n, size_t base, int precision, size_t capital)
{
	char	*sym;
	int	len;
	int	i;
	char	*ret;

	sym = "0123456789abcdef0123456789ABCDEF";
	sym += 16 * capital;
	len = ft_ucountplaces(n, base);
	i = 0;
	if (!(ret = ft_strnew(len + (precision == -1 ? 0 : precision))))
		return (NULL);
	while (n != 0 || (i == 0 && precision != 0) || i < precision)
	{
		ret[i++] = *(sym + (n % base));
		n /= base;
	}
	ft_strrev(ret, ft_strlen(ret));
	return (ret);
}
