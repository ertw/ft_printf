/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:00:52 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/05 21:45:44 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n)
	{
		if (*(char*)s1 == *(char*)s2)
			return (ft_memcmp(++s1, ++s2, --n));
		if (*(char*)s1 != *(char*)s2)
			return ((*(unsigned char*)s1 - *(unsigned char*)s2));
	}
	return (0);
}
