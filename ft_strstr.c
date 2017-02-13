/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewilliam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 09:09:56 by ewilliam          #+#    #+#             */
/*   Updated: 2016/12/08 14:56:42 by ewilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_str_in_str(const char *s, const char *find)
{
	if (!*find)
		return (1);
	if (*s && *find)
	{
		if (*s == *find)
			return (is_str_in_str(++s, ++find));
	}
	return (0);
}

char		*ft_strstr(const char *big, const char *little)
{
	if (!*little)
		return ((char*)big);
	while (*big)
	{
		if (is_str_in_str(big, little))
			return ((char*)big);
		big++;
	}
	return (NULL);
}
