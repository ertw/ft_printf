/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:19:12 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/08 13:59:13 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n)
	{
		*(unsigned char*)dst++ = *(unsigned char*)src++;
		if (*((unsigned char*)src - 1) == (unsigned char)c)
			return (dst);
		n--;
	}
	return (NULL);
}
