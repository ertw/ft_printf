/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:55:32 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/03 14:28:18 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (*s)
	{
		if (*s == (char)c)
			return ((char*)s);
		if (s[1] == '\0' && c == '\0')
			return ((char*)++s);
		if (*s != (char)c)
			return (ft_strchr(++s, c));
	}
	return (NULL);
}
