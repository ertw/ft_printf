/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 08:27:40 by ewilliam          #+#    #+#             */
/*   Updated: 2017/01/08 11:27:30 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putcharc(char c, int r, int g, int b)
{
	write(1, "\x1b[38;2;", 7);
	ft_putnbr(r);
	write(1, ";", 1);
	ft_putnbr(g);
	write(1, ";", 1);
	ft_putnbr(b);
	write(1, "m", 1);
	write(1, &c, 1);
	write(1, "\x1b[0m", 4);
}

void		ft_putstrc(const char *s, int r, int g, int b)
{
	while (s && *s)
	{
		ft_putcharc(*s++, r, g, b);
		write(1, "\x1b[0m", 4);
	}
}
