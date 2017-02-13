/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:13:00 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/06 18:03:55 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	char	*anum;
	long	lnum;

	len = ft_countplaces(n, 10);
	anum = malloc(sizeof(char) * (len + (n < 0) + 1));
	if (!anum)
		return (NULL);
	lnum = n;
	lnum *= n < 0 ? -1 : 1;
	ft_bzero(anum, len + (n < 0) + 1);
	if (n < 0)
		*anum++ = '-';
	if (lnum == 0)
		*anum++ = '0';
	while (lnum)
	{
		*anum++ = lnum % 10 + '0';
		lnum /= 10;
	}
	ft_strrev(anum - len, len);
	return (anum - len - (n < 0));
}
