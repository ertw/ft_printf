/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:28:56 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/08 15:00:00 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	else
		return (0);
}

static int	char_to_int(char c)
{
	return (c - '0');
}

int			ft_atoi(const char *str)
{
	long	val;
	int		sign;

	val = 0;
	sign = 1;
	while (ft_isspace(*str))
		++str;
	if (is_sign(*str))
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (ft_isdigit(*str))
	{
		val *= 10;
		val += char_to_int(*str);
		++str;
	}
	return ((int)val * sign);
}
