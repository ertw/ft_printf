/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countplaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 14:47:27 by ewilliam          #+#    #+#             */
/*   Updated: 2017/01/18 12:42:40 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countplaces(int n, const size_t base)
{
	int		places;
	long	num;

	num = -1;
	if (n == 0)
		return (1);
	places = 0;
	num = base == 10 && n < 0
		? num * n
		: n;
	while (num)
	{
		places++;
		num /= base;
	}
	return (places);
}
