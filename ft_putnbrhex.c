/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 21:12:16 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/05 21:24:24 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrhex(int n, int len)
{
	char	*base;
	int		sign;

	base = "0123456789ABCDEF";
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		write(1, "-", 1);
	}
	while (len > 1)
	{
		ft_putnbrhex((n * sign) / 16, --len);
	}
	write(1, base + (n * sign) % 16, 1);
}
