/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mempmove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 21:42:24 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/05 21:58:06 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/* Like memmove, but returns pointer to the end of dst (see stpcpy) */

void	*ft_mempmove(void *dst, const void *src, size_t len)
{
	if (dst > src)
	{
		while (len--)
		{
			((char*)dst)[len] = ((char*)src)[len];
		}
	}
	if (dst < src)
	{
		while (len--)
		{
			*(char*)dst = *(char*)src;
			dst++;
			src++;
		}
	}
	return (dst);
}
