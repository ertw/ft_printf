/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:46:38 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/09 11:52:39 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	unsigned char	ch;
	size_t			len;

	string = (unsigned char*)s;
	ch = c;
	len = 0;
	while (len < n)
	{
		if (string[len] == ch)
			return ((void*)(s + len));
		len++;
	}
	return (NULL);
}
