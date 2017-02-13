/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 21:47:19 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/08 14:55:59 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_str_in_strn(const char *s, const char *find, size_t len)
{
	if (!*find)
		return (1);
	if (*s && *find && len)
	{
		if (*s == *find)
			return (is_str_in_strn(++s, ++find, --len));
	}
	return (0);
}

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (!*little)
		return ((char*)big);
	while (*big && len)
	{
		if (is_str_in_strn(big, little, len))
			return ((char*)big);
		big++;
		len--;
	}
	return (NULL);
}
