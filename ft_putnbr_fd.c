/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 23:58:41 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/05 21:52:30 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		sign = -1;
	}
	if (n > -10 && n < 10)
		ft_putchar_fd(n * sign + '0', fd);
	else
	{
		ft_putnbr_fd(n / 10 * sign, fd);
		ft_putchar_fd(n % 10 * sign + '0', fd);
	}
}
